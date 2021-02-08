// Largest array

#include <stdio.h>

void main() {
    int a[5] = {54, 34, 23, 56, 12}, l = a[0];
    for(int i = 1; i < 5; i++) {
        if(a[i] > l)
            l = a[i];
    }
    printf("Largest = %d", l);
    getch();
}