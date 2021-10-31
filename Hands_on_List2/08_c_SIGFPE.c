/* @author Praveen Reddy 
 * @date : 2021-10-13
 * @desc Signals - SIGFPE
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void sig_handler(int sig){ // Use trap -l in cmd line to know signal numbers and corresponding signal
	printf("signal caught\n");
	printf("signal SIGFPE , number : %d\n",sig);
	exit(0);
}

int main(){

	signal(SIGFPE, sig_handler); //Floating Point Exception
	int a=5/0; //Floating point exception - Divide by zero error

	return 0;
}