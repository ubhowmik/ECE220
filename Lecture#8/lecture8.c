#include <stdio.h>

/* use nested for loops to print an n x n identity matrix */

int main(){
   int i, j, n=0;

   printf("Enter a number for nxn matrix size: ");
   scanf("%d", &n);

   printf("Output Identity Matrix: \n");

   for (i = 0; i < n; i++){
	for (j = 0; j < n; j++){
		if(i == j)
		   printf("1");
		else
		   printf("0");
	}
	printf("\n");
   }

   return 0;
}

//What are some ways to stop printing after the second "1" on the main diagonal, such as shown below?
//100
//01


