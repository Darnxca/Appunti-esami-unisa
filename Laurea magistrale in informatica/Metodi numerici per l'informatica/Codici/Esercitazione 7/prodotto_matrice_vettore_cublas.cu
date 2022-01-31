#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <cuda_runtime.h>
#include <cublas_v2.h>


// alfa = 1, beta e y = 0
void productMatrixVectorCPU(float *a, float *b, float *v, int N);
void generateMatrix(float *h_A, int  n);

int main (void){
    cudaError_t cudaStat;
    cublasStatus_t stat;
    cublasHandle_t handle;
    float* h_A = 0;       // Host matrice A
    float* d_A;           // Device matrice A
    float* h_b = 0;       // Host array b
    float* d_b;           // Device array b
    float* d_v;           // Device risultato prodotto v
    float* h_v2= 0;       // Risultato finale del prodotto matrice vettore portato da device a host
    float* h_v;           // Risultato cpu
    float alfa = 1, beta = 0;
	int N,i;

    printf("***\t prodotto matrice vettore con cublas \t***\n");
    printf("Inserire numero di righe e colonne : \n");
    scanf("%d", &N);


    h_A = (float *)malloc (N*N* sizeof (*h_A));      // Alloco h_A e lo inizializzo
    if (!h_A) {
        printf ("host memory allocation failed");
        return EXIT_FAILURE;
    }

    generateMatrix(h_A, N);

    h_b = (float *)malloc (N * sizeof (*h_b));  // Alloco h_b e lo inizializzo
    if (!h_b) {
        printf ("host memory allocation failed");
        return EXIT_FAILURE;
    }

    for (i=0; i<N; i++) h_b[i] = rand()%5-2;


    cudaStat = cudaMalloc ((void**)&d_A, N*N*sizeof(*h_A));       // Alloco d_A
    if (cudaStat != cudaSuccess) {
        printf ("device memory allocation failed");
        return EXIT_FAILURE;
    }

    cudaStat = cudaMalloc ((void**)&d_b, N*sizeof(*h_b));       // Alloco d_b
    if (cudaStat != cudaSuccess) {
        printf ("device memory allocation failed");
        return EXIT_FAILURE;
    }

    stat = cublasCreate(&handle);               // Creo l'handle per cublas
    if (stat != CUBLAS_STATUS_SUCCESS) {
        printf ("CUBLAS initialization failed\n");
        return EXIT_FAILURE;
    }

    stat = cublasSetMatrix(N,N,sizeof(float),h_A,N,d_A,N);    // Setto h_A su d_A
    if (stat != CUBLAS_STATUS_SUCCESS) {
        printf ("data download failed");
        cudaFree (d_A);
        cublasDestroy(handle);
        return EXIT_FAILURE;
    }

    stat = cublasSetVector(N,sizeof(float),h_b,1,d_b,1);    // Setto h_b su d_b
    if (stat != CUBLAS_STATUS_SUCCESS) {
        printf ("data download failed");
        cudaFree (d_b);
        cublasDestroy(handle);
        return EXIT_FAILURE;
    }

    h_v2 = (float *)malloc(N*sizeof(float));
    memset(h_v2, 0, N*sizeof(float));
    
    cudaStat = cudaMalloc ((void**)&d_v, N*sizeof(*h_v2));       // Alloco d_v
    if (cudaStat != cudaSuccess) {
        printf ("device memory allocation failed");
        return EXIT_FAILURE;
    }
    
    stat = cublasSetVector(N,sizeof(float),h_v2,1,d_v,1);    // Setto h_b su d_b
    if (stat != CUBLAS_STATUS_SUCCESS) {
        printf ("data download failed");
        cudaFree (d_v);
        cublasDestroy(handle);
        return EXIT_FAILURE;
    }

    // parte calcolo GPU
    cudaEvent_t start, stop;
    cudaEventCreate(&start);
    cudaEventCreate(&stop);

    cudaEventRecord(start);

    stat = cublasSgemv(handle,CUBLAS_OP_T,N,N,&alfa,d_A,N,d_b,1,&beta,d_v,1);

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
        cudaFree (d_A);
        cudaFree (d_b);
        cublasDestroy(handle);
        return EXIT_FAILURE;
    }


    // calcolo su CPU
    h_v = (float *)malloc(N*sizeof(float));
    memset(h_v, 0, N*sizeof(float));

    cudaEventCreate(&start);
    cudaEventCreate(&stop);
    cudaEventRecord(start);

     // calcolo somma seriale
    productMatrixVectorCPU(h_A, h_b, h_v, N);

    cudaEventRecord(stop);
    cudaEventSynchronize(stop); // assicura che tutti siano arrivati all'evento stop prima di registrare il tempo
    cudaEventElapsedTime(&elapsed, start, stop);
    cudaEventDestroy(start);
    cudaEventDestroy(stop);
    printf("tempo CPU=%f\n", elapsed);


    stat = cublasGetVector(N,sizeof(float),d_v,1,h_v2,1); 
    if (stat != CUBLAS_STATUS_SUCCESS) {
        printf ("data download failed cublasGetVector");
        cudaFree (d_A);
        cudaFree (d_b);
        cudaFree (d_v);
        cublasDestroy(handle);
        return EXIT_FAILURE;
    }
    
    cudaFree (d_A);     // Dealloco d_a
    cudaFree (d_b);     // Dealloco d_b
    cudaFree (d_v);     // Dealloco d_v

    cublasDestroy(handle);  // Distruggo l'handle

    free(h_A);      // Dealloco h_a
    free(h_b);      // Dealloco h_b
    free(h_v);      // Dealloco h_v
    free(h_v2);      // Dealloco h_v
    return EXIT_SUCCESS;
}

void generateMatrix(float *h_A, int N){
  if(N<=20) printf("A = ");
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (j == 0) h_A[i * N + j] = 1.0 / (i + 1) - 1;
        else h_A[i * N + j] = 1.0 / (i + 1) - pow(1.0 / 2.0, j);
        if(N<=20) printf("   %f  ", h_A[i*N+j] );
      }
      if(N<=20) printf("\n\n   ");
    }
    if(N<=20) printf("\n\n");
}

//Seriale
void productMatrixVectorCPU(float *a, float *b, float *v, int n){
    int i,j;
    for(i = 0; i < n; i++)
      for(j = 0; j < n; j++)
        v[i] += a[i * n + j] * b[j];
}
