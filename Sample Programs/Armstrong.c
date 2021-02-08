// Armstrong

#include <stdio.h>

void main () {
    int n = 371,s = 0, t, r;
    t = n;
    while(n > 0) {
        r = n % 10;
        s = s + (r * r * r);
        n = n / 10;
    }
    if(t == s)
        printf("Number is armstrong");
    else
        printf("Number is not armstrong");
    getch();
}