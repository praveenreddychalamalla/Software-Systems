/* @author Praveen Reddy 
 * @date : 2021-10-06
 * @desc Writing to Shared Memory 
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
   
    char* data=(char *)shmat(shmid,(void*)0,0);  //shmat attaches the shared memory segment with shmid to this process address space and returns a void pointer like malloc.

/* void *shmat(int shmid, const void *shmaddr, int shmflg); 
 *
 * Third argument is the mode in which you want to operate on shared memory : 0(RDWR), SHM_RDONLY
 *
 * Second argument is the address where this memory segment has to be attached in the user space (Physical Memory)
 * As linux has virtual memory manager, we don't have to worry about the specific address where the memory segment has to be attached, 
 * hence we pass zero (void ptr) and virtual memory manager finds the free space in physical memory, attaches memory segment at correspoinding place, and returns a void pointer.
 * Now use the pointer to read/write operations similarly as you do in case of malloc.
 * */
    printf("Enter data for writing to the shared memory : ");
    scanf("%[^\n]",data);
    getchar();
    getchar(); //Check the size o

    return 0;
}
