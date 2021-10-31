/* @author Praveen Reddy 
 * @date : 2021-09-20
 * @desc Orphan Process
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){

    if(!fork()){
       printf("Before Orphan, Parent Process id : %d\n",getppid());
       sleep(3);
       /*As the parent process will be terminated by this time, this child process will be attached to systemd or init process 
        *As there is no parent process(Process which created this), this child process is now an orphan process. . 
        *It's exit status will collected by system_d or init process accordingly to which it is attached to.
        */
       printf("After Orphan, Parent Process id: %d\n",getppid()); 
       exit(EXIT_SUCCESS);
    }
    else{
        /* Parent will exit (terminated) when the child process is in sleep state */
        printf("Parent Process : %d\n ",getpid());
        exit(EXIT_SUCCESS);
    }
}
