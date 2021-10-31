/* @author Praveen Reddy 
 * @date : 2021-10-13
 * @desc  Sending SIGSTOP signal
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>


int main(){

	int pid;
	printf("Enter pid to send SIGSTOP signal: ");
	scanf("%d",&pid);
	int retval=kill(pid,SIGSTOP); //Kill can be used to send any signal not only SIGKILL
	if(retval==-1){
		perror("kill");
		exit(EXIT_FAILURE);
	}
	printf("SIGSTOP signal sent\n");
	return 0;
	
}
