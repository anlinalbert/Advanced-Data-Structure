#include<stdio.h>  
#include<conio.h>  
#include<stdlib.h>

int unions(int[],int[],int[],int,int);  
int input(int[]);  
int intersection(int[],int[],int[],int,int);  
int difference(int[],int[],int[],int,int);  
void display(int[],int);  
int find(int[], int[], int, int, int);

void main() {  
    int set1[20], set2[20], set3[40], s1=0, s2=0, s3, ch, ch1, ch2, a, b; 
    int n, choice = 1;

    while(choice != 0) {
        printf("\n============================================\n");
        printf("               DISJOINED SET OPS              \n");
        printf("============================================\n");
        printf("1. Input\n");
        printf("2. Union\n");
        printf("3. Intersection\n");
        printf("4. Difference\n");
        printf("5. Find\n");
        printf("6. Display\n");
        printf("0. Exit\n");
        printf("--------------------------------------------\n");
        printf("Enter your choice : ");

        scanf("%d", &choice);

        switch (choice) {
            case 1 :
                printf("Enter set 1:\n");
                s1 = input(set1);
                printf("\nEnter set 2:\n");
                s2 = input(set2);
                break;

            case 2 :
                if(s1==0 &&s2==0)  
                    printf("\n\n\t\tU HAVE TO ENTER SET FIRST"); 
                else {
                    s3 = unions(set1, set2, set3, s1, s2);
                    display(set3,s3);
                }
                break;

            case 3 :
                if(s1==0 &&s2==0)  
                    printf("\n\n\t\tU HAVE TO ENTER SET FIRST");  
                else {  
                    s3=intersection(set1,set2,set3,s1,s2);  
                    display(set3,s3);  
                }  
                break;  

            case 4 :
                if(s1==0 &&s2==0)  
                    printf("\n\n\t\tU HAVE TO ENTER SET FIRST"); 
                else {
                    printf("\tA - B\n");
                    s3=difference(set1,set2,set3,s1,s2);  
                    display(set3,s3);   
                    printf("\n\n\tB - A\n");
                    s3=difference(set2,set1,set3,s2,s1);  
                    display(set3,s3);  
                }
                break;

            case 5 :
                if(s1==0 &&s2==0)  
                    printf("\n\n\t\tU HAVE TO ENTER SET FIRST"); 
                else {
                    printf("Enter the first element: ");
                    scanf("%d", &a);
                    printf("Enter the second element: ");
                    scanf("%d", &b);
                    if(find(set1, set2, s1, s2, a) == find(set1, set2, s1, s2, b))
                        printf("\nThe elements are in the same set.\n");
                    else
                        printf("\nThe elements are not in the same set.\n");
                }
                break;  
            
            case 6 :
                if(s1==0 &&s2==0)  
                    printf("\n\n\t\tU HAVE TO ENTER SET FIRST"); 
                else {
                    display(set1,s1);
                    display(set2,s2);
                }
                break;

            default:
                printf("Enter a valid input");
        }
    }
}


/*****************************************************  
                    INPUT FUNCTION  
*****************************************************/  
int input(int set[])  {  
    int i=0,j,s;  
    printf("\nENTER THE SIZE OF THE SET : ");  
    scanf("%d",&s);  
    printf("\nENTER THE SET\n");  
    while(i<s) {  
        scanf("%d",&set[i]);  
        for(j=0;j<i;j++) {
            if(set[i]==set[j])  {  
                printf("\n\n!!!! DUPLICATED ENTRY !!!!\n\n");  
                printf("----------: ENTER AGAIN");  
                break;  
            } 
        } 
        if(i==j)  
            i++;  
    }  
    return s;  
}  

/*********************************************************  
                    UNION FUNCTION  
*********************************************************/  
int unions(int set1[],int set2[],int set3[],int s1,int s2) {  
    int s3,i,j;  
    for(i=0;i<s1;i++)  
        set3[i]=set1[i];  
    s3=i;  
    for(i=0;i<s2;i++) {  
        for(j=0;j<s1;j++) {
            if(set1[j]==set2[i])  
            break;  
        }
        if(j==s1)  
            set3[s3++]=set2[i];  
    }  
    return s3;  
}  

/*************************************************************  
                INTERSECTION FUNCTION  
***************************************************************/  
int intersection(int set1[],int set2[],int set3[],int s1,int s2) {  
    int i,j,s3=0;  
    for(i=0;i<s1;i++) {  
        for(j=0;j<s2;j++)  
            if(set1[i]==set2[j]) {  
                set3[s3++]=set1[i];  
                break;  
            } 
    }  
    return s3;  
}  

/****************************************************************  
                    DIFFERENCE FUNCTION  
******************************************************************/  
int difference(int set1[],int set2[],int set3[],int s1,int s2) {  
    int i,j,s3=0;  
    for(i=0;i<s1;i++) {  
        for(j=0;j<s2;j++)  
            if(set1[i]==set2[j])  
                break;  
            if(j==s2)  
            set3[s3++]=set1[i];  
    }  
    return s3;  
}  

/*********************************************************  
                    FIND FUNCTION  
**********************************************************/  
int find(int set1[], int set2[], int s1, int s2, int x) {
    int c = 0;

    for(int i = 0; i < s1; i++)
        if(set1[i] == x)
            c = 1;
    
    for(int i = 0; i < s2; i++)
        if(set2[i] == x)
            c = 2;

    return c;
}

/*********************************************************  
                    DISPLAY FUNCTION  
**********************************************************/  
void display(int set[],int size) {  
    int i;  
    printf("\n\n\t{ ");  
    for(i=0;i<size;i++)  
        printf("\t%d",set[i]);  
    printf("\t} ");  
    getch();  
}  