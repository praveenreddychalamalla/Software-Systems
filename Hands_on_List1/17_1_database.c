/* @author Praveen Reddy 
 * @date : 2021-09-14
 * @desc Database for online ticket reservation simulation
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

struct DataBase{

    int ticket_no;
};
int main(){

    struct DataBase db;
    db.ticket_no=0;

    int fd=open("Records_17.txt",O_RDWR|O_CREAT, S_IRWXU|S_IRGRP|S_IROTH); //0744

    if(fd==-1){
        perror("open");
        exit(EXIT_FAILURE);
    }
    write(fd,&db,sizeof(db));
    close(fd);

    fd=open("Records_17.txt",O_RDONLY);
    if(fd==-1){
        perror("open");
        exit(EXIT_FAILURE);
    }
    read(fd,&db,sizeof(db));
    printf("Ticket_no : %d\n",db.ticket_no);
    close(fd);

    return 0;
}
