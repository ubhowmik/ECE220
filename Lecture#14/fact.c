#include <stdio.h>
int Factorial(int n);
//assume n is non-negative
int Factorial(int n)
{
	if(n == 0)
		return 1;
	else
		return n*Factorial(n-1);
}

int main()
{
	int n=3;
	printf("Factorial(%d)=%d \n",n,Factorial(n));

	return 0;
}

