/* @author Praveen Reddy 
 * @date : 2021-09-03
 * @desc I/O using read and write system calls 
 */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#define buffer_size 1024

/* read system call returns no.of bytes read successfully. Sometimes it may happen that specified number of bytes might not be there to read. 
 * write system call returns no.of bytes written successfully. 
 * read system call returns 0 when EOF is read
 * Both return -1 incase of failure
 */
int main(){
    
	int fd1=0; //file descriptor of stdin
    int fd2=1; //file descriptor of stdout
    
    char buf[buffer_size];
    int cnt=100; 

    int size=read(fd1,buf,cnt); //reads cnt no.of bytes from file assciated with fd1 and stores into buf. cnt<=buff else buffer overflow occurs. 
    
    write(fd2,buf,size); //writes size no.of bytes to file associated with fd2 . 

    close(fd1);
    close(fd2);
    

    return 0;
}
