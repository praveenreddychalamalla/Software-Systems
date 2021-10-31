/* @author Praveen Reddy 
 * @date : 2021-10-06
 * @desc IPC - Two way communication using FIFO
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#define buffer_size 128

int main(){
	
	const char* file1="myfifo1";
	const char* file2="myfifo2";

	char buf[buffer_size];

	int pipefd1=open(file1,O_WRONLY); //Blocking call. Unless the read end of myfifo1 gets opened by some process, it's blocked.
	int pipefd2=open(file2,O_RDONLY); //Blocking call. Unless some process writes into myfifo2, it's blocked.
	if(pipefd1==-1 || pipefd2==-1){
		perror("open");
		exit(EXIT_FAILURE);
	}

	printf("Enter Message : ");
	scanf("%[^\n]",buf);

	write(pipefd1,buf,buffer_size);

	read(pipefd2,buf,buffer_size);
	printf("Message received : %s\n",buf);

	close(pipefd1);
	close(pipefd2);
	return 0;
}
