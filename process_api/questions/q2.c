#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    // open a file and the create a child
    int fd = open("./q2.output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
    int rc = fork();
    if(rc < 0) {
        // fork failed
        fprintf(stderr, "failed to fork\n");
        exit(1);
    } else if(rc == 0) {
        // write to file in child
        for(int i = 0; i < 10; i++) {
            dprintf(fd, "hello from child!\n");
        }
    } else {
        // write to file in parent
        for(int i = 0; i < 10; i++) {
            dprintf(fd, "hello from parent!\n");
        }
    }
    return 0;
}

