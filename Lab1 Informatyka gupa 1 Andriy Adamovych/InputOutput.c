#include <stdio.h>

int main (void)
{
	//Zadanie 1
	int a;
	float b;
	char c[32];
	printf("Podaj zmienna calkowita: "); 
	scanf("%d", &a);
	printf("Podaj zmienna z przecinkiem: ");
	scanf("%f", &b);
	printf("Podaj napis: ");
	scanf("%s", c);
	printf("--------Wynik:--------\n");
	printf("%d\n", a);
	printf("%5.3f\n", b);
	printf("%s\n", c);
	
	//Zadanie 1.1
	/*
	double x;
	printf("Podaj zmienna z przecinkiem: ");
	scanf("%lf", &x);
	printf("--------Wynik:--------\n");
	printf("%5.3lf", x);
	*/
	
	//Zadanie 1.2
	/*
	char c[32];
	printf("Podaj napis: ");
	scanf("%[^\n]", c);
	printf("--------Wynik:--------\n");
	printf("%s\n", c);
	*/
	
	//Zadanie 1.3
	/*
	char c[32];
	printf("Podaj napis: ");
	fgets(c, 32, stdin);
	printf("--------Wynik:--------\n");
	printf("%s\n", c);
	*/	
}
