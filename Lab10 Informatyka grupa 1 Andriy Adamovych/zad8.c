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
    
    int n = 0;
    int a = 1;
    while ((ch = fgetc(plik_otw)) != EOF){
        if(a == 1 && ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') || ch == '_')){
            n++;
            a = 0;
        } else if (!((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') || ch == '_')){
            a = 1;
        }
    }

    printf("Plik %s ma w sobie %d słów.\n", argv[1], n);

    fclose(plik_otw);

    exit(0);
}