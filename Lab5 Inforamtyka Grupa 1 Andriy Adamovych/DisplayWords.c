#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>


void printWords(FILE *fd){
	char s[256];
	char ch;
	int n = 0;
	char *p;
	while ((ch = fgetc(fd)) != EOF){
		*(s + ((n) * sizeof(char))) = ch;
		n++;
	}
	p = strtok(s, " ");
	printf("%s", p);
	do {
			p=strtok('\0', " ");
			if(p) printf(",%s", p);
	} while(p);
	
}

int main(void){
	FILE *fd = fopen("displayWords.txt", "r");
	printWords(fd);
	fclose(fd);
}
