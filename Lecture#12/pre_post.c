// C Program to demonstrate the working of increment and decrement operators
#include <stdio.h>
int main()
{
    int a = 10, b = 100;
    float c = 10.5, d = 100.5;
// pre_increment Testing
printf("pre-Increment:\n");
    printf("++a = %d \n", ++a);

    printf("--b = %d \n", --b);

    printf("++c = %f \n", ++c);

    printf("--d = %f \n", --d);

// post_increment
a = 10, b = 100;
c = 10.5, d = 100.5;
printf("post-Increment:\n");
	printf("a++ = %d \n", a++);

    printf("b-- = %d \n", b--);

    printf("c++ = %f \n", c++);

    printf("d-- = %f \n", d--);

    return 0;
}