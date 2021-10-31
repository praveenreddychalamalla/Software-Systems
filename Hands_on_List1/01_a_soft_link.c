/* @author Praveen Reddy 
 * @date : 2021-09-03
 * @desc Creating Soft Link using symlink system call
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

int main(){

	const char* src="/home/praveen/IIITB/Term 1/Software Systems/Lab Exercises/Hands_on_List1/test";
	const char* link_path="/home/praveen/IIITB/Term 1/Software Systems/Lab Exercises/Hands_on_List1/test_soft_link";

	int val=symlink(src,link_path); //Returns 0 on successful creation, else -1

	if(val==-1){
		perror("symlink");
		exit(EXIT_FAILURE);
	}
	
	printf("Soft link created successfully\n");

	return 0;
}
