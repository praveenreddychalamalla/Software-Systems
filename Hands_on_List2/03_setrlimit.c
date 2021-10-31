/* @author Praveen Reddy 
 * @date : 2021-10-13
 * @desc Set Resource limits
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

int main(){

    struct rlimit old,new;

    int retval=getrlimit(RLIMIT_MSGQUEUE,&old);
    if(retval==-1){
        perror("getrlimit");
        exit(EXIT_FAILURE);
    }

    new.rlim_cur=old.rlim_cur-200;
    new.rlim_max=old.rlim_max;

    retval=setrlimit(RLIMIT_MSGQUEUE,&new);

    if(retval==-1){
        perror("setrlimit");
        exit(EXIT_FAILURE);
    }
    getrlimit(RLIMIT_MSGQUEUE,&old);
    printf("Modified resource limits - %s\t: Soft Limit = %lu\t Hard Limit = %lu \n","msgqueue",old.rlim_cur,old.rlim_max);
}


