/* @author Praveen Reddy 
 * @date : 2021-10-12
 * @desc Using semaphore to protect critical section - Binary Semaphore (Mutual Exclusion)
 */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>

/* struct sembuf, contains the following members:
 *         unsigned short sem_num;  semaphore number - On which semaphore in semaphore set, you want to perform operation
 *         short          sem_op;   semaphore operation - Lock or Unlock
 *         short          sem_flg;  operation flags : 0 - Wait until lock is obtained, IPC_NOWAIT, SEM_UNDO - Release Lock if the process which holds the lock exit suddenly)
 */
struct DataBase{

    int ticket_no;
};
int main(){
    
    key_t key;
    int semid,fd;
    struct sembuf sops={0,-1,0|SEM_UNDO}; //Semaphore number = 0 (first semaphore, 0 indexed in semaphore set array)
    struct DataBase db;

    fd=open("Records_32_a.txt",O_RDWR);

    key=ftok(".",'b');
    
    semid=semget(key,1,0); //semaphore associated with given key must exist.
    //Specify the no.of semaphores in semaphore set through second arg  - Must be less than or equal to the number used, while creating semaphore 

    if(semid==-1){
        perror("semget");
        exit(EXIT_FAILURE);
    }

    printf("Waiting to enter critical section...\n");

    semop(semid,&sops,1); //performs  operations  on selected semaphores (Selected through semaphore number in sembuf structure) in the set indicated by semid
    //Last argument specifies no.of sops (sops can be an array of sembuf structures)

    printf("Inside the critical Section...\n");

    read(fd,&db,sizeof(db));
    printf("Current ticket_no : %d\n",db.ticket_no);

    db.ticket_no++;

    lseek(fd,0,SEEK_SET);
    write(fd,&db,sizeof(db));

    printf("Enter to Unlock");
    getchar();

    sops.sem_op=1;
    semop(semid,&sops,1);
}
