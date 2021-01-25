#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    printf("Poczatek\n");
    pid_t pid = fork();
    if (fork() == 0) {
         if (fork() == 0) {
            printf("Proces dziecko od procesu dziecko, zmienna pid = %d\n", pid);
            printf("Pid dziecka od dziecka: %d\n", getpid());
            exit(7);
         }
         wait(NULL);
        printf("Proces dziecko, zmienna pid = %d\n", pid);
        printf("Pid dziecka: %d\n", getpid());
    }
    if (pid > 0){
        if (pid1 == 0) {
            printf("Proces dziecko od procesu rodzic, zmienna pid = %d\n", pid);
            printf("Pid dziecka od rodzica: %d\n", getpid());
            exit(7);
         }
        wait(NULL);
        wait(NULL);
        printf("Proces rodzic, zmienna pid = %d\n", pid);
        printf("Pid rodzica: %d\n", getpid());
    }
    printf("Koniec\n");
    return 0;
}