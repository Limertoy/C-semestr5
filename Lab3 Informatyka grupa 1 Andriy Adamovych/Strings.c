#include <stdio.h>
#include <math.h>


int indexOf(const char *str, int c) {
    char* ptr = strchr(str, c);
    if (ptr == NULL) return -1;
    int index = ptr - str;
    return index;   
}

char *identity(const char *name, const char *surname){
	int counter = 0;
	int size = 0;
	char character;
	int i = 0;
	char *identity = (char *) malloc(sizeof(char));
	for (i; i < 2; i++){
		counter = 0;
		character = -1;
		while ((int)character != 0){
			if (i == 0){
				character = *(name+counter*sizeof(char));
			} else {
				character = *(surname+counter*sizeof(char));
			}
			size++;
			identity = (char *) realloc(identity, size*sizeof(char));
			char *test = (char *) realloc(identity, size*sizeof(char));
			*(identity+((size-1)*sizeof(char))) = character;
			counter++;
		}
	}
	
	return identity;
}

int main(void){
	char c = '$';
    char *str = "99$ ";
   	
   	char *name = "Andriy";
   	char *surname = "Adamovych";
   	
    printf("indexOf(\"%s\", %c) = %d\n", str, c, indexOf(str, c));
    printf("%s", identity(name, surname));
    return 0;
}
