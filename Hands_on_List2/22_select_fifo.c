/* @author Praveen Reddy 
 * @date : 2021-10-06
 * @desc select system call with fifo
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/time.h>
#define buffer_size 128

int main(){

	fd_set rfds;
	struct timeval tv;
	int pipefd,retval;
	char buf[buffer_size];
	const char* file="myfifo1";

	pipefd=open(file,O_RDONLY);  //Blocking call
	if(pipefd==-1){
		perror("open");
		exit(EXIT_FAILURE);
	}
	FD_ZERO(&rfds);
	FD_SET(pipefd,&rfds);

	tv.tv_sec=10;
	tv.tv_usec=0;

	retval=select(1+pipefd,&rfds,NULL,NULL,&tv); //Will start monitoring only after read end is opened, because line21 is a blocking call

	if(retval==-1){
		perror("select");
		exit(EXIT_FAILURE);
	}
	else if(retval){

		read(pipefd,buf,buffer_size);
		printf("Data is available with in 10 sec\n");
		printf("Message received : %s\n",buf);
	}
	else{
		printf("No Data is available with in 10 sec\n");
	}
	return 0;
}
