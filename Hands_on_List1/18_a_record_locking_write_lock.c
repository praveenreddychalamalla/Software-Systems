/* @author Praveen Reddy 
 * @date : 2021-09-14
 * @desc Record Locking - write lock
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

struct DataBase{

    int train_no;
    int ticket_count;
};

int main(){

    struct flock lock;
    struct DataBase db;
    int fd;

    fd=open("Records_18.txt",O_RDWR);

    if(fd==-1){
        perror("open");
        exit(EXIT_FAILURE);
    }

    int input;
    printf("Enter Train Number : ");
    scanf("%d",&input);

    /*Set the fields of flock structure - Lock specific record only */
   
    lock.l_type=F_WRLCK; //Exclusive lock. 
    lock.l_whence=SEEK_SET;
    lock.l_start=(input-1)*sizeof(db); //Start from (input-1)th record from whence
    lock.l_len=sizeof(db); //Lock 1 record
    lock.l_pid=getpid();

    printf("Before entering into critical section\n");
    int flag=fcntl(fd,F_SETLKW,&lock); //Waits if lock is unavailable

    if(flag==-1){
        perror("fcntl");
        exit(EXIT_FAILURE);
    }

    lseek(fd,(input-1)*sizeof(db),SEEK_SET); //move file pointer to the desired record
    read(fd,&db,sizeof(db));
    printf("Current ticket_no : %d\n",db.ticket_count);
    printf("In critical section\n");

    db.ticket_count++; //Increment ticket no.
    
    lseek(fd,(input-1)*sizeof(db),SEEK_SET);//Move the file pointer to update the changes in the locked record
    write(fd,&db,sizeof(db)); //Write the changes into database
    
    printf("Press Enter to confirm ticket booking\n");
    getchar();
    getchar();
    lock.l_type=F_UNLCK; //Release lock
    
    printf("Unlocked\n");

    close(fd);
    return 0;
}
