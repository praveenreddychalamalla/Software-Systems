/* @author Praveen Reddy 
 * @date : 2021-10-13
 * @desc Signals - SIGALARM , alarm sys call
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void sig_handler(int sig){ // Use trap -l in cmd line to know signal numbers and corresponding signal
	printf("signal caught\n");
	printf("signal SIGALRM , number : %d\n",sig);
	exit(0);
}

int main(){

	signal(SIGALRM, sig_handler); 
	alarm(1); //Triggers SIGALRM signal after 1 sec
	pause(); //suspends program execution until a signal arrives whose action is either to execute a handler function, or to terminate the process.
	//If the signal causes a handler function to be executed, then pause returns	
	return 0;
}