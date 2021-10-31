/* @author Praveen Reddy 
 * @date : 2021-10-06
 * @desc Creating Shared Memory 
 */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(){
    
    key_t key;
    int size=1024;
    key=ftok(".",'a');

    int shmid=shmget(key,size,IPC_CREAT|IPC_EXCL|0764); //Creates a shared memory segment of size bytes. 
    /*If already shared memory segment exists with given key, as EXCL flag is mentioned, shmget fails and returns -1*/

    if(shmid==-1){
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    printf("Shared Memory Created successfully - shmid : %d\n",shmid);
    /*Attach the created memory segment onto any process address space using shmat and perform the required operations*/
    return 0;
}
