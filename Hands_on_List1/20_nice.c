/* @author Praveen Reddy 
 * @date : 2021-09-19
 * @desc Modifying priority of process using nice and setpriority system calls
 */

//Run this program with super user previliges (sudo ./a.out)

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/resource.h>

int main(){
    
    int priority,retVal;
    
    /* getpriority(int which, id_t who) :
     * which - can be PRIO_PROCESS, PRIO_PGRP, PRIO_USER;
     * who - is interpreted relative to which & who = 0 implies w.r.t calling function
     */ 

    errno=0; //errno is never set to 0 by any system call or library function. Will be set to some nonzero value in case if any error occurs
    priority=getpriority(PRIO_PROCESS,0); //Get the priority of current process. In case of failure appropriate errno is set

    if(errno!=0){ //check if errno is set to any non zero number 
        perror("getpriority");
        exit(EXIT_FAILURE);
    }
    printf("Default priority of process = %d\n",priority);

    errno=0;
    priority=nice(-10); //Adds given nice value to the current thread and returns new nice value
    
    if(errno!=0){
        perror("nice");
        exit(EXIT_FAILURE);
    }
    printf("Priority of process after modification using nice = %d\n",priority);

    retVal=setpriority(PRIO_PROCESS,0,5); //Sets the current process priority to 5
    if(retVal==-1){ 
        perror("setpriority");
        exit(EXIT_FAILURE);
    }

    errno=0;
    priority=getpriority(PRIO_PROCESS,0); //Get the priority of current process
    if(errno!=0){ 
        perror("getpriority");
        exit(EXIT_FAILURE);
    }
    printf("Priority of process after modification using setpriority = %d\n",priority);
  

    return 0;
}