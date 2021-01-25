#include <stdio.h>
#include <math.h>

//Zadanie 2
	
//Zadanie 2.1
/*
int fibo1(int a){
	if (a == 1 || a == 0){
		return 1;
	} else {
		return fibo1(a-1)+fibo1(a-2);
	}
}
*/

//Zadanie 2.2

int fibo2(int a){
	int r0 = 0;
	int r1 = 1;
	int i;
	int tab[a];
	tab[0] = 1;
	for(i = 0; i <= a; i++){
		int r2 = r1 + r0;
		r0 = r1;
		r1 = r2;
		tab[i+1] = r2;
	}
	return tab[a];
}


//Zadanie 2.3
/*
int fibo3(int a){
	int pom = 0;
	int i, r0, r1;
	int tab[a];
	tab[0] = 1;
	for (i = 0; i <= a; i++){
		r0 = tab[i];
		r1 = r0 + pom;
		pom = r0;
		tab[i+1] = r1;
	}
	return tab[a];
}
*/
	
int main(){
	int x;
	printf("Podaj indeks ciagu: ");
	scanf("%d", &x);
	printf("-----Wynik:------\n");
	printf("Wartosc ciagu: %d", fibo2(x));
}
	
	

