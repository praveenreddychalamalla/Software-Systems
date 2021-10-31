/* @author Praveen Reddy 
 * @date : 2021-10-06
 * @desc Change existing message queue permissions 
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

//uid,gid,mode,qbytes  can be altered

int main(){

	int msqid;
	key_t key;
	struct msqid_ds mq; //Check man page for fields of ipc_perm and msqid_ds structures

	key=ftok(".",'a'); 
	msqid=msgget(key,0); //Returns the message queue identifier asssociated with key. Message Queue associated with given key must exist, else use appropriate flags to create

	if(msqid==-1){
		perror("msgget");
		exit(EXIT_FAILURE);
	}

	mq.msg_perm.mode=0764;
	mq.msg_perm.uid=500;
	mq.msg_perm.gid=500;


	msgctl(msqid,IPC_SET,&mq);
	printf("Queue Permissions after changing....\n");
	printf("Access Permission :0%o\n",mq.msg_perm.mode);
	printf("Effective UID of owner :%d\n",mq.msg_perm.uid);
	printf("Effective GID of owner :%d\n",mq.msg_perm.gid);


	return 0;
}