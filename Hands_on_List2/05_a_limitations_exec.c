/* @author Praveen Reddy 
 * @date : 2021-10-13
 * @desc System limitations 
 */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

int main(){

	long ARG_MAX;

	ARG_MAX=sysconf(_SC_ARG_MAX); //get configuration information at runtime

	if(ARG_MAX==-1){
		perror("sysconf");
		exit(EXIT_FAILURE);
	}
	printf("Maximum length of the arguments to the exec family of functions = %ld\n", ARG_MAX);

	return 0;
}
