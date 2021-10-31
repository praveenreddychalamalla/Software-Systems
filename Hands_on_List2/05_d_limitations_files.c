/* @author Praveen Reddy 
 * @date : 2021-10-13
 * @desc System limitations 
 */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

int main(){

	long OPEN_MAX; 

	OPEN_MAX=sysconf(_SC_OPEN_MAX); //get configuration information at runtime

	if(OPEN_MAX==-1){
		perror("sysconf");
		exit(EXIT_FAILURE);
	}
	printf("Maximum number of open files = %ld\n", OPEN_MAX);

	return 0;
}
