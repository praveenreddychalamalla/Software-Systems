/* @author Praveen Reddy 
 * @date : 2021-09-14
 * @desc DataBase for record locking
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

struct DataBase{
    int train_no;
    int ticket_count;
};
int main(){

    struct DataBase db[3];
    for(int i=0;i<3;i++){
        db[i].train_no=i+1;
        db[i].ticket_count=0;
    }

    int fd=open("Records_18.txt",O_RDWR|O_CREAT, S_IRWXU|S_IRGRP|S_IROTH); //0744

    if(fd==-1){
        perror("open");
        exit(EXIT_FAILURE);
    }
    write(fd,&db,sizeof(db));
    close(fd);

    
    return 0;
}
