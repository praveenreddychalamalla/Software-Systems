/* @author Praveen Reddy 
 * @date : 2021-10-13
 * @desc SIGPROF, ITIMER_PROF
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/time.h>
#include <signal.h>

void sig_handler(int sig){
    printf("signal caught\n");
    printf("signal SIGPROF , number : %d\n",sig);
    exit(0);
}
int main(){

    signal(SIGPROF,sig_handler);
    struct timeval val,interval;
    val.tv_sec=0;
    val.tv_usec=1;

    interval.tv_sec=0;
    interval.tv_usec=0;

    struct itimerval new={interval,val};

    int retval=setitimer(ITIMER_PROF, &new,NULL); //ITIMER_PROF - Counts down against total cpu time (user + system (i/o))

    if(retval==-1){
        perror("setitimer");
        exit(EXIT_FAILURE);
    }

    while(1) sleep(0.0000000001); //Sleep time is not accounted.

    return 0;
}