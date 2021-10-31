/* @author Praveen Reddy 
 * @date : 2021-09-03
 * @desc Copy one file to other
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#define buffer_size 1024

int main(){
    
    const char* src="/home/praveen/IIITB/Term 1/Software Systems/Lab Exercises/Hands_on_List1/test";
    const char* dest="/home/praveen/IIITB/Term 1/Software Systems/Lab Exercises/Hands_on_List1/file";
    
	int fd1= open(src,O_RDONLY);
    int fd2= open(dest, O_TRUNC | O_WRONLY); //Erases everything in file before writing

    if(fd1==-1 || fd2==-1){
        perror("open");
        exit(EXIT_FAILURE);
    }

    char buf[buffer_size];

    int size;
    while( (size=read(fd1,buf,buffer_size)) == buffer_size ){ //Read 1024 bytes from source and write in destination file until bytes available to read are fewer than 1024 
        write(fd2,buf,size);
        //write(1,buf,size);
    }
    write(fd2,buf,size);
    //write(1,buf,size);
    close(fd1);
    close(fd2);
    

    return 0;
}
