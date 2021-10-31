/* @author Praveen Reddy 
 * @date : 2021-10-06
 * @desc Removing existing shared memory memory segment
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
    
    int retval=shmctl(shmid,IPC_RMID,NULL);
    if(retval==-1){
        perror("shmctl");
        exit(EXIT_FAILURE);
    }
    printf("resource deleted successfully\n");
    
    return 0;
}
