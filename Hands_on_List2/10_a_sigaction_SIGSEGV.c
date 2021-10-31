/* @author Praveen Reddy 
 * @date : 2021-10-13
 * @desc sigaction system call - SIGSEGV
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void sig_handler(int sig){ // Use trap -l in cmd line to know signal numbers and corresponding signal
	printf("signal caught\n");
	printf("signal SIGSEGV , number : %d\n",sig);
	exit(0);
}

int main(){
	struct sigaction my_action;
	my_action.sa_handler=sig_handler;
	my_action.sa_flags=0;
	sigaction(SIGSEGV,&my_action, NULL); //Segementation fault
	int a[10];
	printf("%d",a[10000]); //Segfault
	return 0;
}