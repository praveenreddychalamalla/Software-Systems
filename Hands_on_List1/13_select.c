/* @author Praveen Reddy 
 * @date : 2021-09-13
 * @desc Monitoring file descriptors using select system call
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#define buffer_size 512
int main(){

    fd_set rfds;
    struct timeval tv;
    int fd=0 ; //stdin. To monitor stdin for any i/p availability

    FD_ZERO(&rfds) ; //Clear rfds fd_set
    FD_SET(fd,&rfds) ; //Add fd to rfds fd_set

    /* Set timeout interval - select() should block waiting for a file descriptor to become ready */
    /* select call will block until the file descriptors passed becomes ready, or the call interrupted by signal handler or, timeout expires */
    tv.tv_sec=10 ;
    tv.tv_usec=0;

    
    /* returns the number of file descriptors contained in the three returned descriptor sets, some of them will expire (May be all also)*/
    int retval=select(1,&rfds,NULL,NULL,&tv); //nfds should be 1+ max fd value among all file descriptor values in 3 independent fd_sets.

    if(retval==-1){
        perror("select");
        exit(EXIT_FAILURE);
    }

    if(retval==0){
        printf("No input is available in stdin within 10 seconds\n");
    }
    else {
        char buf[buffer_size];
        read(0,buf,buffer_size);
        printf("Input is available within 10 seconds\n");    
    }
    close(fd);
    return 0;

}