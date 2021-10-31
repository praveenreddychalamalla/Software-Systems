/* @author Praveen Reddy 
 * @date : 2021-10-13
 * @desc Get Resource limits
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

int main(){

    struct rlimit limits;

    int limit[]={RLIMIT_AS, RLIMIT_CORE, RLIMIT_CPU, RLIMIT_DATA, RLIMIT_FSIZE, RLIMIT_LOCKS,
                 RLIMIT_MEMLOCK, RLIMIT_MSGQUEUE, RLIMIT_NICE, RLIMIT_NOFILE, RLIMIT_NPROC,
                 RLIMIT_RSS, RLIMIT_RTPRIO, RLIMIT_RTTIME, RLIMIT_SIGPENDING, RLIMIT_STACK, 0};

    char* name[]={"virtual memory", "core file size", "cpu time", "data seg size", "file size",
                  "file locks","max locked memory","msgqueue size","nice value", "open files", "processes",
                  "resident set", "realtime priority", "realtime timeout", "pending signals","stack size"};

    for(int i=0;i<16;i++){
        int retval=getrlimit(limit[i],&limits);
        if(retval==-1){
            perror("getrlimit");
            exit(EXIT_FAILURE);
        }
        printf("%20s\t: Soft Limit = %20lu\t Hard Limit = %20lu \n",name[i],limits.rlim_cur,limits.rlim_max);
    }

}

/*Output: 

      virtual memory    : Soft Limit = 18446744073709551615  Hard Limit = 18446744073709551615 
      core file size    : Soft Limit =                    0  Hard Limit = 18446744073709551615 
            cpu time    : Soft Limit = 18446744073709551615  Hard Limit = 18446744073709551615 
       data seg size    : Soft Limit = 18446744073709551615  Hard Limit = 18446744073709551615 
           file size    : Soft Limit = 18446744073709551615  Hard Limit = 18446744073709551615 
          file locks    : Soft Limit = 18446744073709551615  Hard Limit = 18446744073709551615 
   max locked memory    : Soft Limit =             67108864  Hard Limit =             67108864 
       msgqueue size    : Soft Limit =               819200  Hard Limit =               819200 
          nice value    : Soft Limit =                    0  Hard Limit =                    0 
          open files    : Soft Limit =                 1024  Hard Limit =                 4096 
           processes    : Soft Limit =                30790  Hard Limit =                30790 
        resident set    : Soft Limit = 18446744073709551615  Hard Limit = 18446744073709551615 
   realtime priority    : Soft Limit =                    0  Hard Limit =                    0 
    realtime timeout    : Soft Limit = 18446744073709551615  Hard Limit = 18446744073709551615 
     pending signals    : Soft Limit =                30790  Hard Limit =                30790 
          stack size    : Soft Limit =              8388608  Hard Limit = 18446744073709551615 

 */

