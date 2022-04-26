#include <signal.h> // kill, sigaction
#include <stdio.h>
#include <stdlib.h> // exit
#include <unistd.h> // getpid, fork, pause, pipe
#include <getopt.h>

#define errExit(msg) \
    do { \
        perror(msg); \
        exit(EXIT_FAILURE); \
    } while(0) \

//
