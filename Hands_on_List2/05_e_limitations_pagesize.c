/* @author Praveen Reddy 
 * @date : 2021-10-13
 * @desc System limitations 
 */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

int main(){

	long PAGESIZE; 

	PAGESIZE=sysconf(_SC_PAGESIZE); //get configuration information at runtime

	if(PAGESIZE==-1){
		perror("sysconf");
		exit(EXIT_FAILURE);
	}
	printf("size of a page = %ld\n", PAGESIZE);

	return 0;
}
