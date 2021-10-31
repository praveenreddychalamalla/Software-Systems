/* @author Praveen Reddy 
 * @date : 2021-10-12
 * @desc Using semaphore to protect critical section - Counting Semaphore
 */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/types.h>


int main(){
    
    key_t key1,key2;
    int shmid,semid,fd,size=32;
    struct sembuf sops={0,-1,0|SEM_UNDO}; //Semaphore number = 0 (first semaphore, 0 indexed in semaphore set array)

    key1=ftok(".",'c'); //semaphore
    key2=ftok(".",'a'); //shared memory
    
    semid=semget(key1,1,0); //semaphore associated with given key must exist.
    shmid=shmget(key2,size,IPC_CREAT|0764);

    if(semid==-1 || shmid==-1){
        exit(EXIT_FAILURE);
    }

    int* data=(int*)shmat(shmid,(void *)0, 0);

    printf("Waiting to enter critical section...\n");

    semop(semid,&sops,1); //performs  operations  on selected semaphores (Selected through semaphore number in sembuf structure) in the set indicated by semid
    //Last argument specifies no.of sops (sops can be an array of sembuf structures)

    printf("Inside the critical Section...\n"); 
    //As counting semaphore is being used, no.of process allowed into critical section are more tahn one depending on value of counting semaphore

    (*data)++;  

    printf("Data: %d\n",*data);
    getchar();

    printf("Enter to Unlock");
    getchar();

    sops.sem_op=1; //Unlock
    semop(semid,&sops,1);
}
 
