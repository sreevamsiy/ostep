#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int rc = fork();
    if(rc < 0) {
        // fork failed
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if(rc == 0) {
        // child says hello
        printf("hello from child!\n");
    } else {
        // parent says goodbye
        sleep(1);
        printf("parent says goodbye!\n");
    }
}

