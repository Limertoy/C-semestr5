#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

//Zadanie 1.1
int isNumber(const char *s) {
	int a, count;
	char ch = -1;
	count = 0;
	while ((int)ch != 0){
		ch = *(s + count * sizeof(char));
		if (isdigit(ch)){
			a = isdigit(ch);
			break;
		}
		count++;
	}
	return a;
}

//Zadanie 1.2
char *trim(char *s){
	int count = 0;
	int n = 0;
	char ch = -1;
	
	char *tr = (char *)malloc(sizeof(char));
	while ((int)ch != 0){
		ch = *(s + count * sizeof(char));
		if(!isspace(ch)){
			*(tr + ((n) * sizeof(char))) = ch;
			n++;
		}
		count++;
	}
	return tr;
}

//Zadanie 1.3
int getOperator(char *op, const char *s){
	int count = 0;
	int n = 0;
	char ch = -1;
	
	while((int)ch != 0){
		ch = *(s + count * sizeof(char));
		if (ch == *op){
			n = 1;
			break;
		}
		count++;
	}
	return n;
}

//Zadanie 1.4
int getFraction(const char *s){
	int count = 0;
	int n = 0, a = 0;
	char ch = -1;
	
	while((int)ch != 0){
		ch = *(s + count *sizeof(char));
		if(ch == '/' && a == 0 && count > 0){
			count++;
			n = 1;
			a+= 1;
		} else if (((char)ch >= '0' && (char)ch <= '9') || ch == 0) {
			count++;
			n = 1;
		} else {
			n = 0;
			break;
		}
	}
	return n;
}

int main(void){
    char *s = "-35x";
    char *s1 = "ala ma kota";
    char *op = "+";
    char *s2 = "4 + 3 = 7";
    char *s3 = "37/5";
    
    printf("Zad 1.1: Czy jest liczba w napisie %s (1 - tak, 0 - nie): %d\n", s, isNumber(s));
    printf("Zad 1.2: Usuwamy znaki biale z napisu \"%s\": %s\n", s1, trim(s1));
    printf("Zad 1.3: Czy jest operator %s w napisie %s (1 - tak, 0 - nie): %d\n", op, s2, getOperator(op,s2));
    printf("Zad 1.4: Czy jest napis \"%s\" ulamkiem lub liczba calkowita (1 - tak, 0 - nie): %d", s3, getFraction(s3));
    return 0;
}
