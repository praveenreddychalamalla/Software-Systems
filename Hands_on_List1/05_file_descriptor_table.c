/* @author Praveen Reddy 
 * @date : 2021-09-03
 * @desc Checking File descriptor table 
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(){
    
	int fd[5];
    int i=0;
    while(1){  //goto /proc/pid/fd and check file descriptor table
        
        if(i<5){

            char fileName[20]="file";
            char ch=(i+1)+'0';
            strncat(fileName,&ch,1);
            fd[i]=creat(fileName,0744);

            if(fd[i]==-1){
                perror("creat");
                exit(EXIT_FAILURE);
            }

            printf("%s created successfully with file descriptor value %d\n",fileName,fd[i]);
            i++;
        }
    }

    return 0;
}

/*  Output:

    total 0
    lrwx------ 1 praveen praveen 64 Sep 10 22:45 0 -> /dev/pts/0
    lrwx------ 1 praveen praveen 64 Sep 10 22:45 1 -> /dev/pts/0
    lrwx------ 1 praveen praveen 64 Sep 10 22:45 2 -> /dev/pts/0
    l-wx------ 1 praveen praveen 64 Sep 10 22:45 3 -> '/home/praveen/IIITB/Term 1/Software Systems/Lab Exercises/file1'
    l-wx------ 1 praveen praveen 64 Sep 10 22:45 4 -> '/home/praveen/IIITB/Term 1/Software Systems/Lab Exercises/file2'
    l-wx------ 1 praveen praveen 64 Sep 10 22:45 5 -> '/home/praveen/IIITB/Term 1/Software Systems/Lab Exercises/file3'
    l-wx------ 1 praveen praveen 64 Sep 10 22:45 6 -> '/home/praveen/IIITB/Term 1/Software Systems/Lab Exercises/file4'
    l-wx------ 1 praveen praveen 64 Sep 10 22:45 7 -> '/home/praveen/IIITB/Term 1/Software Systems/Lab Exercises/file5'

*/
