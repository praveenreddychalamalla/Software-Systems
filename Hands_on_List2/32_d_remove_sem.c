/* @author Praveen Reddy 
 * @date : 2021-10-12
 * @desc Removing a semaphore
 */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main(){

    int semid,key,retval;
    key=ftok(".",'a');
    semid=semget(key,1,0);

    retval=semctl(semid,0,IPC_RMID); //Argument sem_num is ignored
    if(retval==-1){
        perror("semctl");
        exit(EXIT_FAILURE);
    }
    return 0;
}