#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    printf("hello world (pid:%d)\n", (int) getpid());
    int rc = fork();
    if (rc < 0) {
        //fork failed
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        //child: redirect standard output to a file
        close(STDOUT_FILENO);
        printf("this shouldn't print out.\n");
    } else {
        //parent goes down this path (main)
        int rc_wait = wait(NULL);
    }
    return 0;   
}