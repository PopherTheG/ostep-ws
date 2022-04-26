#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv) {
    int x;
    printf("(pid %d)\t parent\n", (int)getpid());
    printf("(pid: %d)\t x = %d\n", (int)getpid(), x);
    x = 100;
    printf("(pid: %d)\t x = %d\n", (int)getpid(), x);
    int rc = fork();
    
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child
        printf("(pid %d)\t child\n", (int)getpid());
        printf("(pid %d)\t x = %d\n", (int)getpid(), x);
        x = x + 1;
        printf("(pid %d)\t x = %d\n", (int)getpid(), x);
    } else {
        // parent
        wait(NULL);
        x = x + 1;
        printf("(pid %d)\t parent\n", (int)getpid());
        printf("(pid %d)\t x = %d\n", (int)getpid(), x);
    }
    return 0;
}
