#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

struct Fraction {
    int num, den;
};

int odczyt(char *s, struct Fraction *x){
	char ch = -1;
	int count = 0, n = 0;
	int a = 0;
	int i;
	
	char *temp = (char *)malloc(sizeof(char));
	
	while((int)ch != 0){
		ch = *(s + count * sizeof(char));
		if(ch == '/' && a == 0 && count > 0){
			count++;
			a+= 1;
			x->num = atoi(temp);
			for (i = 0; i < n; i++){
				*(temp + ((i) * sizeof(char))) = 0;
			}
			n = 0;
		} else if ((char)ch >= '0' && (char)ch <= '9') {
			*(temp + ((n) * sizeof(char))) = ch;
			count++;
			n++;
		} else if ((int)ch == 0){
			x->den = atoi(temp);
			for (i = 0; i < n; i++){
				*(temp + ((i) * sizeof(char))) = 0;
			}
			n = 0;
		} else {
			printf ("Zle napisane.");
		}
	}
	return 1;
}

char *safeReadFromConsole()
{
    unsigned int len_max = 128;
    unsigned int currentSize = 0;
    char *data = malloc(len_max);
    currentSize = len_max;

    if (data != NULL)
    {
        int c;
        unsigned int i = 0;
        while ((c = getchar()) != '\n')
        {
            data[i++] = (char)c;
            if (i == currentSize)
            {
                currentSize = i + len_max;
                data = realloc(data, currentSize);
            }
        }
        data[i] = '\0';
        return data;
    }
    return data;
}

int main(void){
	char *s1, *s2;
	s1 = malloc(20);
	s2 = malloc(20);
	struct Fraction x1, *x = &x1;
	struct Fraction y1, *y = &y1;
	printf("a/b = ");
	s1 = safeReadFromConsole();
	odczyt(s1, x);
	printf("c/d = ");
    s2 = safeReadFromConsole();
    odczyt(s2, y);
	printf("%d/%d + %d/%d", x->num, x->den, y->num, y->den);
	return 0;
}
