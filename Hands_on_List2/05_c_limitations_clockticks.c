/* @author Praveen Reddy 
 * @date : 2021-10-13
 * @desc System limitations 
 */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

int main(){

	long ticks; 

	ticks=sysconf(_SC_CLK_TCK); //get configuration information at runtime

	if(ticks==-1){
		perror("sysconf");
		exit(EXIT_FAILURE);
	}
	printf("Number of clock ticks (jiffy) per second = %ld\n", ticks);

	return 0;
}
