// Array sum

#include <stdio.h>

void main() {
    int a[5] = {24, 414, 13, 54, 28}, b[5] = {54, 74, 27, 31, 67}, s[5]; 
    printf("Array sum: \n");
    for(int i = 0; i < 5; i++) {
        s[i] = a[i] + b[i];
        printf("%d\n", s[i]);
    }
    getch();
}