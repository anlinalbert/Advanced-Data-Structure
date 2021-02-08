// Lower case to upper case

#include <stdio.h>

void main() {
    char a[] = "HELLO", s[20];
    for (int i = 0; a[i]!='\0'; i++) {
        if(a[i] >= 'A' && a[i] <= 'Z') 
            s[i] = a[i] + 32;
    }
    printf("Lower case : %s", s);
    getch();
}