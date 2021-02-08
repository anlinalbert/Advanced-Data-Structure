// Elements in arrays

#include <stdio.h>

void main() {
    int a[] = {321, 31, 3, 13, 44, 41, 54, 341};
    int l = sizeof(a) / sizeof(a[0]);
    printf("Length = %d", l);
    getch();
}