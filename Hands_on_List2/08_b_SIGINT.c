/* @author Praveen Reddy 
 * @date : 2021-10-13
 * @desc Signals - SIGSINT
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void sig_handler(int sig){ // Use trap -l in cmd line to know signal numbers and corresponding signal
	printf("signal caught\n");
	printf("signal SIGINT , number : %d\n",sig);
	exit(0);
}

int main(){

	signal(SIGINT, sig_handler); //Interrupt
	while(1); //ctrl-c : terminal interrupt
	return 0;
}