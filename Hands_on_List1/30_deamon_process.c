/* @author Praveen Reddy 
 * @date : 2021-09-21
 * @desc Deamon Process Creation
 */

/* Deamon Process: 
 * executed as bg process, Orphan Process, No controlling terminal, run with super user privileges, session leaders, process group leaders
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(){

    if(!fork()){
        setsid(); //creates a new session if the calling process is not a process group leader. Initially new session has no controlling terminal
        /*The calling process is the leader of the new session (i.e., its session ID is made the same as its process ID).  
         *The calling process also becomes the process group leader of a new process group in the session (i.e., its process group ID is made the same as its process ID).
         */
        chdir("/"); //Change to root directory
        umask(0); //Gives super user previleges
        while(1){
            
            sleep(3); //Executes the following task for every 3 seconds (Interval)
            
            if(!fork()){

                const char* path="/home/praveen/IIITB/Term 1/Software Systems/Lab Exercises/Hands_on_List1/deamon_script.sh";
                char* argv[]={"deamon_script.sh",NULL};
                char* envp[]={NULL};
                
                execve(path,argv,envp);
                
                perror("execve");
                exit(EXIT_FAILURE);
            }
            else{
                printf("Process id : %d\n",getpid());
                printf("Deamon Process is running....\n");
            }
            
        }
    }
    else{
        exit(EXIT_SUCCESS); //Makes child process as orphan process
    }
}

/*ps axo pid,ppid,pgrp,tty,tpgid,sess,comm |awk '$2==1' |awk '$1==$3'*/