#include <stdio.h>

#define DEBUG 1

int main(){
	#ifdef DEBUG
		printf("Debug is ON\n");
		printf("Hi friends!\n");
	#else
		printf("Debug is OFF\n");
	#endif
	return 0;
}
