// Matrix operations 

#include <stdio.h>

void main() {
    int a[2][2] = { {51, 32}, {32, 45} }, b[2][2] = { {63, 46}, {34, 62} }, s[2][2], n[2][2], m[2][2];
    for(int i = 0; i < 2; i++) 
        for(int j = 0; j < 2; j++) {
            s[i][j] = a[i][j] + b[i][j];
            n[i][j] = a[i][j] - b[i][j];
            m[i][j] = a[i][j] * b[i][j];
        }
    printf("After addition: \n");
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++)
            printf("%d ", s[i][j]);
        printf("\n");
    }
    printf("\nArray substraction: \n");
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++)
            printf("%d ", n[i][j]);
        printf("\n");
    }
    printf("\nProduct: \n");
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++)
            printf("%d ", m[i][j]);
        printf("\n");
    }
    getch();
}