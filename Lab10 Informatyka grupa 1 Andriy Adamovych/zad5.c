#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#define MAX 512

int main(int argc, char* argv[]) {
    char buf[MAX];
    FILE *plik_otw, *plik_zam;
    int lbajt;

    if (argc < 3) {
        fprintf(stderr, "Za malo argumentow. Uzyj:\n");
        fprintf(stderr, "%s <plik zrodlowy> <plik docelowy> <parametr>\n", argv[0]);
        printf("Dostępne parametry: \n");
        printf("-s    kopiowanie 10 ostatnich słow\n");
        printf("-l    kopiowanie 10 ostatnich linii\n");
        printf("-z    kopiowanie 10 ostatnich znaków\n");
        exit(1);
    }

    plik_otw = fopen(argv[1], "r");
    plik_zam = fopen(argv[2], "w");

    if (plik_otw == NULL) {
        perror("Blad otwarcia pliku zrodlowego.\n");
        exit(1);
    }

    if (plik_zam == NULL) {
        perror("Blad otwarcia pliku docelowego.\n");
        exit(1);
    }

    if (strstr(argv[3], "-s")){ 
        char a[10][25];
        char buf[25];
        while (fscanf(plik_otw, "%s", buf) != EOF)
        {
            int i = 9;
            for (i; i > 0; i--)
                strcpy(a[i], a[i - 1]);
            strcpy(a[0], buf);
        }

        int i = 9;
        for (i; i >= 0; i--)
        {
            fprintf(plik_zam, a[i]);
            putc('\n', plik_zam);
        }
    } else if (strstr(argv[3], "-z")){
        char ch;
        
        fseek(plik_otw, 0, SEEK_END);
        int len = ftell(plik_otw);
        
        fseek(plik_otw, (len - 10), SEEK_SET);

        while((ch = fgetc(plik_otw)) != EOF){
            putc(ch, plik_zam);
        }
        printf("10 ostatnich znaków zostały skopiowane.\n");
    } else if (strstr(argv[3], "-l")){
        char *lines[10] = {NULL};
        int i, j;
        
        for(i = 0; fgets(buf, MAX, plik_otw) != NULL;){
            free(lines[i]);
            lines[i] = strdup(buf);
            i = (i + 1) % 10;
        }
        
        for(j = i;;){
            if(lines[i])
                fputs(lines[i], plik_zam);
            i = (i + 1) % 10;
            if(i == j)
                break;
        }
        printf("10 ostatnich linii zostały skopiowane.\n");
    } else {
        printf("Niepoprawny parametr!\n");
        exit(1);
    }

    if (lbajt == -1) {
        perror("Blad odczytu pliku zrodlowego.\n");
        exit(1);
    }

    fclose(plik_otw);
    fclose(plik_zam);

    exit(0);
}
