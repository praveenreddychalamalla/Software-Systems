/* @author Praveen Reddy 
 * @date : 2021-10-20
 * @desc Use the executable file of this code in execve system call.
 */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#define buffer_size 1024

int main(int argc, const char* argv[]){ 

    char buf[buffer_size];
    if(argc!=3){ //Expects source path of file and destination path of file as command line arguments
        printf("Enter ./a.out source destination\n");
        return 0;
    }
    int fd1=open(argv[1],O_RDONLY);
    int fd2=open(argv[2],O_WRONLY|O_TRUNC);

    if(fd1==-1 || fd2==-1){
        perror("open");
        exit(EXIT_FAILURE);
    }
    int size;
    while( (size=read(fd1,buf,buffer_size))==buffer_size ){
        write(1,buf,size);
    }
    write(fd2,buf,size);

    close(fd1);
    close(fd2);

    return 0;
}
