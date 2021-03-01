#include<stdio.h>
#include<conio.h>

int bu[10],ba[10],bb[10];

void convertion(int u[],int a[],int b[]);
void unionop();
void intersection();
void difference();

void main() {
    int u[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int a[10]={3, 5, 7, 9};
    int b[10]={1, 2, 5, 7, 8, 9};

    convertion(u,a,b);
    unionop();
    intersection();
    difference();

    getch();
}

void convertion(int u[], int a[], int b[]) {
    int i = 0, j = 0;

    printf("Values: ");
    for(i = 0; i < 10; i++) {
       printf("%d ", u[i]);
       bu[i] = 1;
    }
    printf("\nA: ");

    for(i = 0; i < 10; i++) {
        printf("%d ", a[i]);
        for (j = 0; j < 10; j++) {
            if(u[i] == a[j]) {
                ba[i] = 1;
                break;
            } else
                ba[i] = 0;
        }
    }

    printf("\nB: ");
    for(i = 0; i < 10; i++) {
        printf("%d ", b[i]);
        for(j = 0; j < 10; j++) {
            if(u[i] == b[j]) {
                bb[i] = 1;
                break;
            } else
                bb[i] = 0;
        }
    }

    printf("\n\nUniversal set: ");

    for(i = 0; i < 10; i++)
        printf("%d", bu[i]);

    printf("\nSet A: ");

    for(i = 0; i < 10; i++)
        printf("%d", ba[i]);

    printf("\nSet B: ");

    for(i = 0; i < 10; i++)
        printf("%d", bb[i]);
}

void unionop() {
    int m[10], i, j;

    for(i = 0; i < 10; i++)
       m[i] = 0;

    printf("\n\nUnion: ");
    
    for(i = 0; i < 10; i++) {
        if(bu[i] == ba[i] || bu[i] == bb[i])
            m[i] = 1;
    }
    for(i = 0; i < 10; i++)
        printf("%d", m[i]);
}

void intersection() {
    int m[10], i, j;

    for(i = 0; i < 10; i++)
       m[i] = 0;

    printf("\nIntersection: ");

    for(i = 0; i < 10; i++) {
        if(bu[i] == ba[i] && bu[i] == bb[i])
            m[i] = 1;
    }

    for(i = 0; i < 10; i++)
        printf("%d", m[i]);
}

void difference() {
    int m[10], i, j;
    
    for(i = 0; i < 10; i++)
       m[i] = 0;

    for(i = 0; i < 10; i++) {
        if(ba[i] == 1 && ba[i] != bb[i])
            m[i] = 1;
    }

    printf("\nDifference: ");
    for(i = 0; i < 10; i++)
        printf("%d", m[i]);
}