/* @author Praveen Reddy 
 * @date : 2021-10-06
 * @desc Reading from Shared Memory 
 */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(){
    key_t key;
    key=ftok(".",'a');
    int size=1024;
    int shmid=shmget(key,size,0); //Returns the shmid with given key. Shared memory segment with given key must exist, else create using appropriate flags
    
    if(shmid==-1){
        perror("shmget");
        exit(EXIT_FAILURE);
    }
    
    /*Attach the shared memory segment to this process address space*/
   
    char* data=(char *)shmat(shmid,(void*)0,SHM_RDONLY);  //shmat attaches the memory segment with shmid to this process address space and returns a void pointer like malloc.

    printf("Data from shared memory : %s",data);
    getchar(); 

    return 0;
}
