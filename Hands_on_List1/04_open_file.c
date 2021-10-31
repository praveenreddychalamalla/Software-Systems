/* @author Praveen Reddy 
 * @date : 2021-09-03
 * @desc Opening file in Read Write Mode with O_EXCL flag
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/* Note : The behavior of O_EXCL is undefined if it is used without O_CREAT. Hence use O_EXCL in conjuction with O_CREAT.
 * If you want to create a file and the file already exists, then usage of O_EXCL makes open system call to fail. 
 * i.e., if the file is already created, then don't create, return -1.
 */
int main(){

    const char* path1 = "/home/praveen/IIITB/Term 1/Software Systems/Lab Exercises/Hands_on_List1/test";
    const char* path2 = "temp"; //Non existing file
    
	int fd1=open(path1, O_RDWR); //Existing file without O_EXCL flag - Opens Successfully

    if(fd1==-1){

        perror("open");
    }
    else{

        printf("Existing file opened successfully in read write mode with file descriptor value %d\n",fd1);
    
        close(fd1);
    }
    

    int fd2=open(path1, O_CREAT | O_EXCL, O_RDWR ); //Existing file with O_EXCL flag - Results error

    if(fd2==-1){
        
        perror("open");
    }
    else{

        printf("Existing file opened successfully in read write mode with file descriptor value %d\n",fd2);
    
        close(fd2);
    }

    int fd3=open(path2,O_RDWR) ; //Non Existing file without O_EXCL flag - Results Error

    if(fd3==-1){
        
        perror("open");
    }
    else{

        printf("Non existing file is created and opened successfully in read write mode with file descriptor value %d\n",fd3);
    
        close(fd3);
    }

    int fd4=open(path2,O_CREAT | O_EXCL, O_RDWR ) ; //Non Existing file with O_EXCL flag - New File is created and opened in RDWR mode

    if(fd4==-1){
        
        perror("open");
    }
    else{

        printf("Non existing file is created and opened successfully in read write mode with file descriptor value %d\n",fd4);
    
        close(fd4);
    }
    return 0;
}
