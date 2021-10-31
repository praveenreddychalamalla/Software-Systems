/* @author Praveen Reddy 
 * @date : 2021-09-14
 * @desc Write Lock implementation in online ticket reservation simulation
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

struct DataBase{

    int ticket_no;
};

int main(){

    struct flock lock;
    struct DataBase db;
    int fd;

    fd=open("Records_17.txt",O_RDWR);

    if(fd==-1){
        perror("open");
        exit(EXIT_FAILURE);
    }

    /*Set the fields of flock structure */
   
    lock.l_type=F_WRLCK; //Shared lock - allows many readers but not a single writer
    lock.l_whence=SEEK_SET;
    lock.l_start=0; //Setting start and len fields to 0 locks entire file.
    lock.l_len=0;
    lock.l_pid=getpid();

    printf("Before entering into critical section\n");
    int flag=fcntl(fd,F_SETLKW,&lock); //Waits if lock is unavailable

    if(flag==-1){
        perror("fcntl");
        exit(EXIT_FAILURE);
    }

    read(fd,&db,sizeof(db));
    printf("Current ticket_no : %d\n",db.ticket_no);
    printf("In critical section\n");

    db.ticket_no++; //Increment ticket no.
    
    lseek(fd,0,SEEK_SET); //As you read from file, fp will be at the end, hence writing directly without setting file pointer will not update the existing ticket no
    write(fd,&db,sizeof(db)); //Write the changes into database
    
    printf("Enter to confirm ticket\n");
    getchar();
    lock.l_type=F_UNLCK; //Release lock

    printf("Unlocked\n");

    return 0;
}
