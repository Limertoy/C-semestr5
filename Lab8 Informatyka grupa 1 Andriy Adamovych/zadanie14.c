#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    if (fork() == 0) {
        if (fork() == 0) {
            if (fork() == 0) {
                printf("child1 pid = %d\n", getpid());
                exit(0);
            }
            printf("child2 pid = %d\n", getpid());
            exit(0);
        }
        printf("child3 pid = %d\n", getpid());
        exit(0);
    }

    sleep(20);
    wait(NULL);

    exit(0);
}
