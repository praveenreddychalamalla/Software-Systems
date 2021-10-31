/* @author Praveen Reddy 
 * @date : 2021-09-13
 * @desc Know opening mode of a file using fcntl with file status flag - F_GETL
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(){

    int fd =open("file",O_RDWR); 

    if(fd==-1){
        perror("open");
        exit(EXIT_FAILURE);
    }
    int mode=fcntl(fd,F_GETFL); //The return value should be unmasked with Access mode - O_ACCMODE (Defined to be 3)
    mode =mode&O_ACCMODE;

    printf("Opening Mode of file : ");

    switch(mode){
        case 0: printf("O_RDONLY\n");
                break;
        case 1: printf("O_WRONLY\n");
                break;
        case 2: printf("O_RDWR\n");
                break;
        default : printf("%d",mode);
    }
    
    close(fd);

    return 0;

}