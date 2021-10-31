/* @author Praveen Reddy 
 * @date : 2021-09-20
 * @desc execle system call
 */

/*Similar to execl , but the environment is also passed as argument*/
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

int main(){

	int retval;

	if(!fork()){ 
		
		extern char **environ; //Default environ for execl
		const char* path="/bin/ls";
		char** envp=environ; // New environment can also be passed
		retval=execle(path,"ls","-l","-R",NULL,envp);
		
		if(retval==-1){ //Control is not reached here if execle executes successfully
			perror("execl");
			exit(EXIT_FAILURE);
		}
	}
	else{ 
		exit(EXIT_SUCCESS);
	}

}