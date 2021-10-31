/* @author Praveen Reddy 
 * @date : 2021-10-13
 * @desc Creating Threads
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/syscall.h>
#include <sys/types.h>

void thread_handler(void* args){ //function to be executed when a thread is created 

    printf("Thread Running..\n");
    sleep(1);
}

int main(){

    pthread_t thread;

    for(int i=0;i<3;i++){
        int retval=pthread_create(&thread,NULL,(void*)thread_handler, NULL);

        if(retval==-1){
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
        //pthread_join(thread,NULL);
    }
    pthread_exit(NULL);
    
    return 0;
}