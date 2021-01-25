#define _GNU_SOURCE
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <crypt.h>

int wariacje1(){
    int liczbaLiterMalych = 26;
    int liczbaLiterDuzych = 26;
    int liczbaCyfr = 10;
    int kropkaUkosnik = 2;
    int dlugoscCiagu = 2;

    int res = (int)pow(liczbaCyfr + liczbaLiterDuzych + liczbaLiterMalych + kropkaUkosnik, dlugoscCiagu);
    return res;
}

int wariacje2(){
    static const char alphabet[] =
"abcdefghijklmnopqrstuvwxyz"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"0123456789"
"./";
    int len = strlen(alphabet);
    int i, j, sum = 0;
    for(i = 0; i < len; i++){
        for(j = 0; j < len; j++){
            sum++;
        }
    }
    return sum;
}

int losuj(int a, int b){
    int n, i;
    srand(time(NULL));
    n = (rand() % (b-a)) + a;
    return n;
}

void set(char salt[2]){
    struct crypt_data data[1] = {0};
    char *res;

    res = crypt_r("haslo", salt, data);
    printf("%s\n", res);
}

void errnoExample(){
    FILE *ptr;
    ptr = fopen("text", "r");
    if(ptr == NULL)
    printf("Coś poszło nie tak! Kod błędu: %d\n", errno);
    else
    printf("Success!");
}

void perrorExample(){
    FILE *ptr;
    ptr = fopen("text.txt", "r");
    if(ptr == NULL){
        printf("Coś poszło nie tak!\n");
        perror(strerror(errno));
    }
    else
    printf("Success!");
}

int main(){
    int a, b;
    int i, n;
    
    // printf("Losuj: \n");
    // scanf("%d", &a);
    // printf("Proszę podać koniec przedziału: ");
    // scanf("%d", &b);
    // printf("Wylosowana liczba: %d\n", losuj(a, b));
    printf("------------------------------\n");
    printf("Warjacje 1: \n");
    printf("%d\n", wariacje1());
    printf("------------------------------\n");
    printf("Warjacje 2: \n");
    printf("%d\n", wariacje2());
    
    printf("------------------------------\n");
    printf("Set: \n");
    char s[2] = "as";
    set(s);
    printf("------------------------------\n");
    printf("Errno Example: \n");
    errnoExample();
    printf("------------------------------\n");
    printf("Perror Example: \n");
    perrorExample();
}