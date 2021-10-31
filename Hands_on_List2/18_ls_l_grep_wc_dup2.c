/* @author Praveen Reddy 
 * @date : 2021-10-01
 * @desc Executing  ls -l | grep ^d | wc using pipes and dup2
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	
	int pipefd1[2],pipefd2[2];
	pipe(pipefd1);
	pipe(pipefd2);
	
	if(!fork()){

		if(!fork()){
			/*Keep only write end of pipe2 open and close remaining*/
			close(pipefd1[0]);
			close(pipefd1[1]);
			close(pipefd2[0]);

			dup2(pipefd2[1],1); //file descriptor 1 is associated with write end of pipe2

			execl("/bin/ls","ls","-l",NULL); //In the new process image, output goes to write end of pipe2 instead of stdout 
		}
		else{
			/*Keep write end of pipe 1 open and read end of pipe 2 open. Close remaining*/
			close(pipefd1[0]); 
			close(pipefd2[1]);

			dup2(pipefd1[1],1); //file descriptor 1 is associated with write end of pipe1
			dup2(pipefd2[0],0); //file descriptor 0 is associated with read end of pipe2
		
			execlp("grep","grep","^d",NULL); //In the new process image, input comes from read end of pipe 2 instead of stdin and output goes to write end of pipe1 instead of stdout 
		}
		
	}
	else{
		/*Keep only read end of pipe1 open and close remaining*/
		close(pipefd1[1]); 
		close(pipefd2[0]);
		close(pipefd2[1]);

		dup2(pipefd1[0],0); //Closes the file descriptor 0 associated with stdin and the read end of pipe is associated with file descriptor 0 

		execlp("wc","wc",NULL); //In the new process image, instead of reading input from stdin, reads from pipe1
	}
	return 0;
}
