/* @author Praveen Reddy 
 * @date : 2021-10-13
 * @desc  Iterative Server Program
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>         
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#define buffer_size 1024

int main(){

    char buf[buffer_size];
    int sd,nsd,size;
    struct sockaddr_in serv, cli;
    sd=socket(AF_UNIX,SOCK_STREAM,0); //0 - Default Protocol

    serv.sin_family=AF_UNIX;
    serv.sin_addr.s_addr=INADDR_ANY ; //IP Address
    serv.sin_port=htons(9876) ; //host to network short 

    bind(sd, (void *)&serv, sizeof(serv));

    listen(sd, 5); //Backlog Queue size

    size=sizeof(cli);
    nsd=accept(sd,(void *)&cli, &size); //Waits for client

    read(nsd,buf,buffer_size);

    printf("Message from client: %s\n",buf);
    char *servmsg="ACK from server";

    write(nsd,servmsg,strlen(servmsg));

    
    return 0;
}