#include<stdio.h>
#include<stdlib.h>

int ar[10],a,b,i,j;

void create() {
    for(i = 0; i < 9; i++)
        ar[i] = i;
}

void display() {
    printf("\nData Elements:\n\n");
    for(i = 0; i < 9; i++)
        printf("\t%d[%d]", i, ar[i]);
    printf("\n");
}

void unionop() {
    int t,m;

    while(1) {
        a = 0;
        b = 0;

        printf("\nEnter the parent: ");
        scanf("%d",&b);
        printf("Enter the element: ");
        scanf("%d",&a);

        if((a >= 0) && (a < 9) && (b >= 0) && (b < 9))
           break;
        else
            printf("Invalid data");

    }

    int temp = ar[a];
    for(i = 0; i < 9; i++)
        if(ar[i] == temp)
            ar[i] = ar[b];

    display();
}

void find() {
    while(1) {
        a = 0;
        b = 0;
        printf("\nEnter the element 1: ");
        scanf("%d",&a);
        printf("Enter the element 2: ");
        scanf("%d",&b);

        if((a >= 0) && (a < 9) && (b >= 0) && (b < 9))
           break;
        else
            printf("Result: Invalid data\n");
    }

    if(ar[a] == ar[b])
        printf("Result: True\n");
    else
        printf("Result: Absent\n");
}

void main() {
    int ch;

    create();
    display();

    while(1) {
        printf("\n1.Union\n2.Find\n3.Display\n4.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch) {
            case 1: unionop();
                break;
            case 2: find();
                break;
            case 3: display();
                break;
            case 4: exit(0);
            default : printf("\nInvalid input - try again.\n");
        }
    }
}