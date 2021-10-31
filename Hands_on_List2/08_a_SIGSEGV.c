/* @author Praveen Reddy 
 * @date : 2021-10-13
 * @desc Signals - SIGSEGV
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void sig_handler(int sig){ // Use trap -l in cmd line to know signal numbers and corresponding signal
	printf("signal caught\n");
	printf("signal SIGSEGV , number : %d\n",sig);
	exit(0);
}

int main(){

	signal(SIGSEGV, sig_handler); //Segementation fault
	int a[10];
	printf("%d",a[10000]); //Segfault
	return 0;
}