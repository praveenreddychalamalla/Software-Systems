/* @author Praveen Reddy 
 * @date : 2021-09-20
 * @desc execvp system call - Similar to execv, but instead passing variable arguments, vector of arguments are passed
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

int main(){

	int retval;
	if(!fork()){ 

		const char* file="ls";
		char* argv[]={"ls","-l","-R",NULL};//By convention first argument is name of executable (No significance) followed by other arguments with NULL terminated pointer
		retval=execvp(file,argv); 
		
		if(retval==-1){ //Control is not reached here if execvp executes successfully
			perror("execl");
			exit(EXIT_FAILURE);
		}
	}
	else{ 
		exit(EXIT_SUCCESS);
	}

}