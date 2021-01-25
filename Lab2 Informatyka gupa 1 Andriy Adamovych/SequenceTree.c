#include <stdio.h>
#include <math.h>

//Zadanie 1
int a1(int a){
	int b = 0;
	if (a == 1 || a == 0){
		printf("a(%d) = 1 \n", a);
		return 1;
	} else {
		b = a1(a-2)+a1(a-1);
		printf("a(%d) = %d \n", a, b);
		return b;
	}
	
}

	
int main(void){
	int x;
	printf("Podaj indeks ciagu: ");
	scanf("%d", &x);
	printf("-----Wynik:------\n");
	printf("Wynik koncowy: %d", a1(x));
}
