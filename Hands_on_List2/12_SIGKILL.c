/* @author Praveen Reddy 
 * @date : 2021-10-13
 * @desc  kill system call to send SIGKILL signal to the parent process from the child process
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>


int main(){

	if(!fork()){
		int parent_id=getppid(); //Parent Process id

		printf("Parent Process Id : %d\n",parent_id);

		int retval=kill(parent_id,SIGKILL);
		if(retval==-1){
			perror("kill");
			exit(EXIT_FAILURE);
		}
		sleep(3);
		parent_id=getppid();
		printf("Parent Process Id : %d\n",parent_id);//Process id of system_d or init process. Hence orphan process
	}
	else{
		sleep(10);
	}

	return 0;
}