#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX 512

int main(int argc, char* argv[]) {
    char buf[MAX];
    int plik_open, plik_close, lbajt;

    if (argc < 3) {
        fprintf(stderr, "Za malo argumentow. Uzyj:\n");
        fprintf(stderr, "%s <nazwa pliku>\n", argv[0]);
        exit(1);
    }

    plik_open = open(argv[1], O_RDONLY);

    if (plik_open == -1) {
        perror("Blad otwarcia pliku.\n");
        exit(1);
    }

    

    if (lbajt == -1) {
        perror("Blad odczytu pliku zrodlowego.\n");
        exit(1);
    }

    if (close(plik_open) == -1 || close(plik_close) == -1) {
        perror("Blad zamkniecia pliku.\n");
        exit(1);
    }

    exit(0);
}