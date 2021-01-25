#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define MAX 512

int main(int argc, char *argv[])
{
    char buf[MAX];
    FILE *plik_otw, *plik_zam;

    if (argc < 4)
    {
        fprintf(stderr, "Za malo argumentow. Uzyj:\n");
        fprintf(stderr, "%s <plik zrodlowy 1> ... <plik zrodlowy n> <plik docelowy>\n", argv[0]);
        exit(1);
    }

    int i;
    int n = argc-1;
    for(i = 1; i < n; i++){
        char ch;
        
        plik_otw = fopen(argv[i], "r");
        if(i == 1)
            plik_zam = fopen(argv[n], "w");
        else
            plik_zam = fopen(argv[n], "a");

        if(plik_otw == NULL || plik_zam == NULL){
            printf("Błąd otwarcia pliku źrodłowego: %s.\n", argv[i]);
            exit(1);
        }

        if(plik_zam == NULL){
            printf("Błąd otwarcia pliku zapisywania.\n");
            exit(1); 
        }
        
        while((ch = fgetc(plik_otw)) != EOF)
            putc(ch, plik_zam);

        fclose(plik_otw);
        fclose(plik_zam);
    }

    printf("Pliki zostały przekopiowane do pliku %s\n", argv[n]);


    exit(0);
}