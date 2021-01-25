#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int indexOf(const char *str, int c) {
    char* ptr = strchr(str, c);
    if (ptr == NULL){
		return -1;
    } 
    int index = ptr - str;
    return index;   
}

char *identity(const char *name, const char *surname){
	int	n = 0, i, count;
	char ch;
	char a = 0;
	
	char *iden = (char *)malloc(sizeof(char));
	for (i = 0; i < 2; i++){
		count = 0;
		ch = -1;
		while((int)ch != 0){
			if(i == 0){
				ch = *(name + count * sizeof(char));
			} else {
				ch = *(surname + count * sizeof(char));
			}
			n++;
			*(iden + ((n-1) * sizeof(char))) = ch;
			count++;
			}
		if(i == 0){
			*(iden + ((n-1) * sizeof(char))) = ' ';
		}
	}

   	return iden;
}

char *login(const char *name, const char *surname){
	int n = 0;
   	char ch = -1;
   	char a = 0;

   	char *log = (char *)malloc(sizeof(char) * 32);
   	a = (char)*name;
   	if(a >= 'A' && a <= 'Z'){
   		*log =	(char)(a + 32);
   	} else {
   		*log = a;
   	}
	while ((int)ch != 0 || n > 32){
		a = (char)*(surname + n * sizeof(char));
		if(a >= 'A' && a <= 'Z'){
			ch = (char)(a + 32);
		} else {
			ch = a;
		}
       	n++;
       	*(log + ((n) * sizeof(char))) = ch;
   	}

   	return log;
}


int main(){
	char c = '$';
    char *str = "99$ ";
   	char *name = "Andriy";
   	char *surname = "Adamovych";
    
	printf("Zad 3.1: indexOf(\"%s\", %c) = %d\n", str, c, indexOf(str, c));
    printf("Zad 3.2: Identity: %s\n", identity(name, surname));
    printf("Zad 3.3: Login: %s", login(name, surname));
}







