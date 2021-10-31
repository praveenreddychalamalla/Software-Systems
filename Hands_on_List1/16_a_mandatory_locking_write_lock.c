/* @author Praveen Reddy 
 * @date : 2021-09-14
 * @desc Mandatory Locking - Locking entire file - write lock
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(){

    struct flock lock;
    int fd;

    fd=open("test",O_RDWR);

    if(fd==-1){
        perror("open");
        exit(EXIT_FAILURE);
    }

    /*Set the fields of flock structure before passing it to fcntl system call for locking*/
    /*l_type should be compatible with open mode of file to which fd is pointing to i.e., you cannot open a file in O_RDONLY and apply F_WRLCK on it*/
    
    lock.l_type=F_WRLCK; //Exclusive lock. 
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

    printf("In critical section\n");
    printf("Enter to unlock\n");
    getchar();
    lock.l_type=F_UNLCK; //Release lock
    printf("Unlocked\n");

    close(fd);
    return 0;
}
