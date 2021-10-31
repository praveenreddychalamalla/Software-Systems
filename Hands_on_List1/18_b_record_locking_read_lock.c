/* @author Praveen Reddy 
 * @date : 2021-09-14
 * @desc Record Locking - read lock
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

    fd=open("Records_18.txt",O_RDONLY);

    if(fd==-1){
        perror("open");
        exit(EXIT_FAILURE);
    }

    int input;
    printf("Enter Train Number : ");
    scanf("%d",&input);

    /*Set the fields of flock structure - Lock specific record only */
   
    lock.l_type=F_RDLCK; //Shared lock - allows many readers but not a single writer
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
    printf("Ticket_no Available: %d\n",db.ticket_count);
    printf("In critical section\n");

    printf("Press Enter to unlock\n");
    getchar();//Previous usage of scanf("%d",&input) leaves the trailing newline (\n) in input buffer. This getchar() is written to eat up the \n in input
    getchar();//To take input from user 
    
/*If you want to get things done by only 1 getchar(), make scanf to eat up the newline character as well i.e., scanf("%d%*c",&input) */
/*scanf ignores any no.of newline characters before the input i.e, press enter any number no.of times when scanf seeks input, it will still expect input by skipping all \n */
    
    lock.l_type=F_UNLCK; //Release lock
    
    printf("Unlocked\n");

    close(fd);
    return 0;
}
