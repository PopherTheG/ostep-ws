#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <assert.h>

void Spin(int sec);

int main(int argc, char **argv) {
    int *p = malloc(sizeof(int));
    assert(p != NULL);
    printf("(%d) address pointed to by p: %p\n", getpid(), p);
    *p = 0; 

    while (1) {
        Spin(1);
        *p = *p + 1;
        printf("(%d) p: %d\n", getpid(), *p);
    }

    return 0;
}

void Spin(int sec) {
    struct timeval cur_time;
    time_t prev_time;

    gettimeofday(&cur_time, NULL);
    prev_time = cur_time.tv_sec;
    
    while (cur_time.tv_sec < prev_time + sec) {
        gettimeofday(&cur_time, NULL);
    }
}
