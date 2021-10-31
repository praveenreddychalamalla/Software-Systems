/* @author Praveen Reddy 
 * @date : 2021-09-03
 * @desc file information using fstat
 */

/*fstat() is identical to stat(), except that the file about which information is to be retrieved is specified by the file descriptor fd.*/

/*lstat() is identical to stat(), except that if pathname is a symbolic link, 
 *then it returns information about the link itself, not the file that it refers to
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <errno.h>
#include <stdlib.h>

int main(){

	const char *path="file";
	int fd=open(path,O_RDONLY);
	
	if(fd==-1){
		perror("open");
		exit(EXIT_FAILURE);
	}

	struct stat sb;
	int val=fstat(fd,&sb); //Returns -1 and sets error number incase of failure, returns zero on successful

	if(val==-1){
		perror("fstat");
		exit(EXIT_FAILURE);
	}

	printf("Information of file %s\n", path);
	printf("Inode Number : %ld\n", (long)sb.st_ino);
	printf("Hard link count : %ld\n", (long)sb.st_nlink);
	printf("User id : %ld\n", (long)sb.st_uid);
	printf("Group id : %ld\n", (long)sb.st_gid);
	printf("Block size : %ld\n", (long)sb.st_blksize);
	printf("Number of blocks : %ld\n", (long)sb.st_blocks);
	printf("Time of last access : %s", ctime(&sb.st_atime));
	printf("Time of last modification : %s", ctime(&sb.st_mtime));
	printf("Time of last status change : %s", ctime(&sb.st_ctime));

	return 0;
}

/* 	Output:

	Information of file file
	Inode Number : 6304539
	Hard link count : 1
	User id : 1000
	Group id : 1000
	Block size : 4096
	Number of blocks : 8
	Time of last access : Fri Sep 10 15:29:24 2021
	Time of last modification : Fri Sep 10 15:21:26 2021
	Time of last status change : Fri Sep 10 15:21:26 2021

*/