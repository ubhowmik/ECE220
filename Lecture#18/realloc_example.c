#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char *p1;
    int m1, m2;
    m1 = 10;
    m2 = 20;
    p1 = (char*)malloc(m1);
    strcpy(p1, "Codesdope");
    p1 = (char*)realloc(p1, m2);
    strcat(p1, "Practice");
    printf("%s\n", p1);
    return 0;
}