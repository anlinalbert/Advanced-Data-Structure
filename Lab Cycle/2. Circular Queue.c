// Circular queue

#include <stdio.h>
#define size 5

int front =  - 1;
int rear =  - 1;

int main() {
    int n, ch;
    int queue[size];
    do {
        printf("\n============================================\n");
        printf("                CIRCULAR QUEUE\n");
        printf("============================================\n");
        printf("1. Insert \n2. Delete\n3. Display\n4. Search\n0. Exit");
        printf("\nEnter Choice 0-4? : ");
        scanf("%d", &ch);
        switch (ch) {
            case 0:
                exit(0);
            case 1:
                printf("\nEnter number: ");
                scanf("%d", &n);
                insertq(queue, n);
                break;
            case 2:
                deleteq(queue);
                break;
            case 3:
                display(queue);
                break;
            case 4:
                searchq(queue);
                break;
            default:
                printf("\nEnter a valid option");
        }
    } while (ch);
}


void insertq(int queue[], int item) {
    if ((front == 0 && rear == size - 1) || (front == rear + 1)) {
        printf("queue is full");
        return;
    } else if (rear ==  - 1) {
        rear++;
        front++;
    } else if (rear == size - 1 && front > 0)
        rear = 0;
    else
        rear++;
    queue[rear] = item;
}

void display(int queue[]) {
    int i;
    if (front ==  - 1)
        printf("\nQueue is empty\n");
    else {
        printf("\nQueue Elements:\n");
        if (front > rear) {
            for (i = front; i < size; i++)
                printf("%d ", queue[i]);
            for (i = 0; i <= rear; i++)
                printf("%d ", queue[i]);
        } else
            for (i = front; i <= rear; i++)
                printf("%d ", queue[i]);
        printf("\n");
    }
}

void deleteq(int queue[]) {
    if (front ==  - 1)
        printf("Queue is empty ");
    else if (front == rear) {
        printf("\n %d deleted", queue[front]);
        front =  - 1;
        rear =  - 1;
    } else {
        printf("\n %d deleted", queue[front]);
        front++;
    }
}

void searchq(int queue[]) {
    int key, c = 0;
    printf("\nEnter the search element: ");
    scanf("%d", &key);
    for(int i = 0; i < size; i++) {
        if (front ==  - 1) {
            c = 2;
            break;
        } else if(queue[i] == key)
            c = 1;
    }
    if(c == 1)
        printf("Element found\n");
    else if(c == 0)
        printf("Element not found\n");
    else
        printf("Queue Empty\n");
}