#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <crypt.h>


int main(int argc, char *argv[])
{
    const char name[] = "baza.txt";

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
        char full_name[50];
        char password[8+1];

        char *token = strtok(line, ";");
        strncat(login, token, 1);
        strcpy(full_name, token);
        strcat(full_name, " ");

        token = strtok(NULL, ";");
        strncat(login, token, 31);
        strcat(full_name, token);

        token = strtok(NULL, ";");

        int n = strlen(token);

        if (token[n-2] == '\r')
            token[n-2] = '\0';
        else
            token[n-1] = '\0';

        if (strlen(token) > 8) token[8] = '\0';

        strcpy(password, token);

        char *encrypted = crypt_r(password, "cd", &data);

        char command[100] = "useradd -m -p ";
        strcat(command, encrypted);
        strcat(command, " -c \"");
        strcat(command, full_name);
        strcat(command, "\" -s /bin/bash -g student ");
        strcat(command, login);

        system(command);
    }

    fclose(file);

    return 0;
}
