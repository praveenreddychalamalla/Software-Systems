/* @author Praveen Reddy 
 * @date : 2021-10-06
 * @desc Message Queue Information
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <time.h>
int main(){

	int msqid;
	key_t key;
	//struct ipc_perm msg_perm is a structure in msqid_ds structure; 
	struct msqid_ds mq; //Check man page for fields of ipc_perm and msqid_ds structures

	key=ftok(".",'a'); 
	msqid=msgget(key,0); //Returns the message queue identifier asssociated with key. Message Queue associated with given key must exist

	if(msqid==-1){
		perror("msgget");
		exit(EXIT_FAILURE);
	}

	msgctl(msqid,IPC_STAT,&mq);

	printf("Access Permission :0%o\n",mq.msg_perm.mode);
	printf("Effective UID of owner :%d\n",mq.msg_perm.uid);
	printf("Effective GID of owner :%d\n",mq.msg_perm.gid);
	printf("Effective UID of creator :%d\n",mq.msg_perm.cuid);
	printf("Effective GID of creator :%d\n",mq.msg_perm.cgid);
	printf("Time of last msgsnd : %s",ctime(&mq.msg_stime));
	printf("Time of last msgrcv: %s",ctime(&mq.msg_rtime));
	printf("Time of last change: %s",ctime(&mq.msg_ctime));
	printf("Size of queue in bytes: %lu\n",mq.__msg_cbytes);
	printf("Current number of messages in queue: %lu\n",mq.msg_qnum);
	printf("Maximum number of bytes allowed in queue: %lu\n",mq.msg_qbytes);
	printf("PID of last msgsnd: %d\n",mq.msg_lspid);
	printf("PID of last msgrcv: %d\n",mq.msg_lrpid);
	return 0;
	
}

/*	Output :

	Access Permission :0744
	Effective UID of owner :1000
	Effective GID of owner :1000
	Effective UID of creator :1000
	Effective GID of creator :1000
	Time of last msgsnd : Wed Oct  6 18:10:28 2021
	Time of last msgrcv: Wed Oct  6 18:11:31 2021
	Time of last change: Wed Oct  6 18:09:24 2021
	Size of queue in bytes: 5
	Current number of messages in queue: 1
	Maximum number of bytes allowed in queue: 16384
	PID of last msgsnd: 15510
	PID of last msgrcv: 15571


*/