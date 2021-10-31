/* @author Praveen Reddy 
 * @date : 2021-10-01
 * @desc Executing  ls -l | wc using pipe and dup2
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#define buffer_size 1024

int main(){
	
	int pipefd[2];
	pipe(pipefd);
	
	if(!fork()){
		close(pipefd[0]); //Close read end of pipe
		
		dup2(pipefd[1],1); //Closes the file descriptor 1 associated with stdout, the write end of pipe is associated with file descriptor 1 
	
		execl("/bin/ls","ls","-l",NULL); //In the new process image, stdout instead of going to monitor, goes to write end of pipe 
	}
	else{
		close(pipefd[1]); //Close write end of pipe
		
		dup2(pipefd[0],0); //Closes the file descriptor 0 associated with stdin and the read end of pipe is associated with file descriptor 0 

		execlp("wc","wc",NULL); //In the new process image, instead of reading input from stdin, reads from pipe
	}
	return 0;
}
