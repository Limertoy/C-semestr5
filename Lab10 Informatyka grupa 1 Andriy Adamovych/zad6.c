#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#define MAX 512

int main(int argc, char* argv[]) {
    char buf[MAX];
    FILE *plik_otw, *add;
    char ch;

    if (argc < 1) {
        fprintf(stderr, "Za malo argumentow. Uzyj:\n");
        fprintf(stderr, "%s <plik zrodlowy>\n", argv[0]);
        exit(1);
    }

    plik_otw = fopen(argv[1], "r");

    if (plik_otw == NULL) {
        perror("Blad otwarcia pliku zrodlowego.\n");
        exit(1);
    }
    
    int a = 1;
    
    while ((ch = fgetc(plik_otw)) != EOF){
        if(isascii(ch) == 0){
            printf("Plik %s nie jest plikiem tekstowym.\n", argv[1]);
            a = 0;
            exit(1);
        }
    }

    if (a == 1){
        printf("Plik %s jest plikiem tekstowym.\n", argv[1]);
    }

    fclose(plik_otw);

    exit(0);
}