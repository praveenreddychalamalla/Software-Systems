/* @author Praveen Reddy 
 * @date : 2021-09-13
 * @desc Identifying the type of file using lstat
 */

/* lstat syscall is same as that of stat syscall, except that lstat retrieves the information of link file (softlink)itself, 
 * instead of file it is pointing to. soft link files cannot be identified using  stat syscall
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[]){ //Get filepath from command line

    if(argc!=2){
        printf("Enter ./a.out filepath\n");
        return -1;
    }
    const char* path=argv[1];

    /* st_mode field accommodates the file type and permissions. Least 9 bits holds the permissions (Interpret in Octal System 0777)
     * Unmask the required part using corresponding mask
     */
    struct stat sb;
   
    int retval=lstat(path,&sb); 

    if(retval==-1){
        perror("lstat");
        exit(EXIT_FAILURE);
    }

    printf("Type of file : ");

    switch(sb.st_mode & S_IFMT){

        case S_IFSOCK : printf("socket\n");
                        break;
        case S_IFLNK : printf("symbolic link\n");
                        break;
        case S_IFREG : printf("regular file\n");
                        break;
        case S_IFBLK : printf("block device\n");
                        break;
        case S_IFCHR : printf("character device\n");
                        break;
        case S_IFIFO : printf("FIFO\n");
                        break;
        default      : printf("Unknown\n");
    }
    return 0;
}

/*     
    S_IFMT     0170000   bit mask for the file type bit field

       S_IFSOCK   0140000   socket
       S_IFLNK    0120000   symbolic link
       S_IFREG    0100000   regular file
       S_IFBLK    0060000   block device
       S_IFDIR    0040000   directory
       S_IFCHR    0020000   character device
       S_IFIFO    0010000   FIFO
*/