#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    
    int fd[2];
    pipe(fd);
    
    int rc1 = fork();
    if(rc1 < 0) {
        //fork failed
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if(rc1 == 0) {
        //execute a command
        close(1);
        dup(fd[1]);
		close(fd[0]);
		close(fd[1]);
        char* myargs[1];
        myargs[0] = "/bin/ls";
        myargs[1] = NULL;
        fprintf(stderr,"************* Running ls -l *************\n");	
        execvp(myargs[0], myargs);
    } 
    
    int rc2 = fork();
    if(rc2 < 0) {
        //fork failed
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if(rc2 == 0) {
        //execute a command
        close(0);
        dup(fd[0]);
		close(fd[0]);
		close(fd[1]);
        char* myargs[3];
        myargs[0] = "grep";
        myargs[1] = "q.";
        myargs[2] = NULL;
        fprintf(stderr,"************* Running grep pipe *************\n");
        execvp(myargs[0], myargs);
    } 
    
    close(fd[0]);
	close(fd[1]);
	/* Wait for the children to finish, then exit. */
	waitpid(rc1,NULL,0);
	waitpid(rc2,NULL,0);
	printf("************* Father exitting... *************\n");
    return 0;
}