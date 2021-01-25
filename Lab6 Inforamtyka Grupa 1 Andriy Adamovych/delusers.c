#define _GNU_SOURCE
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <crypt.h>

int main(int argc, char *argv[])
{
    const char name[] = "baza1.txt";

    FILE *file = fopen(name, "r");

    if (file == NULL)
    {
        perror(name);

        return EXIT_FAILURE;
    }

    char line[100];

    struct crypt_data data;
    data.initialized = 0;

    while (fgets(line, sizeof line, file) != NULL)
    {
        char login[32+1] = "";

        char *token = strtok(line, ";");
        strncat(login, token, 31);

        int n = strlen(token);

        char command[100] = "userdel ";
        strcat(command, login);
        strcat(command, " -r");
        system(command);
    }

    fclose(file);

    return 0;
}
