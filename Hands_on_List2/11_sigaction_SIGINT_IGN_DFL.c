/* @author Praveen Reddy 
 * @date : 2021-10-13
 * @desc sigaction system call - SIGINT - Ignore and Default handlers
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(){
	struct sigaction my_action;
	my_action.sa_handler=SIG_IGN; //Interrupt signals are ignored. 
	my_action.sa_flags=0;
	
	sigaction(SIGINT,&my_action, NULL); //Try using ctrl+c
	sleep(5);

	my_action.sa_handler=SIG_DFL; 
	sigaction(SIGINT,&my_action, NULL);//Handled by default handler of SIGINT signals. You can interrupt using ctrl+c
	sleep(5);

	return 0;
}