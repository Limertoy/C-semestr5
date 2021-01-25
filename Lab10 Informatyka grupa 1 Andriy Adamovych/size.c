#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[]) {
    int plik;
    long rozm;

    if (argc < 2) {
        fprintf(stderr, "Za malo argumentow. Uzyj:\n");
        fprintf(stderr, "%s <nazwa pliku>\n", argv[0]);
        exit(1);
    }

    plik = open(argv[1], O_RDONLY);

    if (plik == -1) {
        perror("Blad otwarcia pliku");
        exit(1);
    }

    rozm = lseek(plik, 0, SEEK_END);

    if (rozm == -1) {
        perror("Blad w pozycjonowaniu");
        exit(1);
    }

    printf("Rozmiar pliku %s: %ld\n", argv[1], rozm);

    if (close(plik) == -1) {
        perror("Blad zamkniecia pliku");
        exit(1);
    }

    exit(0);
}
