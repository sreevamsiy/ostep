#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int rc = fork();
    if(rc < 0) {
        //fork failed
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if(rc == 0) {
        //execute a command
        char* myargs[1];
        myargs[0] = "/bin/ls";
        myargs[1] = NULL;
        execvp(myargs[0], myargs);
    } else {
        // do nothing
    }
    return 0;
}