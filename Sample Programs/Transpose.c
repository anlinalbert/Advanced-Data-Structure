// Transpose matrix

#include <stdio.h>

void main() {
    int a[2][2] = { {1, 2}, {5, 6} };
    printf("Initial Matrix:\n");
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) 
            printf("%d ", a[i][j]);
        printf("\n");
    }
    printf("\nTranspose:\n");
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) 
        printf("%d ", a[j][i]);
        printf("\n");
    }
    getch();
}