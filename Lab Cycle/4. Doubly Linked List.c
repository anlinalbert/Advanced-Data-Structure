// Doubly linked list

#include <stdio.h>
#include <stdlib.h>


/*
 * Basic structure of Node
 */
struct node {
    int data;
    struct node * prev;
    struct node * next;
}*head, *last;


int main() {
    int n, data, choice=1;

    head = NULL;
    last = NULL;

    while(choice != 0) {
        /*
         * Menu creation to use the program
         */
        printf("============================================\n");
        printf("            DOUBLY LINKED LIST              \n");
        printf("============================================\n");
        printf("1. Create List\n");
        printf("2. Insert node - at beginning\n");
        printf("3. Insert node - at end\n");
        printf("4. Insert node - at N\n");
        printf("5. Delete node - from beginning\n");
        printf("6. Delete node - from end\n");
        printf("7. Delete node - from N\n");
        printf("8. Display list\n");
        printf("9. Search\n");
        printf("0. Exit\n");
        printf("--------------------------------------------\n");
        printf("Enter your choice : ");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the total number of nodes in list: ");
                scanf("%d", &n);
                createList(n);
                break;
            case 2:
                printf("Enter data of first node : ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 3:
                printf("Enter data of last node : ");
                scanf("%d", &data);

                insertAtEnd(data);
                break;
            case 4:
                printf("Enter the position where you want to insert new node: ");
                scanf("%d", &n);
                printf("Enter data of %d node : ", n);
                scanf("%d", &data);
                insertAtN(data, n);
                break;
            case 5:
                deleteFromBeginning();
                break;
            case 6:
                deleteFromEnd();
                break;
            case 7:
                printf("Enter the node position which you want to delete: ");
                scanf("%d", &n);
                deleteFromN(n);
                break;
            case 8:
                displayList();
                break;
            case 9:
                search(n);
                break;
            case 0:
                break;
            default:
                printf("Error! Invalid choice. Please choose between 0-5");
        }

        printf("\n\n");
    }

    return 0;
}


void createList(int n) {
    int i, data;
    struct node *newNode;

    if(n >= 1)
    {

        head = (struct node *)malloc(sizeof(struct node));

        printf("Enter data of 1 node: ");
        scanf("%d", &data);

        head->data = data;
        head->prev = NULL;
        head->next = NULL;

        last = head;

        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            printf("Enter data of %d node: ", i);
            scanf("%d", &data);

            newNode->data = data;
            newNode->prev = last; 
            newNode->next = NULL;

            last->next = newNode; 
            last = newNode;          
        }

        printf("\nDOUBLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}

void displayList()
{
    struct node * temp;
    int n = 1;

    if(head == NULL || last == NULL) 
    {
        printf("List is empty.\n");
    }
    else
    {
        temp = head;
        printf("DATA IN THE LIST:\n");

        while(temp != NULL)
        {
            printf("DATA of %d node = %d\n", n, temp->data);

            n++;
            temp = temp->next;
        }
    }
}


void insertAtBeginning(int data)
{
    struct node * newNode;

    if(head == NULL)
    {
        printf("Error, List is Empty!\n");
    }
    else
    {
        newNode = (struct node *)malloc(sizeof(struct node));

        newNode->data = data;
        newNode->next = head;
        newNode->prev = NULL; 
        head->prev = newNode;
        head = newNode;

        printf("NODE INSERTED SUCCESSFULLY AT THE BEGINNING OF THE LIST\n");
    }
}


void insertAtEnd(int data)
{
    struct node * newNode;

    if(last == NULL)
    {
        printf("Error, List is empty!\n");
    }
    else
    {
        newNode = (struct node *)malloc(sizeof(struct node));

        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = last;

        last->next = newNode;
        last = newNode;

        printf("NODE INSERTED SUCCESSFULLY AT THE END OF LIST\n");
    }
}


void insertAtN(int data, int position)
{
    int i;
    struct node * newNode, *temp;

    if(head == NULL || last == NULL)
    {
        printf("Error, List is empty!\n");
    }
    else
    {
        temp = head;
        i=1;

        while(i<position-1 && temp!=NULL)
        {
            temp = temp->next;
            i++;
        }

        if(position == 1)
        {
            insertAtBeginning(data);
        }
        else if(temp == last)
        {
            insertAtEnd(data);
        }
        else if(temp!=NULL)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            newNode->data = data;
            newNode->next = temp->next;
            newNode->prev = temp;    

            if(temp->next != NULL)
            {
                
                temp->next->prev = newNode;
            }
          
            temp->next = newNode;

            printf("NODE INSERTED SUCCESSFULLY AT %d POSITION\n", position);
        }
        else
        {
            printf("Error, Invalid position\n");
        }
    }
}

void deleteFromBeginning()
{
    struct node * toDelete;

    if(head == NULL)
    {
        printf("Unable to delete. List is empty.\n");
    }
    else if(head == last) {
        toDelete = head;
        free(toDelete);
        head = NULL;
        last = NULL;
        printf("SUCCESSFULLY DELETED NODE FROM BEGINNING OF THE LIST.\n");
    }
    else
    {
        toDelete = head;

        head = head->next; 
        
        if (head != NULL)
            head->prev = NULL;

        free(toDelete); 
        printf("SUCCESSFULLY DELETED NODE FROM BEGINNING OF THE LIST.\n");
    }
}


void deleteFromEnd()
{
    struct node * toDelete;

    if(last == NULL)
    {
        printf("Unable to delete. List is empty.\n");
    }
    else if(head == last) {
        toDelete = head;
        free(toDelete);
        head = NULL;
        last = NULL;
        printf("SUCCESSFULLY DELETED NODE FROM END OF THE LIST.\n");
    }
    else
    {
        toDelete = last;

        last = last->prev;
        
        if (last != NULL)
            last->next = NULL;

        free(toDelete);      
        printf("SUCCESSFULLY DELETED NODE FROM END OF THE LIST.\n");
    }
}


void deleteFromN(int position)
{
    struct node *current;
    int i;

    current = head;
    for(i=1; i<position && current!=NULL; i++)
    {
        current = current->next;
    }

    if(position == 1)
    {
        deleteFromBeginning();
    }
    else if(current == last)
    {
        deleteFromEnd();
    }
    else if(current != NULL)
    {
        current->prev->next = current->next;
        current->next->prev = current->prev;

        free(current); 

        printf("SUCCESSFULLY DELETED NODE FROM %d POSITION.\n", position);
    }
    else
    {
        printf("Invalid position!\n");
    }
}

void search(n) {
    int key, c = 0;
    struct node *temp = head;

    if(head == NULL || last == NULL)
    {
        printf("List is empty.\n");
    }
    else {
        printf("\nEnter search key: ");
        scanf("%d", &key);
        while(temp != NULL) {
            if(temp -> data == key)
                c = 1;
            temp = temp -> next;
        }
        if(c)
            printf("Element found");
        else 
            printf("Element not found");
    }
}