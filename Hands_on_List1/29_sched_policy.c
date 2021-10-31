/* @author Praveen Reddy 
 * @date : 2021-09-20
 * @desc Changing Scheduling Policy
 */

//Run this program with super user previliges (sudo ./a.out)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
int main(){

	pid_t pid=getpid();

	int spolicy=sched_getscheduler(pid);
	printf("Scheduling Policy before modifying : %d\n", spolicy);

	struct sched_param p;
	p.sched_priority = 15; // FOR RT give 1-99, for other policies 0

	int retval =sched_setscheduler(pid,SCHED_RR,&p);
	if(retval==-1){
		perror("sched_setscheduler");
		exit(EXIT_FAILURE);
	}

	spolicy=sched_getscheduler(pid);
	printf("Scheduling Policy after modifying  : %d\n", spolicy);
	return 0;
}

/*  grep define.SCHED_ /usr/include/linux/sched.

	#define SCHED_NORMAL		0
	#define SCHED_FIFO		1
	#define SCHED_RR		2
	#define SCHED_BATCH		3
	#define SCHED_IDLE		5
	#define SCHED_DEADLINE		6
	#define SCHED_RESET_ON_FORK     0x40000000
	#define SCHED_FLAG_RESET_ON_FORK	0x01
	#define SCHED_FLAG_RECLAIM		0x02
*/
