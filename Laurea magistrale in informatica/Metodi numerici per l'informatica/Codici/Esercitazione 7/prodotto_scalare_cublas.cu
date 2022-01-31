#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <cuda_runtime.h>
#include <cublas_v2.h>

void prodottoScalareCPU(float *a, float *b, float *v, int n);

int main (void){
    cudaError_t cudaStat;
    cublasStatus_t stat;
    cublasHandle_t handle;
    float* h_a = 0;     // Host array a
    float* d_a;         // Device array a
    float* h_b = 0;     // Host array b
    float *d_b;         // Device array b
    float somma_gpu = 0;   // Risultato finale
    float* h_v;         // Risultato cpu
    float somma_cpu=0;
	int M,i;
	
    printf("***\t prodotto scalare con cublas \t***\n");
    printf("Inserire numero di elementi : \n");
    scanf("%d", &M);
    
    h_a = (float *)malloc (M * sizeof (*h_a));      // Alloco h_a e lo inizializzo
    if (!h_a) {
        printf ("host memory allocation failed");
        return EXIT_FAILURE;
    }
    
    
    h_b = (float *)malloc (M * sizeof (*h_b));  // Alloco h_b e lo inizializzo
    if (!h_b) {
        printf ("host memory allocation failed");
        return EXIT_FAILURE;
    }
    
    for (i=0; i<M; i++) {
        h_a[i] = rand()%5-2;
    	h_b[i] = rand()%5-2;
    }
    
    cudaStat = cudaMalloc ((void**)&d_a, M*sizeof(*h_a));       // Alloco d_a
    if (cudaStat != cudaSuccess) {
        printf ("device memory allocation failed");
        return EXIT_FAILURE;
    }
    
    cudaStat = cudaMalloc ((void**)&d_b, M*sizeof(*h_b));       // Alloco d_b
    if (cudaStat != cudaSuccess) {
        printf ("device memory allocation failed");
        return EXIT_FAILURE;
    }
    
    stat = cublasCreate(&handle);               // Creo l'handle per cublas
    if (stat != CUBLAS_STATUS_SUCCESS) {
        printf ("CUBLAS initialization failed\n");
        return EXIT_FAILURE;
    }
    
    stat = cublasSetVector(M,sizeof(float),h_a,1,d_a,1);    // Setto h_a su d_a
    if (stat != CUBLAS_STATUS_SUCCESS) {
        printf ("data download failed");
        cudaFree (d_a);
        cublasDestroy(handle);
        return EXIT_FAILURE;
    }
    
    stat = cublasSetVector(M,sizeof(float),h_b,1,d_b,1);    // Setto h_b su d_b
    if (stat != CUBLAS_STATUS_SUCCESS) {
        printf ("data download failed");
        cudaFree (d_b);
        cublasDestroy(handle);
        return EXIT_FAILURE;
    }
    
    // parte calcolo GPU
    cudaEvent_t start, stop;
    cudaEventCreate(&start);
    cudaEventCreate(&stop);
    
    cudaEventRecord(start);
    
    stat = cublasSdot(handle,M,d_a,1,d_b,1,&somma_gpu);        // Calcolo il prodotto
    
    cudaEventRecord(stop);
    cudaEventSynchronize(stop); // assicura che tutti siano arrivati all'evento stop prima di registrare il tempo
    float elapsed;
    // tempo tra i due eventi in millisecondi
    cudaEventElapsedTime(&elapsed, start, stop);
    cudaEventDestroy(start);
    cudaEventDestroy(stop);
    printf("tempo GPU=%f\n", elapsed);
    
    if (stat != CUBLAS_STATUS_SUCCESS) {
        printf ("data download failed cublasSdot");
        cudaFree (d_a);
        cudaFree (d_b);
        cublasDestroy(handle);
        return EXIT_FAILURE;
    }
    
    
    // calcolo su CPU
    h_v = (float *)malloc(M*sizeof(float));
    
    cudaEventCreate(&start);
    cudaEventCreate(&stop);
    cudaEventRecord(start);
     // calcolo somma seriale
    prodottoScalareCPU(h_a, h_b, h_v, M);
    
    for(i=0;i<M;i++){
    	somma_cpu=somma_cpu+h_v[i];         
    }
    
    cudaEventRecord(stop);
    cudaEventSynchronize(stop); // assicura che tutti siano arrivati all'evento stop prima di registrare il tempo
    cudaEventElapsedTime(&elapsed, start, stop);
    cudaEventDestroy(start);
    cudaEventDestroy(stop);
    printf("tempo CPU=%f\n", elapsed);
    
    
    assert(somma_cpu == somma_gpu);
    
    printf("Risultato del prodotto --> %f",somma_gpu);
    
    cudaFree (d_a);     // Dealloco d_a
    cudaFree (d_b);     // Dealloco d_b
    
    cublasDestroy(handle);  // Distruggo l'handle
    
    free(h_a);      // Dealloco h_a
    free(h_b);      // Dealloco h_b    
    free(h_v);      // Dealloco h_v  
    return EXIT_SUCCESS;
}

//Seriale
void prodottoScalareCPU(float *a, float *b, float *v, int n){
    int i;
    for(i=0;i<n;i++)
    	v[i]=a[i]*b[i];
}