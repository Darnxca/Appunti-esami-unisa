#include <assert.h>
#include <stdio.h>
#include<cuda.h>
#include <time.h>

void sommaCPU(double *A, double *B, double *C, int n);
__global__ void sommaGPU(double *A, double *B, double *C, int n);

int main(void)
{
 double *A_h, *B_h,*C_h,*C2_h; // host data
 double *A_d, *B_d,*C_d; // device data
 int N, nBytes;
dim3 gridDim, blockDim;


printf("***\t  somma di due matrici \t***\n");
printf("Inserire il numero di righe e colonne : \n");
scanf("%d", &N);

 nBytes = N*N*sizeof(double);
 A_h = (double *)malloc(nBytes);
 B_h = (double *)malloc(nBytes);
 C_h = (double *)malloc(nBytes);
 C2_h = (double *)malloc(nBytes);
 cudaMalloc((void **) &A_d, nBytes);
 cudaMalloc((void **) &B_d, nBytes);
 cudaMalloc((void **) &C_d, nBytes);
 // inizializzo i dati
 /*Inizializza la generazione random dei vettori utilizzando l'ora attuale del sistema*/
srand((unsigned int) time(0));


    if(N<=100) printf("A = ");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (j == 0) {
                    A_h[i * N + j] = 1.0 / (i + 1) - 1;

                } else {
                    A_h[i * N + j] = 1.0 / (i + 1) - pow(1.0 / 2.0, j);

                }

                if(N<=100)
                printf("   %f  ", A_h[i*N+j] );

            }
            if(N<=100)
            printf("\n\n   ");
        }
        if(N<=100)
        printf("\n\n");

        if(N<=100) printf("B = ");
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (j == 0) {
                        B_h[i * N + j] = 2.0 / (i + 1) - 1;

                    } else {
                        B_h[i * N + j] = 2.0 / (i + 1) - pow(1.0 / 2.0, j);

                    }

                    if(N<=100)
                    printf("   %f  ", B_h[i*N+j] );

                }
                if(N<=100)
                printf("\n\n   ");
            }
            if(N<=100)
            printf("\n\n");




 cudaMemcpy(A_d, A_h, nBytes, cudaMemcpyHostToDevice);
 cudaMemcpy(B_d, B_h, nBytes, cudaMemcpyHostToDevice);


 //azzeriamo il contenuto del vettore c
memset(C_h, 0, nBytes);
cudaMemset(C_d, 0, nBytes);

//configurazione del kernel
blockDim.x=32;
blockDim.y=32;
gridDim.x=N/blockDim.x+((N%blockDim.x)==0?0:1);
gridDim.y=N/blockDim.y+((N%blockDim.y)==0?0:1);


cudaEvent_t start, stop;
cudaEventCreate(&start);
cudaEventCreate(&stop);

cudaEventRecord(start);

//invocazione del kernel
sommaGPU<<<gridDim, blockDim>>>(A_d, B_d, C_d, N);
cudaEventRecord(stop);
cudaEventSynchronize(stop); // assicura che tutti siano arrivati all'evento stop prima di registrare il tempo
float elapsed;
// tempo tra i due eventi in millisecondi
cudaEventElapsedTime(&elapsed, start, stop);
cudaEventDestroy(start);
cudaEventDestroy(stop);
printf("tempo GPU=%f\n", elapsed);

 cudaMemcpy(C_h, C_d, nBytes, cudaMemcpyDeviceToHost);

 // calcolo su CPU
cudaEventCreate(&start);
cudaEventCreate(&stop);
cudaEventRecord(start);
 // calcolo somma seriale
sommaCPU(A_h, B_h, C2_h, N);

cudaEventRecord(stop);
cudaEventSynchronize(stop); // assicura che tutti siano arrivati all'evento stop prima di registrare il tempo
cudaEventElapsedTime(&elapsed, start, stop);
cudaEventDestroy(start);
cudaEventDestroy(stop);
printf("tempo CPU=%f\n", elapsed);




 for (int i=0; i< N*N; i++) assert( C_h[i] == C2_h[i] );


 if(N<=100) printf("C_h= ");
     for (int i = 0; i < N; i++) {
         for (int j = 0; j < N; j++) {
             if(N<=100)
             printf("   %f  ", C_h[i*N+j] );
         }
         if(N<=100)
         printf("\n\n   ");
     }
     if(N<=100)
     printf("\n\n");


 free(A_h); free(B_h); free(C_h); free(C2_h);
 cudaFree(A_d); cudaFree(B_d); cudaFree(C_d);
 return 0;
}

//Seriale
void sommaCPU(double *A, double *B, double *C, int n)
{
int i;
for(i=0;i<n*n;i++)
	C[i]=A[i]+B[i];
}

//Parallelo
__global__ void sommaGPU
(double *A, double *B, double *C, int n)
{
int i=threadIdx.x + blockIdx.x*blockDim.x;
int j= blockIdx.y* blockDim.y+ threadIdx.y;
int index= j*gridDim.x* blockDim.x+i;
if(index < n*n)
	C[index] = A[index]+B[index];
}
