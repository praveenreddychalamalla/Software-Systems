/* @author Praveen Reddy 
 * @date : 2021-09-03
 * @desc Creating Named pipe using mkfifo system call
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){


	int val=mkfifo("myfifo",0744); //Returns 0 on successful creation, else -1.  

	if(val==-1){
		perror("mkfifo");
		exit(EXIT_FAILURE);
	}

	printf("Named Pipe Created Successfully\n");

	return 0;
}
