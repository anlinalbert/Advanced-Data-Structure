// Sort array

#include <stdio.h>

void main() {
    int n[5] = {59, 75, 1, 15, 40}, a;
    for (int i = 0; i < 5; ++i)
        for (int j = i + 1; j < 5; ++j) {
             if (n[i] > n[j]) {
                a =  n[i];
                n[i] = n[j];
                n[j] = a;
            }
        }
    printf("The numbers arranged in ascending order are given below \n");
    for (int i = 0; i < 5; ++i)
        printf("%d\n", n[i]);
    getch();
}