#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

//Zadanie 1.1
void printChars(FILE *fd){
	char ch;
	
	while ((ch = fgetc(fd))!= EOF){
		printf("%c", ch);
	}7
}

//Zadanie 1.2
void printLines(FILE *fd){
	int bufferLength = 255;
	char buffer[bufferLength];

	while(fgets(buffer, bufferLength, fd)) {
    	printf("%s\n", buffer);
	}
}

//Zadanie 1.3
void copy(const char *add1, char *add2){
	FILE *fd = fopen(add1, "r");
    FILE *nd = fopen(add2, "w");
    int bufferLength = 255;
    char buffer[bufferLength];
    char ch;

    while ((ch = fgetc(fd))!= EOF)
    {
		fprintf(nd, "%c", ch);
    } 
    fclose(fd);
    fclose(nd);
}

int main(void){
	FILE *fd = fopen("text.txt", "r");
	char *s1, *s2;
	s1 = "text.txt";
	s2 = "newtext.txt";
	
	printLines(fd);
	copy(s1, s2);
	
}	
