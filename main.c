#include <pthread.h>
#include <stdlib.h>
#include<stdio.h>
#include <stdbool.h>

void *VerificaPrimo( void *argumento );

typedef struct {
    bool* arg;
    unsigned int inicial;
    unsigned int final;
} Info;

int main(){

    unsigned int nPrimos = 0;
    unsigned int numThreads = 0;
    unsigned int quantidadePorThreads = 0;

    
    scanf( "%u", &nPrimos ); // %u para unsigned int ( valores apenas positivos )
    scanf( "%u", &numThreads );


    bool arg[nPrimos];
    for( unsigned int i=0; i<nPrimos; i++ ){
        arg[i] = false;
    }

    quantidadePorThreads = nPrimos / numThreads;

    Info info[numThreads];
    pthread_t thread_id[numThreads];

    for( unsigned int i=0; i<numThreads; i++ ){ // sempre manter consistencias do tipo usado no for com os tipos das variáveis que for comparar dentro
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

    for( unsigned int i=0; i<numThreads; i++ ){
        pthread_join( thread_id[i], NULL );
    }

    for( unsigned int i=0; i< nPrimos; i++){
        if( arg[i] == true ){
            printf( " %u ", i );
        }
    }


}

void *VerificaPrimo( void *argumento ){

    Info info = *(Info*)argumento;
    bool ctrl;
    
    for( unsigned int i = info.inicial; i <= info.final; i++ ) {
        ctrl = true;
        for( unsigned int j = 2; j<i; j++ ){
            if( i%j == 0 ){
                ctrl = false;
                break;
            }
        }
        if( ctrl == false ||  i == 0 || i == 1  ){
            info.arg[i] = false;
        } else{
            info.arg[i] = true;
        }
    
    }

    return NULL;

}
 
