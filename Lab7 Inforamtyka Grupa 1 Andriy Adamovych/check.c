#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){
	#ifdef _WIN32
	printf("Program compiled on: Windows");
	#elif __unix__
	printf("Program compiled on: Linux");
	#endif
}
