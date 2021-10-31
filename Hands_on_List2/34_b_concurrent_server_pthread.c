/* @author Praveen Reddy 
 * @date : 2021-10-13
 * @desc Concurrent Server Program - Threads
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>         
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include <string.h>
#define buffer_size 1024

void thread_handler(void* nsd){ //function to be executed when a thread is created to serve the client

    int *sd=(int *) nsd;
    char buf[buffer_size];

    read(*sd,buf,buffer_size);

    printf("Message from client: %s\n",buf);
    char *servmsg="ACK from server";
    write(*sd,servmsg,strlen(servmsg));

    close(*sd); 
    //exit(EXIT_SUCCESS) - Process stops (Same process id as that of parent - Hence server gets terminated)
}

int main(){

    char buf[buffer_size];
    int sd,nsd,size;
    struct sockaddr_in serv, cli;
    sd=socket(AF_UNIX,SOCK_STREAM,0); //0 - Default Protocol

    serv.sin_family=AF_UNIX;
    serv.sin_addr.s_addr=INADDR_ANY ; //IP Address
    serv.sin_port=htons(9276) ; //host to network short 

    bind(sd, (void *)&serv, sizeof(serv));

    listen(sd, 5); //Backlog Queue size

    size=sizeof(cli);

    while(1){
        nsd=accept(sd,(void *)&cli, &size); //Waits for client
        pthread_t tid;
        int retval=pthread_create(&tid,NULL,(void*)thread_handler, (int *)&nsd);
        if(retval==-1){
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
        //pthread_join(tid,NULL);
    }
    return 0;
}