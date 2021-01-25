#include <stdio.h>
#include <regex.h>
#include <string.h>
#include <stdlib.h>

int main(){
    regex_t regex;
    int reti;
    char msgbuf[100];
    char text[100];
    char let[100];
    printf("Prosze podac tekst: ");
    fgets(text, 100, stdin);
    printf("Prosze podac co szukac: ");
    scanf("%s", let);
    reti = regcomp(&regex, let, 0);
    reti = regexec(&regex, text, 0, NULL, 0);
    if (!reti) {
        puts("Jest w tekscie.");
    }
    else if (reti == REG_NOMATCH) {
        puts("Nie ma w tekscie.");
    }
    else {
        regerror(reti, &regex, msgbuf, sizeof(msgbuf));
        fprintf(stderr, "Regex match failed: %s\n", msgbuf);
        exit(1);
    }   
}