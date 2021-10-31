/* @author Praveen Reddy 
 * @date : 2021-10-06
 * @desc IPC - One way communication using FIFO
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#define buffer_size 128

int main(){
	
	const char* file="myfifo1";
	char buf[buffer_size];

	int pipefd=open(file,O_WRONLY); //Blocking call. Unless the read end of myfifo1 gets opened by some process, it's blocked.

	if(pipefd==-1){
		perror("open");
		exit(EXIT_FAILURE);
	}

	printf("Enter Message : ");
	scanf("%[^\n]",buf);

	write(pipefd,buf,buffer_size); //Write to pipe

	close(pipefd);
	return 0;
}
