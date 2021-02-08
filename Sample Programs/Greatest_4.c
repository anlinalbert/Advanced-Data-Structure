// Greatest of three nos, ifelse

#include <stdio.h>

void main() {
    int a = 45, b = 12, c = 41;
    if(a > b && a > c)
        printf("A is greater");
    else if(b > a && b > c)
        printf("B is greater");
    else
        printf("C is greater");
    getch();
}