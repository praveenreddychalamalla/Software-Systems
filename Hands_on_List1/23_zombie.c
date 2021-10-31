/* @author Praveen Reddy 
 * @date : 2021-09-19
 * @desc Zombie state of a process
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){

    if(!fork()){
       printf("Child Process id : %d\n",getpid());
       exit(EXIT_SUCCESS);
    }
    else{
        /* Parent will be in sleep state for 10 seconds without collecting exit status from it's child process 
         * and hence child process after execution will be in Zombie state for sometime
         */
        sleep(100); 
        exit(EXIT_SUCCESS);
    }
}

/*
    Output :

    Name:   a.out
    State:  Z (zombie)
    Tgid:   4923
    Ngid:   0
    Pid:    4923
    PPid:   4922
    TracerPid:  0
    Uid:    1000    1000    1000    1000
    Gid:    1000    1000    1000    1000
    FDSize: 0
*/