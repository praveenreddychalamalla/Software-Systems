/* @author Praveen Reddy 
 * @date : 2021-09-20
 * @desc execve system call - Used to execute binary executable file
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

int main(){

	if(!fork()){ //Child Process

		const char* filename="copy"; //Executable file that has to be executed using execve
		char* argv[]={"copy","test","file", NULL}; //Inputs to executable program, by convention first string has to be executable file name (i.e., here argv[0]="copy"). 
		char* envp[]={NULL};

		execve(filename,argv,envp); // execve()  does  not return on success

		/*No statements in the program will be executed after execve (exec family)sys call*/
		printf("This statement is not executed");
	}
	else{ //Parent Process

		printf("Parent Exited\n");
		exit(EXIT_SUCCESS);
	}

}