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

void sig_handler(int sig){
    printf("signal caught\n");
    printf("signal SIGALRM , number : %d\n",sig);
    exit(0);
}
int main(){

    signal(SIGALRM,sig_handler);
    struct timeval val,interval;
    val.tv_sec=1;
    val.tv_usec=0;

    interval.tv_sec=0;
    interval.tv_usec=0;

    struct itimerval new={interval,val}; 

    int retval=setitimer(ITIMER_REAL, &new,NULL); //ITIMER_REAL - Counts down against real time (wall clock)

    if(retval==-1){
        perror("setitimer");
        exit(EXIT_FAILURE);
    }

    while(1) sleep(2); //Sleep time is also accounted.

    return 0;
}