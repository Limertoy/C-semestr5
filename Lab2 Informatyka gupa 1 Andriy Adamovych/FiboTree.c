#include <stdio.h>
#include <math.h>

//Zadanie 1
int fibo1(int a){
	int b = 0, i = 0;
	if (a == 1 || a == 0){
		i = i + 1;
		printf("fibo%d(%d) = 1 \n", i, a);
		return 1;
	} else {
		i = i + 1;
		b = fibo1(a-2)+fibo1(a-1);
		printf("fibo%d(%d) = %d \n", i, a, b);
		return b;
	}
	
}

	
int main(void){
	int x;
	printf("Podaj indeks ciagu: ");
	scanf("%d", &x);
	printf("-----Wynik:------\n");
	printf("Wynik koncowy: %d", fibo1(x));
}
