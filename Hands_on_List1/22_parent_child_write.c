/* @author Praveen Reddy 
 * @date : 2021-09-19
 * @desc write in a file by child and parent process
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

int main(){
    
    int fd=open("file",O_WRONLY|O_TRUNC);

    if(fd==-1){
        perror("open");
        exit(EXIT_FAILURE);
    }

    if(!fork()){
        const char* msg="Written by Child Process\n";
        write(fd,msg,strlen(msg));
    }
    else{
        const char* msg="Written by Parent Process\n";
        write(fd,msg,strlen(msg));
    }
    close(fd);
    return 0;
}