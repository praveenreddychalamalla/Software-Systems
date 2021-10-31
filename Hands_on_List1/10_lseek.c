/* @author Praveen Reddy 
 * @date : 2021-09-13
 * @desc Demonstration of lseek system call 
 */

/* lseek system call returns offset/0/-1 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#define buffer_size 1024

int main(){

    char buf[buffer_size];
    int fd=open("file",O_RDWR|O_TRUNC); //Open file in Read Write mode

    if(fd==-1){
        perror("open");
        exit(EXIT_FAILURE);
    }

    printf("Enter 10 characters : ");
    scanf(" %[^\n]",buf);

    write(fd,buf,10);

    int offset=lseek(fd,10,SEEK_CUR); //Move file pointer 10 bytes bytes from current position.
    printf("Current file pointer is at offset : %d\n",offset);

    printf("Enter 10 characters : ");
    scanf(" %[^\n]",buf);

    write(fd,buf,10); 

    close(fd);
    return 0;

   

}