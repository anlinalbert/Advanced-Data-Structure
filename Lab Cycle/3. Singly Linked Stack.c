// Stack using singly linked list

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>     

#define CAPACITY 10000  // Stack maximum capacity

// Define stack node structure
struct stack {
    int data;
    struct stack *next;
} *top;

// Stack size
int size = 0;

int main() {
    int choice, data;

    while(1) {
        /* Menu */
        printf("------------------------------------\n");
        printf("    STACK IMPLEMENTATION PROGRAM    \n");
        printf("------------------------------------\n");
        printf("1. Push\n");
        printf("2. Pop\n");;
        printf("3. Display\n");
        printf("4. Search\n");
        printf("0. Exit\n");
        printf("------------------------------------\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch(choice) {
            case 0: 
                printf("Exiting.\n");
                exit(0);
                break;

            case 1: 
                printf("Enter data to push into stack: ");
                scanf("%d", &data);
                
                // Push element to stack
                push(data);
                break;

            case 2: 
                data = pop();

                // If stack is not empty
                if (data != INT_MIN)
                    printf("Data => %d\n", data);
                break;
            
            case 3: 
                display();
                break;

            case 4: 
                search();
                break;

            default: 
                printf("Invalid choice, please try again.\n");
        }

        printf("\n\n");
    }


    return 0;
}

/**
 * Functiont to push a new element in stack.
 */
void push(int element) {
    // Check stack overflow
    if (size >= CAPACITY) {
        printf("Stack Overflow, can't add more element to stack.\n");
        return;
    }
    struct stack * newNode = (struct stack *) malloc(sizeof(struct stack));
    newNode->data = element;
    newNode->next = top;        
    top = newNode;
    size++;
    printf("Data pushed to stack.\n");
}


/**
 * Function to pop element from top of stack.
 */
int pop() {
    int data = 0;
    struct stack * topNode;
    
    // Check stack underflow
    if (size <= 0 || !top) {
        printf("Stack is empty.\n");
        return INT_MIN;
    }
    topNode = top;
    data = top->data;
    top = top->next;
    free(topNode);
    size--;

    return data;
}

/**
* Function to display elements of the stack.
*/
void display() {
    struct stack *temp = top;

    if (size <= 0 || !top)
        printf("Stack is empty.\n");
    else {
        while(temp->next) {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
        printf("%d--->NULL", temp->data);
    }
}

/**
* Function to search elements of the stack.
*/
void search() {
    int key, c = 0;
    struct stack *temp = top;

    printf("\nEnter the search key: ");
    scanf("%d", &key);

    if (size <= 0 || !top)
        c = 2;
    else {
        while(temp) {
            if(temp -> data == key)
                c = 1;
            temp = temp->next;
        }
        if(c == 2) 
            printf("Stack is empty.\n");
        else if(c == 1)
            printf("Element found.\n");
        else
            printf("Element not found.\n");
    }
}