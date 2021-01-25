#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void cyfry1(int a){
	int n;
	double b;
	if (a < 0){
		b = abs(a);
	} else {
		b = a;
	}
	n = (int)log10(b);
	printf("cyfry1(%d) = %d\n", a, n+1);
}

void cyfry2(int a){
	int b;
	b = a;
	if (a < 0){
		b = abs(a);
	}
	char *s = malloc(20);
	int n = snprintf(s, 20, "%d", b);
	printf("cyfry2(%d) = %d\n", a, n);
}

void cyfry3(int a){
	int n = 0;
	int b = a;
	if (a < 0){
		b = abs(a);
	}
	while (b > 0){
		b = (int)b/10;
		n++;
	}
	printf("cyfry3(%d) = %d", a, n);
}


int main(void){
	int n = -3579;
	cyfry1(n);
	cyfry2(n);
	cyfry3(n);
}























