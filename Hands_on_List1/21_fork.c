/* @author Praveen Reddy 
 * @date : 2021-09-19
 * @desc fork system call
 */


#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    
    int cpid=fork();
    if(cpid==0){
        printf("Child Process id : %d\n",getpid());
        printf("Parent Process id : %d\n",getppid());
    }
    else if(cpid>0){
        printf("Process id : %d\n",getpid());
        wait(0); //wait until one of its child terminates
    }
    else {
        perror("fork");
        exit(EXIT_FAILURE);
    }
}