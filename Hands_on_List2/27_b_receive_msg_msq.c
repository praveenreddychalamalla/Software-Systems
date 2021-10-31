/* @author Praveen Reddy 
 * @date : 2021-10-06
 * @desc Receiving a message from message queue . With IPC_NOWAIT flag
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

	printf("Enter message type to receive: ");
	scanf("%ld",&mq.mtype);

	int retval=msgrcv(msqid,&mq,sizeof(mq.mtext),mq.mtype,IPC_NOWAIT);//If there is no message of given type in queue, returns immediately by setting appropriate errno
	if(retval==-1){
		perror("msgrcv");
		exit(EXIT_FAILURE);
	}
	printf("Message type : %ld\n", mq.mtype);
	printf("Message : %s\n",mq.mtext);

	return 0;
}
