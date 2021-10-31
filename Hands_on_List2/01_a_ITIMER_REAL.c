/* @author Praveen Reddy 
 * @date : 2021-10-13
 * @desc SIGALRM, ITIMER_REAL
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

    signal(SIGALRM,sighandler);
    struct timeval val,interval;
    val.tv_sec=10;
    val.tv_usec=10;

    interval.tv_sec=2;
    interval.tv_usec=0;

    struct itimerval new={interval,val}; //After 10 seconds and 10 micro seconds , generate signal for every 2 secs 

    printf("Starting Timer \n");

    int retval=setitimer(ITIMER_REAL, &new,NULL); //ITIMER_REAL - Counts down against real time (wall clock)

    if(retval==-1){
        perror("setitimer");
        exit(EXIT_FAILURE);
    }

    while(1) sleep(2); //Sleep time is also accounted.

    return 0;
}