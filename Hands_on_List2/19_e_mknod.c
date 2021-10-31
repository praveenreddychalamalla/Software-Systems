/* @author Praveen Reddy 
 * @date : 2021-10-01
 * @desc creating named pipe using mknod
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#define buffer_size 1024

/*mknod is efficient than mkfifo*/
int main(){
	
	const char* file="myfifo2";
	int retval=mknod(file,S_IFIFO|0664,0); // If mode is not S_IFIFO or dev is not 0, the  behaviour  of  mknod()  is  unspecified.
	if(retval==-1){
		perror("mkfifo");
		exit(EXIT_FAILURE);
	}
	printf("Named pipe created successfully using mknod\n");
	return 0;
}
