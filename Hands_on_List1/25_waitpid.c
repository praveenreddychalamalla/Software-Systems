/* @author Praveen Reddy 
 * @date : 2021-09-20
 * @desc waitpid system call, waiting for a particular child process to terminate
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>

/* pid_t waitpid(pid_t pid, int *wstatus, int options);
 * By default, waits only for terminated children. Use options, if you are intersted in someother state change.

 * pid > 0 ==> Waits for state change in child process with given pid.
 * pid = 0 ==> Waits for state change in any child process whose process group ID is equal to that of calling process. 
 *             Note : fork() - The child inherits its parent's process group (Default)
 * pid =-1 ==> Waits for state change in any child process.
 * pid <-1 ==> Waits for any child process whose process group ID is equal to the absolute value of pid.
 *
 * wstatus can be inspected with MACROS.
 * return value - process id whose state has changed, -1 failure
*/
int main(){

    int wstatus;
    pid_t cpid1=fork(); 
    if(!cpid1){ //Child 1
        printf("Child 1 Exited\n");
        exit(EXIT_SUCCESS);
    }
    else{
        pid_t cpid2=fork();
        if(!cpid2){ //Child 2
            sleep(1);
            printf("Child 2 Exited\n");
            exit(EXIT_SUCCESS);
        }
       else{
            pid_t cpid3=fork();
            if(!cpid3){ //Child 3
                printf("Child 3 Exited\n");
                exit(EXIT_SUCCESS);
            }
            else{
                waitpid(cpid2,&wstatus,0); //waits for its child process with pid = cpid2 to terminate.
                printf("Parent Exited\n");
                exit(EXIT_SUCCESS);
            }
       }
    }
}
