// String length without function

#include <stdio.h>

void main() {
    int i;
    char a[] = "Hello";
    for(i = 0; a[i]!='\0'; i++);
    printf("Length = %d", i);
}