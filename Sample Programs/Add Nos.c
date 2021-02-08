// Add two integer constants

#include <stdio.h>

void main() {
    int a, b, sum;
    printf("Enter two nos\nNumber 1 : ");
    scanf("%d", &a);
    printf("Number 2 : ");
    scanf("%d", &b);
    sum = a + b;
    printf("\nSum = %d", sum);
    getch();
}