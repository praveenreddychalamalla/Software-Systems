/* @author Praveen Reddy 
 * @date : 2021-09-13
 * @desc duplicating file descriptor using dup2 system call
 */

/* Note : If the passed file descriptor value is already in use, then it is silently closed before reusing */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(){

    int fd1,fd2;
    char msg[50],num[10];

    fd1=open("file",O_WRONLY|O_APPEND);

    if(fd1==-1){
        perror("open");
        exit(EXIT_FAILURE);
    }

    fd2=dup2(fd1,15); //Same as dup, except that you specify the value of file descriptor that should be assigned

    if(fd2==-1){
        perror("dup2");
        exit(EXIT_FAILURE);
    }

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