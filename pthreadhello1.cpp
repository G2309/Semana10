#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define NTHREADS 100

//SUBRUTINA
void *say_hello(void *threadNumber){
    long tID;
    //cast de parametro void* a long
    tID = (long)threadNumber;
    printf("Hello from thread num %ld\n", tID);
}


//MAIN
int main(){
    int rc;  // Guardar el valor retorno del crete & join
    long i;    

    pthread_t tid[NTHREADS];
    pthread_attr_t attr;    
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    for(int i=0;i<NTHREADS;i++){
        rc = pthread_create(&tid[i], &attr, say_hello, (void *)i);
        if(rc){
            printf("ERROR: return code from pthread_create() is %d\n",rc);
            exit(-1);
        }
    }

      for(int i=0;i<NTHREADS;i++){
        rc = pthread_create(tid[i], NULL);
        if(rc){
            printf("ERROR: return code from pthread_create() is %d\n",rc);
            exit(-1);
        }
    } 

      pthread_attr_destroy(&attr);

}

