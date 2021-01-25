#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void printChars(FILE *fd){
	char ch;
	
	while ((ch = fgetc(fd))!= EOF){
		printf("%c", ch);
	}
}

//Zadanie 2.1
int countWords1(FILE *fd){
	char ch;
	int inside = 0;
	int sum = 0;
	
	while ((ch = fgetc(fd))!= EOF){
		if (inside == 0) {
            if (isspace(ch)) continue;
            else {
				inside = 1;
                sum++;
            }
        } else if (inside == 1){
            if (!isspace(ch)) continue;
            else {
                inside = 0;
            }
        }
	}
	return sum;
}

//Zadanie 2.2
int countWords2(FILE *fd){
	char ch;
	int sum;
	char a = 0;
	
	while (1){
		ch = fgetc(fd);
		if (a == 0){
			a = ch;
		} else {
			if ((a >= 'a' && a <= 'z') && (ch == ' ' || ch == ',' || ch == EOF)){
				sum++;
			}
			a = ch;
		}
		if (ch == EOF) break;
	}
	return sum;
}

int main(void){
	FILE *fd = fopen("countWords.txt", "r");
	FILE *cd = fopen("countWords.txt", "r");
	FILE *d = fopen("countWords.txt", "r");
	printChars(d);
	printf("\n");
	printf("Liczenie slow, metoda 1: %d\n", countWords1(fd));
	printf("Liczenie slow, metoda 2: %d", countWords2(cd));
	fclose(fd);
	fclose(cd);
	fclose(d);
}
