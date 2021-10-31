/* @author Praveen Reddy 
 * @date : 2021-10-06
 * @desc Creating a Message Queue
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
int main(){

	int msqid;
	key_t key;
	key=ftok(".",'a'); //Passing current directory and proj_id='a' (Least significant 8 bits must be non zero). (Any existing file name can be passed and any integer can be passed).
	/* same pathname and same proj_id - ftok produces same key*/

	msqid=msgget(key,IPC_CREAT|IPC_EXCL|0744); //If the msg queue exists already, msgget fails as IPC_EXCL flag is used

	if(msqid==-1){
		perror("msgget");
		exit(EXIT_FAILURE);
	}

	printf("key value = %d (Decimal)\n",key);
	printf("Key value = 0x%0x (Hexa Decimal)\n",key);
	printf("Message Queue Id = %d\n",msqid);

	return 0;
}
