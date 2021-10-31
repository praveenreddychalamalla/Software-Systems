/* @author Praveen Reddy 
 * @date : 2021-10-01
 * @desc Creating pipe (Unnamed Pipe) using pipe system call.
 */

/*Unnamed pipes are used for IPC between related processes or within the same process.*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#define buffer_size 1024

int main(){
	
	int pipefd[2];
	int retval=pipe(pipefd); //pipefd[0] refers to read end of pipe, and pipefd[1] refers to write end of pipe

	if(retval==-1){ //pipe sys call returns -1 on failure, 0 on success
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	
	char buf[buffer_size];
	const char* msg="IIIT Bangalore\n";

	write(pipefd[1],msg,strlen(msg)); //write into the pipe using write end 
	
	int size=read(pipefd[0],buf,buffer_size); //read from pipe using read end

	write(1,buf,size); //Write to std out.

	close(pipefd[0]);
	close(pipefd[1]);
	return 0;
}
