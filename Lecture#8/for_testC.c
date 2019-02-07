#include <stdio.h>

int main ()
{
	int x;
	int sum=0;
	for (x=0; x<10; ++x)

{
	int y=++x;
	sum = sum+y;
	
	printf("sum = %d\n", sum);
	printf("y = %d\n", y);
	printf ("x = %d\n\n", x);
}

return 0;
}