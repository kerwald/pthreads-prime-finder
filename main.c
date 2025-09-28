#include <pthread.h>
#include <stdlib.h>
#include<stdio.h>

void *VerificaPrimo( void *argumento );

typedef struct {
    int* arg;
    int inicial;
    int final;
} Info;

int main(){

    int nPrimos = 0;
    int numThreads = 0;
    int quantidadePorThreads = 0;

    
    scanf( "%d", &nPrimos );
    scanf( "%d", &numThreads );


    int arg[nPrimos];

    quantidadePorThreads = nPrimos / numThreads;
    if( ( nPrimos % numThreads ) != 0 ){
        numThreads += 1;
    }

    int j = quantidadePorThreads;
    Info info[numThreads];

    for( int i=0; i<numThreads; i++ ){
        j = j*i; // indice inicial
        info[i].inicial = j;
        info[i].final = j + quantidadePorThreads - 1;
        info[i].arg = arg;

        pthread_t thread_id;
        pthread_create (&thread_id, NULL, VerificaPrimo, (void*)&info[i] );
    }
    pthread_exit(NULL);


}

void *VerificaPrimo( void *argumento ){



}
 
