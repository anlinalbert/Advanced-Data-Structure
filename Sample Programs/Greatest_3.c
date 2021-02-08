// Greatest of three nos, conditional operator

#include <stdio.h>

void main() {
    int a = 10, b = 35, c = 50;
    int big = a > b ? (a > c ? a : c) : (b > c ? b : c);
    printf("The greatest no is %d", big);
    getch();
}