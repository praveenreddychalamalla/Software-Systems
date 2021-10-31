/* @author Praveen Reddy 
 * @date : 2021-10-13
 * @desc SIGINT - Ignore and Default handlers
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/time.h>
#include <signal.h>

int main(){

    signal(SIGINT, SIG_IGN); //Interrupt signals are ignored. Try using ctrl+c
    sleep(5);
    signal(SIGINT, SIG_DFL); //Handled by default handler of SIGINT signals. You can interrupt using ctrl+c
    sleep(5);
    return 0;
}