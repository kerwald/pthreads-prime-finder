#include <pthread.h>
#include <stdlib.h>
#include<stdio.h>

void *VerificaPrimo( void *argumento );

typedef struct {
    int* arg;
    int inicial;
    int final;
    int nPrimos;
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

    Info info[numThreads];
    pthread_t thread_id[numThreads];

    for( int i=0; i<numThreads; i++ ){
        if( i==0 ){
            info[i].inicial = 0;
        }else{
            info[i].inicial = quantidadePorThreads*i;
        }
        info[i].final = info[i].inicial + quantidadePorThreads - 1;
        info[i].arg = arg;
        info[i].nPrimos = nPrimos;

        pthread_create ( &thread_id[i], NULL, VerificaPrimo, (void*)&info[i] );
    }

    for( int i=0; i<numThreads; i++ ){
        pthread_join( thread_id[i], NULL );
    }

    for( int i=0; i< nPrimos; i++){
        if( arg[i] == 1 ){
            printf( " %d ", i );
        }
    }


}

void *VerificaPrimo( void *argumento ){

    Info info = *(Info*)argumento;
    int ctrl;

    if( info.final > info.nPrimos ){
        info.final = info.nPrimos - 1;
    }
    
    for( int i = info.inicial; i <= info.final; i++ ) {
        ctrl = -1;
        for( int j = 2; j<i; j++ ){
            if( i%j == 0 ){
                ctrl = 0;
            }
        }
        if( ctrl == 0 && ( i != 0 || i != 1 ) ){
            info.arg[i] = 0;
        } else{
            info.arg[i] = 1;
        }
    
    }

}
 
