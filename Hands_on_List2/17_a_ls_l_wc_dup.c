/* @author Praveen Reddy 
 * @date : 2021-10-01
 * @desc Executing  ls -l | wc using pipe and dup
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

		close(1);//Close stdout. file descriptor 1 is avaliable now. file descriptor 1 is no longer associated with stdout
		close(pipefd[0]); //Close read end of pipe
		
		dup(pipefd[1]); //As file descriptor 1 is available, dup will duplicate the write end of pipe using file descriptor 1 (Lowest Available).
		/*file descriptor 1 is now associated with write end of pipe*/
		execl("/bin/ls","ls","-l",NULL); //In the new process image, stdout instead of going to monitor, goes to write end of pipe 
	}
	else{
		close(0); //Close stdin. file descriptor value 0 is available now. file descriptor 0 is no longer assciated with stdin
		close(pipefd[1]); //Close write end of pipe
		
		dup(pipefd[0]); //File descriptor 0 is now associated with read end of pipe.

		execlp("wc","wc",NULL); //In the new process image, instead of reading input from stdin, reads from pipe
	}
	return 0;
}
