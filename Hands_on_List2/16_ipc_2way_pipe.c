/* @author Praveen Reddy 
 * @date : 2021-10-01
 * @desc IPC between parent process and child process using unnamed pipe. 2 way Communiation
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#define buffer_size 1024

int main(){
	
	int pipefd1[2],pipefd2[2]; //For two way communication we require 2 pipes. Pipes allow only unidirectional flow of data (Half Duplex)
	char buf1[buffer_size],buf2[buffer_size];

	int retval1=pipe(pipefd1);
	int retval2=pipe(pipefd2);

	if(retval1==-1 || retval2==-1){ //pipe sys call -1 on failure, 0 on success
		perror("pipe");
		exit(EXIT_FAILURE);
	}

	if(!fork()){ //Child Process
		close(pipefd1[1]); //Close the write end of pipe1. Child can only read from pipe1 (Parent is expected to write into pipe1)
		close(pipefd2[0]); //Close the read end of pipe2. Child can only write into pipe2  (Parent is expected to read from pipe2)

		read(pipefd1[0],buf1,buffer_size); //child process is blocked unless parent(some process) writes into pipe
		printf("Message received from parent: %s\n",buf1);

		printf("Enter message to be sent to parent from child: ");
		scanf("%[^\n]",buf2);
		write(pipefd2[1],buf2,buffer_size);

		

		exit(EXIT_SUCCESS);
	}
	else{//Parent Process
		close(pipefd1[0]); //Close the read end of pipe1. Parent can only write into pipe1
		close(pipefd2[1]); //Close the write end of pipe2. Parent can only read from pipe2

		printf("Enter message to be sent to child from parent: ");
		scanf("%[^\n]",buf1);
		write(pipefd1[1],buf1,buffer_size); //Writing into pipe1

		read(pipefd2[0],buf2,buffer_size); //Reading from pipe2. Gets blocked unless parent (some process) writes into pipe2.
		printf("Message received from child: %s\n",buf2);

		exit(EXIT_SUCCESS);
	}
	return 0;
}
