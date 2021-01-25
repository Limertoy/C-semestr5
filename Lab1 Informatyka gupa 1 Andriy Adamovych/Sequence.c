#include <stdio.h>
#include <math.h>

//Zadanie 3

//Zadanie 3.1
double a(int n){
	 if(n == 0){
	 	return 1;
	 } else if (n == 1){
	 	return 4;
	 } else {
	 	return 2*a(n-1) + 0.5*a(n-2);
	 }
}

int main(void){
	int x;
	printf("Podaj indeks ciagu: ");
	scanf("%d", &x);
	printf("-----Wynik:------\n");
	printf("Wartosc ciagu: %5.3lf", a(x));
}
