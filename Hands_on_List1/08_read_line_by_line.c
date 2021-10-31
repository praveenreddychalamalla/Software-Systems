/* @author Praveen Reddy 
 * @date : 2021-09-03
 * @desc Reading line by line from a file using system calls
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#define buffer_size 1024

int main(){

    const char* path ="/home/praveen/IIITB/Term 1/Software Systems/Lab Exercises/Hands_on_List1/test";

    int fd1=open(path,O_RDONLY);
    int fd2=1; //stdout

    if(fd1==-1){
        perror("open");
        exit(EXIT_FAILURE);
    }
    
    char buf[buffer_size];
    int i=0, line_count=0;

    while(read(fd1,&buf[i],1)==1){ //Reads 1 byte from the file associated with fd1 into location buf[i].
        if(buf[i]=='\n'){
            line_count++;
            write(fd2,buf,i+1);
            i=0;
        }
        else if(i==buffer_size-1){
            write(fd2,buf,buffer_size);
            i=0;
        }
        else i++;
    }
    write(fd2,buf,i);
    close(fd1);
    close(fd2);

    return 0;
}


