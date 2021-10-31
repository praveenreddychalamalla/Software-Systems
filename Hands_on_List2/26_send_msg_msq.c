/* @author Praveen Reddy 
 * @date : 2021-10-06
 * @desc Sending a Message to Message Queue
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#define buffer_size 128

struct msgbuf{
	long mtype; //Should be a positive integer. Used to identify type of message
	char mtext[buffer_size];
};

int main(){

	int msqid;
	key_t key;
	struct msgbuf mq;
	key=ftok(".",'a');

	msqid=msgget(key,0); //Message identifier associated with given key is returned

	if(msqid==-1){
		perror("msgget");
		exit(EXIT_FAILURE);
	}

	printf("Enter Message type : ");
	scanf("%ld",&mq.mtype);

	printf("Enter Message : ");
	scanf("%s",mq.mtext);
	int size=strlen(mq.mtext);

	msgsnd(msqid,&mq,size+1,0); 

	return 0;
}
