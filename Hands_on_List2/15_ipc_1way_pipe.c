/* @author Praveen Reddy 
 * @date : 2021-10-01
 * @desc IPC between parent process and child process using unnamed pipe. One way Communiation (Parent to child)
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#define buffer_size 1024

int main(){
	
	int pipefd[2];
	char buf[buffer_size];
	int retval=pipe(pipefd);

	if(retval==-1){ //pipe sys call -1 on failure, 0 on success
		perror("pipe");
		exit(EXIT_FAILURE);
	}

	if(!fork()){ //Child Process
		close(pipefd[1]); //Close the write end of pipe. child is expected to read from the pipe in this program
		read(pipefd[0],buf,buffer_size); //child process is blocked unless parent(some process) writes into pipe
		printf("Message received from parent: %s\n",buf);
		exit(EXIT_SUCCESS);
	}
	else{//Parent Process
		close(pipefd[0]); //Close the read end of pipe. Parent is expected to write into pipe in this program
		printf("Enter message to be sent to child from parent: ");
		scanf("%[^\n]",buf); //scanf automatically appends terminating null character('\0') finally after reading input.
		write(pipefd[1],buf,buffer_size); //Writing into pipe. 
		exit(EXIT_SUCCESS);
	}
	return 0;
}
