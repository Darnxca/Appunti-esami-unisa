/*Inserire N come multiplo di 128*/
#include <assert.h>
#include <stdio.h>
#include<cuda.h>
#include <time.h>

void prodottoScalareCPU(float *a, float *b, float *v, int n);
__global__ void prodottoScalareGPU(float* a, float* b, float* c, int n);

int main(void){
    float *a_h, *b_h, *v_h, *v_h2; // host data
    float *a_d, *b_d, *v_d; // device data
    float somma_cpu=0;
    float somma_gpu=0;
    int N , nBytes, i,sharedDim ;
    dim3 gridDim, blockDim;


    printf("***\t prodotto scalare seconda strategia \t***\n");
    printf("Inserire numero di elementi array : \n");
    scanf("%d", &N);

    nBytes = N*sizeof(float);
    a_h = (float *)malloc(nBytes);
    b_h = (float *)malloc(nBytes);
    v_h = (float *)malloc(nBytes);
    v_h2 = (float *)malloc(nBytes);
    cudaMalloc((void **) &a_d, nBytes);
    cudaMalloc((void **) &b_d, nBytes);
    cudaMalloc((void **) &v_d, nBytes);
    // inizializzo i dati
    /*Inizializza la generazione random dei vettori utilizzando l'ora attuale del sistema*/
    srand((unsigned int) time(0));

    for (i=0; i<N; i++) {
        a_h[i] = rand()%5-2;
    	b_h[i] = rand()%5-2;;
    }

    cudaMemcpy(a_d, a_h, nBytes, cudaMemcpyHostToDevice);
    cudaMemcpy(b_d, b_h, nBytes, cudaMemcpyHostToDevice);


    //azzeriamo il contenuto del vettore v
    memset(v_h, 0, gridDim.x * sizeof(float));
    cudaMemset(v_d, 0, nBytes);

    //configurazione del kernel
    blockDim.x=128;
    gridDim.x=N/blockDim.x+((N%blockDim.x)==0?0:1);
    // dimensione dell' array condiviso fra i thread allocato dinamicamente
    sharedDim = blockDim.x*sizeof(float);

    cudaEvent_t start, stop;
    cudaEventCreate(&start);
    cudaEventCreate(&stop);

    cudaEventRecord(start);

    //invocazione del kernel
    prodottoScalareGPU<<<gridDim, blockDim, sharedDim>>>(a_d, b_d, v_d, N);

    cudaMemcpy(v_h, v_d, gridDim.x * sizeof(float), cudaMemcpyDeviceToHost);

    for(i=0;i<gridDim.x;i++){
    	somma_gpu=somma_gpu+v_h[i];
    }

    cudaEventRecord(stop);
    cudaEventSynchronize(stop); // assicura che tutti siano arrivati all'evento stop prima di registrare il tempo
    float elapsed;
    // tempo tra i due eventi in millisecondi
    cudaEventElapsedTime(&elapsed, start, stop);
    cudaEventDestroy(start);
    cudaEventDestroy(stop);
    printf("tempo GPU=%f\n", elapsed);

    //cudaMemcpy(v_h, v_d, nBytes, cudaMemcpyDeviceToHost);

     // calcolo su CPU
    cudaEventCreate(&start);
    cudaEventCreate(&stop);
    cudaEventRecord(start);
     // calcolo somma seriale
    prodottoScalareCPU(a_h, b_h, v_h2, N);

    for(i=0;i<N;i++){
    	somma_cpu=somma_cpu+v_h2[i];
    }

    cudaEventRecord(stop);
    cudaEventSynchronize(stop); // assicura che tutti siano arrivati all'evento stop prima di registrare il tempo
    cudaEventElapsedTime(&elapsed, start, stop);
    cudaEventDestroy(start);
    cudaEventDestroy(stop);
    printf("tempo CPU=%f\n", elapsed);


    assert( somma_cpu == somma_gpu);

    if (N<20){
        for(i=0;i<N;i++)
    	    printf("a_h[%d]=%6.2f ",i, a_h[i]);
    	printf("\n");
    	for(i=0;i<N;i++)
    		printf("b_h[%d]=%6.2f ",i, b_h[i]);
    	printf("\n");
    	for(i=0;i<N;i++)
    		printf("v_h[%d]=%6.2f ",i, v_h[i]);
    	printf("\n");
    }

    printf("Il prodotto scalare sulla gpu fra a e b = %f",somma_gpu);
    printf("\n");

    printf("Il prodotto scalare sulla cpu fra a e b = %f",somma_cpu);
    printf("\n");

    free(a_h); free(b_h); free(v_h); free(v_h2);
    cudaFree(a_d); cudaFree(b_d); cudaFree(v_d);
    return 0;
}

//Seriale
void prodottoScalareCPU(float *a, float *b, float *v, int n){
    int i;
    for(i=0;i<n;i++)
    	v[i]=a[i]*b[i];
}

//Parallelo
__global__ void prodottoScalareGPU(float* a, float * b, float* c, int n){
    int p, Dist,passi = 0;

    extern __shared__ float v[];
    int index=threadIdx.x + blockIdx.x*blockDim.x;
    int id = threadIdx.x;

    if(index < n)
        v[id] = a[index]*b[index];
    __syncthreads();

    // somma in parallelo
    p = blockDim.x;
    while(p!=1){/*shifta di un bit a destra*/
		p=p>>1; //divido
		passi++;
	}

	for(int i=0;i<passi;i++){
	    Dist = 1<<i; // moltiplico 2^i

	    if(id %(Dist * 2) == 0){
	        v[id] = v[id] + v[id + Dist];
	    }

	    __syncthreads();
	}

	if(id == 0) c[blockIdx.x] = v[0];
}
