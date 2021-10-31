/* @author Praveen Reddy 
 * @date : 2021-09-20
 * @desc execl system call
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

int main(){

	int retval;

	if(!fork()){ 

		const char* path="/bin/ls";
		retval=execl(path,"ls","-l","-R",NULL); //After path, variable number of arguments can be passed. 
		/*By convention first argument is name of executable (No significance) followed by other arguments with NULL terminated pointer*/
		
		if(retval==-1){ //Control is not reached here if execl executes successfully
			perror("execl");
			exit(EXIT_FAILURE);
		}
	}
	else{ 
		exit(EXIT_SUCCESS);
	}

}