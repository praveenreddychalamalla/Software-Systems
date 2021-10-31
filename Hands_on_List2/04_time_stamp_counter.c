/* @author Praveen Reddy 
 * @date : 2021-10-13
 * @desc Time Stamp Counter
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

/*TSC is incremented for every clk tick i.e, for every 1 tick - incremented by 1
 *In a 1GHZ cpu(10^9 clk cycles per second), tsc is incremented by 10^9 per second (10^9 ticks per second) i.e., incremented by 1 for every nano sec 
 */

unsigned long long int rdtsc(void){ //read time stamp counter - rdtsc 
	unsigned long long int x;
	__asm__ __volatile__("rdtsc": "=a" (x)); //Assembly lang
}
int main(){

	unsigned long long int start, end;
	int nano;
	start=rdtsc();
	for(int i=0;i<100;i++)getpid();
	end=rdtsc();
	nano =(end-start)/4.2; //Processor speed - 4.2 GHZ
	printf("%d ns\n",nano); //Time slapsed for execution of getpid() system call

	return 0;
}

