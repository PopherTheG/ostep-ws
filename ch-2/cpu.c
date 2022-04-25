#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <assert.h>

void Spin(int sec);

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "usage: cpu <string>\n");
        exit(1);
    }

    char *str = argv[1];
    
    while (1) {
        Spin(1);
        printf("%s\n", str);
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
