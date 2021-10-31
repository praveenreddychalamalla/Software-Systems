/* @author Praveen Reddy 
 * @date : 2021-10-13
 * @desc System limitations 
 */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

int main(){

	long CHILD_MAX; 

	CHILD_MAX=sysconf(_SC_CHILD_MAX); //get configuration information at runtime

	if(CHILD_MAX==-1){
		perror("sysconf");
		exit(EXIT_FAILURE);
	}
	printf("Maximum number of simultaneous process per user id = %ld\n", CHILD_MAX);

	return 0;
}
