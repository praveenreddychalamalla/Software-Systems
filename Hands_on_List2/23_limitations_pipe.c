/* @author Praveen Reddy 
 * @date : 2021-10-06
 * @desc System imposed limitations on pipe 
 */
#include <stdio.h>
#include <unistd.h>

/* _SC_OPEN_MAX macro holds maximum number of files that can be opened within a process
 * _PC_PIPE_BUF macro holds maximum number of bytes that can be written to a pipe atomically.
 */
int main(){

	long PIPE_BUF, OPEN_MAX;

	PIPE_BUF=pathconf(".",_PC_PIPE_BUF) ; //get configuartion values. "." ==> current directory
	OPEN_MAX=sysconf(_SC_OPEN_MAX); //get configuration information at runtime

	printf("Maximum number of files that can be opened within a process = %ld\n", OPEN_MAX);
	printf("Maximum number of bytes that can be written to a pipe atomically = %ld\n", PIPE_BUF);

	return 0;
}
