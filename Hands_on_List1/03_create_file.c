/* @author Praveen Reddy 
 * @date : 2021-09-03
 * @desc Create file using creat system call
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

/*file descriptors 0 - stdin , 1 - stdout, 2 - stderr for any process are reserved. dev/tty*/
/*If file already exists, creat system call will not create any new file but return value will be success*/


int main(){

    const char* path="/home/praveen/IIITB/Term 1/Software Systems/Lab Exercises/Hands_on_List1/file";
    
	int fd=creat(path,0744); //Creates file and returns the first unused file descriptor

    if(fd==-1){
        perror("creat");
        exit(EXIT_FAILURE);
    }
    
    printf("File created Successfully with file descriptor value %d\n",fd);

    close(fd);

    return 0;
}
