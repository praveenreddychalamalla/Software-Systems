/* @author Praveen Reddy 
 * @date : 2021-10-06
 * @desc Creating a Counting semaphore 
 */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/sem.h>

union semun { //get from man page - man semctl
   int              val;    /* Value for SETVAL */
   struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
   unsigned short  *array;  /* Array for GETALL, SETALL */
   struct seminfo  *__buf;  /* Buffer for IPC_INFO
                               (Linux-specific) */
};
int main(){
    
    key_t key;
    int semid;
    union semun arg; 
    key=ftok(".",'c');
    
    semid=semget(key,1,IPC_CREAT|0644); //Specify the no.of semaphores you want in semaphore set through second arg. 
    if(semid==-1){
      perror("semget");
      exit(EXIT_FAILURE);
    }

    arg.val=3; //for for counting semaphore
    int semnum=0; //first semaphore in semaphore set - 0
    
    int retval = semctl(semid,semnum,SETVAL,arg);

    if(retval==-1){
      perror("semget");
      exit(EXIT_FAILURE);
    }
    printf("Counting semaphore created successfully\n");
    
}
