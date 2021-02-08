// Lower case to upper case

#include <stdio.h>

void main() {
    char a[] = "hello", s[20];
    for (int i = 0; a[i]!='\0'; i++) {
        if(a[i] >= 'a' && a[i] <= 'z') 
            s[i] = a[i] - 32;
    }
    printf("Upper case : %s", s);
    getch();
}