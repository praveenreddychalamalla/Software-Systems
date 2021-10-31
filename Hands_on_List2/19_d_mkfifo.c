/* @author Praveen Reddy 
 * @date : 2021-10-01
 * @desc creating named pipe using mkfifo
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#define buffer_size 1024

/*mkfifo is just a wrapper around mknod sys call. mkfifo internally calls mknod.*/
int main(){
	
	const char* file="myfifo1";
	int retval=mkfifo(file,0664);
	if(retval==-1){
		perror("mkfifo");
		exit(EXIT_FAILURE);
	}
	printf("Named pipe created successfully using mkfifo\n");
	return 0;
}
