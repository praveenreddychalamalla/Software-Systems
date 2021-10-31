/* @author Praveen Reddy 
 * @date : 2021-10-13
 * @desc sigaction system call - SIGFPE
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void sig_handler(int sig){ 
	printf("signal caught\n");
	printf("signal SIGFPE , number : %d\n",sig);
	exit(0);
}

int main(){
	struct sigaction my_action;
	my_action.sa_handler=sig_handler;
	my_action.sa_flags=0;
	sigaction(SIGFPE,&my_action, NULL); //Floating Pointing Exception

	int a=5/0;
	
	return 0;
}