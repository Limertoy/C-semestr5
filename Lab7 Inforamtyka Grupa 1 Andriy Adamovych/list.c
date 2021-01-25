#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){
	#ifdef _WIN32
	char command[8] = "dir";
	system(command);
	#elif __unix__
	char command[8] = "ls";
	system(command);
	#endif
}
