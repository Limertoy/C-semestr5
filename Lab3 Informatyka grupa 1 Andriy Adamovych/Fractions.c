#include <stdio.h>
#include <stdlib.h>

struct Fraction {
    int num, den;
};

/*
a/b + c/d = (a*d)/(b*d) + (c*b)/(d*b) = (a*d + c*b) / (b*d)
*/
struct Fraction sum(struct Fraction x, struct Fraction y) {
    int a = x.num;
    int b = x.den;
    
    int c = y.num;
    int d = y.den;
    
    struct Fraction z;
    
    z.num = a*d + c*b;
    z.den = b*d;
    
    return z;
}

/*
a/b - c/d = (a*d)/(b*d) - (c*b)/(d*b) = (a*d - c*b) / (b*d)
*/
struct Fraction minus(struct Fraction x, struct Fraction y){
	int a = x.num;
    int b = x.den;
    
    int c = y.num;
    int d = y.den;
    
    struct Fraction m;
    
    m.num = a*d - c*b;
    m.den = b*d;
    
    return m;
}

/*
a/b * c/d = (a*c)/(b*d)
*/
struct Fraction mnoz(struct Fraction x, struct Fraction y){
	int a = x.num;
    int b = x.den;
    
    int c = y.num;
    int d = y.den;
    
    struct Fraction mn;
    
    mn.num = a*c;
    mn.den = b*d;
    
    return mn;
}

/*
(a/b) : (c/d) = a/b * d/c = (a*d) / (b*c)
*/
struct Fraction dziel(struct Fraction x, struct Fraction y){
	int a = x.num;
    int b = x.den;
    
    int c = y.num;
    int d = y.den;
    
    struct Fraction dz;
    
    dz.num = a*d;
    dz.den = b*c;
    
    return dz;
}
void print(struct Fraction x, struct Fraction y, const char op){
	struct Fraction z = sum(x, y);
    struct Fraction m = minus(x, y);
    struct Fraction mn = mnoz(x, y);
    struct Fraction dz = dziel(x, y);
    
    switch(op){
    	case '+':
            printf("%d/%d + %d/%d = %d/%d\n", x.num, x.den, y.num, y.den, z.num, z.den); 
            break;

        case '-':
            printf("%d/%d - %d/%d = %d/%d\n", x.num, x.den, y.num, y.den, m.num, m.den);
            break;

        case '*':
            printf("%d/%d * %d/%d = %d/%d\n", x.num, x.den, y.num, y.den, mn.num, mn.den);
            break;

        case ':':
            printf("%d/%d : %d/%d = %d/%d\n", x.num, x.den, y.num, y.den, dz.num, dz.den);
            break;
        default:
            printf("%c - nieznane dzialanie.", op); 
    }
}

void printFraction(struct Fraction x){
	int a = x.num;
    int b = x.den;
    if (b == 0){
    	printf ("Frakcja %d/%d: Blad. Dzielenie na 0 niemozliwe.\n", x.num, x.den);
    } else if (a == 0){
		printf("Frakcja %d/%d: %d\n", x.num, x.den, 0);
	} else if(a == b){
		printf("Frakcja %d/%d: %d\n", x.num, x.den, 1);
	} else if (abs(a) < abs(b) && b%a!=0){
		 if (b<0) {
			b = abs(b);
			a =0-a;
		}
		printf("Frakcja %d/%d: %d/%d\n",x.num, x.den, a, b);
	} else if (abs(a) < abs(b) && b%a==0){
		if(a < b){
			int b1 = (int)b/abs(a);
			int a1 = (int)abs(a)/a;
			printf("Frakcja %d/%d: %d/%d\n",x.num, x.den, a1, b1);
		}
		else {
			int b1 = (int)abs(b)/abs(a);
			int a1 =0-(int)abs(a)/a;
			printf("Frakcja %d/%d: %d/%d\n",x.num, x.den, a1, b1);
		}
	} else if (abs(a) > abs(b) && a%b==0){
		int a1 = a/b;
		printf("Frakcja %d/%d: %d\n",x.num, x.den, a1);
	} else if(abs(a) > abs(b) && a%b!=0){
		int a1 = a/b;
		a=abs(a) - abs(a1*b);
		printf("Frakcja %d/%d: %d %d/%d\n",x.num, x.den, a1, abs(a), abs(b));
	}
}

void main() {
	struct Fraction q = {2, 0};
    struct Fraction w = {0, 2};
    struct Fraction e = {2, 2};
    struct Fraction r = {2, 4};
    struct Fraction t = {-1, 2};
    struct Fraction y = {1, -2};
    struct Fraction u = {4, -2};
    struct Fraction i = {5, -2};
    
	printFraction(q);
	printFraction(w);
	printFraction(e);
	printFraction(r);
	printFraction(t);
	printFraction(y);
	printFraction(u);
	printFraction(i);
									                                    
}


