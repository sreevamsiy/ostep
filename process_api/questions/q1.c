#include<stdio.h>
#include <unistd.h>
#include <stdlib.h>
// initialize variable in the parent process
int main(int argc, char *argv[]) {
    int x = 100;
    printf("Value of x at the time of initialization in parent: %d\n", x);
    int rc = fork();
    if(rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    // create a child process and print the variable value
    } else if(rc == 0) {
        x = 101;
        printf("Value of x in child process: %d\n", x);
    // change the variable value in parent process and print it
    } else {
        x = 102;
        printf("Value of x in parent process at the end: %d\n", x);
    }
    return 0;
}

