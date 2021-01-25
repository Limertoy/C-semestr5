#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    printf("Poczatek\n");
    pid_t pid = fork();
    if (pid < 0) fprintf(stderr, "Blad tworzenia procesu potomnego.\n");
    if (pid == 0) {
        printf("Proces dziecko, zmienna pid = %d\n", pid);
        printf("Pid dziecka: %d\n", getpid());
    }
    if (pid > 0){
        wait(NULL);
        printf("Proces rodzic, zmienna pid = %d\n", pid);
        printf("Pid rodzica: %d\n", getpid());
    }
    printf("Koniec\n");
    return 0;
}