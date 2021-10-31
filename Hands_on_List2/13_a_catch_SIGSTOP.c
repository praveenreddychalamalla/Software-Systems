/* @author Praveen Reddy 
 * @date : 2021-10-13
 * @desc  Trying to catch SIGSTOP signal, but not possible to catch (SIGKILL & SIGSTOP)
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>


void sig_handler(int sig){ 
	printf("signal caught\n");
	printf("signal SIGSTOP , number : %d\n",sig);
	exit(0);
}
int main(){

	signal(SIGSTOP,sig_handler);
	printf("My pid: %d\n",getpid());
	printf("Press Enter to catch signal:");
	getchar();
	sleep(5); //Send SIGSTOP signal to this process from another program using this process pid
	printf("No signal found was caught for 10 seconds\n");
	
}
