#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

//Zadanie 4.1
void printHex(FILE *fd){
	char ch;
	
	while ((ch = fgetc(fd))!=EOF)
		printf("%.2X ", ch);
}

//Zadanie 4.2
void printChar(FILE *fd){
	char ch;
	
	while((ch = fgetc(fd)) != EOF){
		switch (ch) {

        case '\n':
            printf("'\\n' ");
            break;
        case '\r':
            printf("'\\r' ");
            break;
        case '\t':
            printf("'\\t' ");
            break;
        default:
            if ((ch < 0x20) || (ch > 0x7f)) {
                printf("'\\%03o'", ch);
            } else {
                printf("'%c' ", ch);
            }
        break;
   }
	}
}

//Zadanie 4.3
void printLinesHex(FILE *fd){
	char str[1200+1];
	
	while (fgets(str, sizeof str, fd) != NULL){
		char ch;
		int i = 0;
		while(ch = str[i++]) printf("%.2X ", ch);
		printf("\n");
	}
}

//Zadanie 4.4
void printLinesChar(FILE *fd){
	char str[1200+1];
	
	while (fgets(str, sizeof str, fd) != NULL){
		char ch;
		int i = 0;
		while(ch = str[i++]){
				switch (ch) {

        case '\n':
            printf("'\\n' ");
            break;
        case '\r':
            printf("'\\r' ");
            break;
        case '\t':
            printf("'\\t' ");
            break;
        default:
            if ((ch < 0x20) || (ch > 0x7f)) {
                printf("'\\%03o'", ch);
            } else {
                printf("'%c' ", ch);
            }
        break;
		}
		}
		printf("\n");
	}
}

int main(void){
	int n;
	FILE *fd;
	printf("1 - linux.txt\n2 - windows.txt\n");
	printf("Choose file: ");
	scanf("%d", &n);
	if (n == 1){
		fd = fopen("linux.txt", "r");
		printHex(fd);
		printf("\n");
		fclose(fd);
		fd = fopen("linux.txt", "r");
		printChar(fd);
		printf("\n");
		fclose(fd);
		fd = fopen("linux.txt", "r");
		printLinesHex(fd);
		printf("\n");
		fclose(fd);
		fd = fopen("linux.txt", "r");
		printLinesChar(fd);
		printf("\n");
		fclose(fd);
	} else if (n == 2){
   		fd = fopen("windows.txt", "r");
   		printHex(fd);
   		printf("\n");
   		fclose(fd);
   		fd = fopen("windows.txt", "r");
	 	printChar(fd);
	 	printf("\n");
		fclose(fd);
		fd = fopen("windows.txt", "r");
		printLinesHex(fd);
		printf("\n");
		fclose(fd);
		fd = fopen("windows.txt", "r");
		printLinesChar(fd);
		fclose(fd);
	} else {
		printf("Bad input. Try again");
	}
	
}
