#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){
	char *a;
	a = strrchr(argv[0], '\\');
	printf("argc = %d\n", argc);
	printf("addr: %s\n", argv[0]);
	#ifdef linux
        #include<libgen.h>
        printf("%s\n\n",basename(argv[0]));
	#else
		printf("name: %s\n", ++a);
	#endif
		printf("params: ");
    int i;
    for (i = 1; i < argc; i++) {
        printf("%s \n",argv[i]);
    }

}
