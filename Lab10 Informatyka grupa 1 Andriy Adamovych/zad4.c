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

    if (argc < 2)
    {
        fprintf(stderr, "Za malo argumentow. Uzyj:\n");
        fprintf(stderr, "%s <plik zrodlowy> <plik docelowy>\n", argv[0]);
        exit(1);
    }

    plik_otw = fopen(argv[1], "r");
    plik_zam = fopen(argv[2], "w");

    if (plik_otw == NULL)
    {
        perror("Blad otwarcia pliku zrodlowego.\n");
        exit(1);
    }

    if (plik_zam == NULL)
    {
        perror("Blad otwarcia pliku docelowego.\n");
        exit(1);
    }

    char *lines[50] = {NULL};
    int i, j, k;

    for (i = 0; fgets(buf, MAX, plik_otw) != NULL;)
    {
        free(lines[i]);
        lines[i] = strdup(buf);
        i = (i + 1) % 50;
    }
    

    for (j = i;;)
    {
        if (lines[i]){
            for(k = strlen(lines[i])-1; k >= 0; k--){
                fputc(lines[i][k], plik_zam);
            }
        }
        i = (i + 1) % 50;
        if (i == j)
            break;
    }

    fclose(plik_otw);
    fclose(plik_zam);

    exit(0);
}