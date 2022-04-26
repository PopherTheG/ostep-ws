#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/signal.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void say_goodbye(int i) {
    printf("(pid %d) goodbye.\n", (int)getpid());
}

int main(int argc, char **argv) {
    printf("(pid %d) parent\n", (int)getpid());
    int parent_pid = (int)getpid();
    int rc = fork();

    if (rc < 0) {
        // fork failed
        fprintf(stderr, "fork() failed\n");
        exit(1);
    } else if (rc == 0) {
        // child
        printf("(pid %d) child\n",(int)getpid());
        printf("(pid %d) hello\n", (int)getpid());
        printf("(pid %d) parent pid: %d\n", (int)getpid(), parent_pid);
        kill(parent_pid, SIGINT);
    } else {
        // parent
        signal(SIGINT, say_goodbye);
    }
    return 0;
}
