/* @author Praveen Reddy 
 * @date : 2021-10-13
 * @desc SIGALRM, ITIMER_VIRTUAL
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/time.h>
#include <signal.h>

void sighandler(){
    printf("Timer Expired\n");
}
int main(){

    signal(SIGVTALRM,sighandler);
    struct timeval val,interval;
    val.tv_sec=10;
    val.tv_usec=10;

    interval.tv_sec=0;
    interval.tv_usec=1;

    struct itimerval new={interval,val}; //After 10 seconds and 10 micro seconds , generate signal for every 1 micro second 

    printf("Starting Timer \n");

    int retval=setitimer(ITIMER_VIRTUAL, &new,NULL); //ITIMER_VIRTUAL - Counts down against usermode cpu time only

    if(retval==-1){
        perror("setitimer");
        exit(EXIT_FAILURE);
    }

    while(1) sleep(0.0000001); //Sleep time is not accounted. During this time process is in sleep state (Process is not with CPU)

    return 0;
}