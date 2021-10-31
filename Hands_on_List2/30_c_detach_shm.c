/* @author Praveen Reddy 
 * @date : 2021-10-06
 * @desc Detaching Shared Memory 
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

    getchar(); //Now, check using ipcs -m whether the memory segment is attached to the process address space

    shmdt(data); //Detach the memory segment from process address space

    getchar(); //Now, check using ipcs -m whether the memory segment is detached from the process address space

    /*When the process exits, automatically detached*/
    return 0;
}
