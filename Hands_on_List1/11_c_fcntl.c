/* @author Praveen Reddy 
 * @date : 2021-09-13
 * @desc duplicating file descriptor using fcntl system call
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(){

    int fd1,fd2;
    char msg[50],num[10];

    fd1=open("file",O_WRONLY); //fcntl fails if mode is mentioned as O_WRONLY | O_APPEND. Hence set file pointer using lseek

    if(fd1==-1){
        perror("open");
        exit(EXIT_FAILURE);
    }

    fd2=fcntl(fd1,F_DUPFD); //fd1, fd2 will point to same file and shares common file pointer in the file. Hence fd1,fd2 can be used interchangebly

    if(fd2==-1){
        perror("fcntl");
        exit(EXIT_FAILURE);
    }

    lseek(fd1,0,SEEK_END);

    sprintf(msg,"%s","Appended using old fd: ");
    sprintf(num,"%d",fd1);
    strcat(num,"\n");
    strcat(msg,num);

    write(fd1,msg,strlen(msg)); //Writing using old file descriptor

    sprintf(msg,"%s","Appended using duplicated fd: ");
    sprintf(num,"%d",fd2);
    strcat(num,"\n");
    strcat(msg,num);

    write(fd2,msg,strlen(msg)); //Writing using duplicated file descriptor

    close(fd1);
    close(fd2);

    return 0;

}