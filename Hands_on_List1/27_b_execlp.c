/* @author Praveen Reddy 
 * @date : 2021-09-20
 * @desc execlp system call 
 */

/*In contrast to execl sys call, instead of passing path of binary executable, just name of binary executable file is specified.
 *The file is searched in the PATH variable (extern **environ) and executed accordingly (first hit)
 */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

int main(){

	int retval;
	
	if(!fork()){ 

		const char* file="ls";
		retval=execlp(file,"ls","-l","-R",NULL); //After file name, variable number of arguments can be passed. 
		/*By convention first argument is name of executable (No significance) followed by other arguments with NULL terminated pointer*/
		
		if(retval==-1){ //Control is not reached here if execlp executes successfully
			perror("execl");
			exit(EXIT_FAILURE);
		}
	}
	else{ 
		exit(EXIT_SUCCESS);
	}

}