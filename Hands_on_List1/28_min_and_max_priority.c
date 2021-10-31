/* @author Praveen Reddy 
 * @date : 2021-09-20
 * @desc Maximum and Minimum Priority values for a RT Process (For RT process Policy - RR/FIFO)
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
int main(){

	int min_priority, max_priority;

	min_priority=sched_get_priority_min(SCHED_RR);
	max_priority=sched_get_priority_max(SCHED_RR);

	printf("Minimum priority of a Real Time Process : %d\n",min_priority);
	printf("Maximum priority of a Real Time Process : %d\n",max_priority);

	return 0;
}