/* @author Praveen Reddy 
 * @date : 2021-10-06
 * @desc Removing a Message Queue
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
int main(){

	key_t key;
	int msqid,retval;
	key=ftok(".",'a');
	msqid=msgget(key,0); //Message Queue id corresponding to the given key is returned. Message Queue with the given key should exist, else create by mentioning appropriate flags.
	
	retval=msgctl(msqid,IPC_RMID,NULL); 
	if(retval==-1){
		perror("msgctl");
		exit(EXIT_FAILURE);
	}

	printf("Message Queue Removed Successfully\n");
	return 0;
}
