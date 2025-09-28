#include <pthread.h>
#include <stdlib.h>
#include<stdio.h>
#include <stdbool.h>

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

    Info info[numThreads];
    pthread_t thread_id[numThreads];

    for( int i=0; i<numThreads; i++ ){
        if( i==0 ){
            info[i].inicial = 0;
        }else{
            info[i].inicial = quantidadePorThreads*i;
        }
        if( i != numThreads -1 ){
            info[i].final = info[i].inicial + quantidadePorThreads - 1;
        } else{
            info[i].final = nPrimos - 1;
        }
        info[i].arg = arg;
        

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
    
    for( int i = info.inicial; i <= info.final; i++ ) {
        ctrl = -1;
        for( int j = 2; j<i; j++ ){
            if( i%j == 0 ){
                ctrl = 0;
                break;
            }
        }
        if( ctrl == 0 ||  i == 0 || i == 1  ){
            info.arg[i] = 0;
        } else{
            info.arg[i] = 1;
        }
    
    }

    return NULL;

}
 
