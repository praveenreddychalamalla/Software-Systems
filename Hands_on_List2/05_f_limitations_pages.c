/* @author Praveen Reddy 
 * @date : 2021-10-13
 * @desc System limitations 
 */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

int main(){

	long PAGES; 

	PAGES=sysconf(_SC_PHYS_PAGES); //get configuration information at runtime

	if(PAGES==-1){
		perror("sysconf");
		exit(EXIT_FAILURE);
	}
	printf("total number of pages in the physical memory = %ld\n", PAGES);

	return 0;
}
