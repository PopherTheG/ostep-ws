#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>

int main(int argc, char **argv) {
    open("./samplefile", O_CREAT | O_WRONLY, S_IRWXU);
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
    
    } else {
    
    }
}
