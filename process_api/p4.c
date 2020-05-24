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
        open("./p4.output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
        
        // now exec "wc"...
        char *myargs[3];
        myargs[0] = "wc";
        myargs[1] = "p3.c";
        myargs[2] = NULL;
        execvp(myargs[0], myargs);
        printf("this shouldn't print out.");
    } else {
        //parent goes down this path (main)
        int rc_wait = wait(NULL);
    }
    return 0;   
}