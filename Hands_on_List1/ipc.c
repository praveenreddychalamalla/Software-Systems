/* @author Praveen Reddy 
 * @date : 2021-10-09
 * @desc Inter Process Communication Demo
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#define buffer_size 10000

int main(){

	const char* src="test";
    const char* dest="myfifo";

	int fd1= open(src,O_RDONLY);
    int fd2= open(dest, O_WRONLY); //Will be blocked here itself unless the read end of myfifo is opened by some other process

    if(fd1==-1 || fd2==-1){
        perror("open");
        exit(EXIT_FAILURE);
    }

    char buf[buffer_size];

    int size=read(fd1,buf,buffer_size);

    write(fd2,buf,size); //size number of bytes will be written into myfifo pipe, if pipe's read end is opened. And the same will be received at read end

    close(fd1);
    close(fd2);

	return 0;
}
