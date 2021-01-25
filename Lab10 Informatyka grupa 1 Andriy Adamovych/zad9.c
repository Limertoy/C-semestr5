#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#define MAX 512

int main(int argc, char *argv[])
{
    char buf[MAX];
    FILE *plik_otw, *plik_zam;

    if (argc < 2)
    {
        fprintf(stderr, "Za malo argumentow. Uzyj:\n");
        fprintf(stderr, "%s <plik pierwszy> <plik drugi>\n", argv[0]);
        exit(1);
    }

    plik_otw = fopen(argv[1], "r");
    plik_zam = fopen(argv[2], "r");

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

    char ch, lt;
    int i;
    int len1, len2;
    fseek(plik_otw, 0, SEEK_END);
    len1 = ftell(plik_otw);
    fseek(plik_otw, 0, SEEK_SET);
    fseek(plik_zam, 0, SEEK_END);
    len2 = ftell(plik_zam);
    fseek(plik_zam, 0, SEEK_SET);

    if (len1 == len2)
    {
        int a = 1;
        int n = 1;
        for (i = 0; i < len1; i++)
        {
            ch = fgetc(plik_otw);
            lt = fgetc(plik_zam);
            if (ch == '\n')
                a++;
            if (ch != lt)
            {
                printf("Pliki różnią się od znaku %d w linii %d\n", i + 1, a);
                n = 0;
                break;
            }
        }
        if (n == 1)
            printf("Pliki są identyczne.\n");
    }
    else if (len1 > len2)
    {
        int a = 1;
        for (i = 0; i < len1; i++)
        {
            ch = fgetc(plik_otw);
            lt = fgetc(plik_zam);
            if (ch == '\n')
                a++;
            if(isascii(lt)){
                if(ch != lt){
                    printf("Pliki różnią się od znaku %d w linii %d\n", i + 1, a);
                    break;
                }
            }

            if(!isascii(ch))
                len1--;

            if (lt == EOF)
            {
                printf("Plik %s zawiera %d znaków więcej niż plik %s\n", argv[1], len1 - i, argv[2]);
                break;
            }
        }
    } else if (len2 > len1){
        int a = 1;
        for (i = 0; i < len2; i++)
        {
            ch = fgetc(plik_otw);
            lt = fgetc(plik_zam);
            if (lt == '\n')
                a++;
            if(isascii(ch)){
                if(lt != ch){
                    printf("Pliki różnią się od znaku %d w linii %d\n", i + 1, a);
                    break;
                }
            }

            if(!isascii(lt))
                len2--;

            if (ch == EOF)
            {
                printf("Plik %s zawiera %d znaków więcej niż plik %s\n", argv[2], len2 - i, argv[1]);
                break;
            }
        }
    }

    fclose(plik_otw);
    fclose(plik_zam);

    exit(0);
}