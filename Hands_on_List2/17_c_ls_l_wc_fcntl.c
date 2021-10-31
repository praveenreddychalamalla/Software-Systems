/* @author Praveen Reddy 
 * @date : 2021-10-01
 * @desc Executing  ls -l | wc using pipe and fcntl
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>
#define buffer_size 1024

int main(){
	
	int pipefd[2];
	pipe(pipefd);

	if(!fork()){

		close(pipefd[0]); //Close read end of pipe
		close(1); //Close the file descriptor 1 associated with stdout

		fcntl(pipefd[1],F_DUPFD); //Write end of pipe is associated with file descriptor 1 (Lowest availble =1) 
		execl("/bin/ls","ls","-l",NULL); //In the new process image, stdout instead of going to monitor, goes to write end of pipe 

	}
	else{

		close(pipefd[1]); //Close write end of pipe
		close(0); 
		/* Without closing file descriptor 0 associated with stdin, 
		 * If you try fcntl(pipefd[0],F_DUPFD,0) - This is not equivalent to dup2. 
		 * You might end up associating read end of pipe with any file descriptor k>=0. If it's 0 fine, else synchronisation fails.
		 */
		fcntl(pipefd[0],F_DUPFD); //read end of pipe is associated with file descriptor 0 
		
		execlp("wc","wc",NULL); //In the new process image, instead of reading input from stdin, reads from pipe
	}
	return 0;
}
