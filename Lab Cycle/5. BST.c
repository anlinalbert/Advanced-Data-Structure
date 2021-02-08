#include<stdio.h>
#include<stdlib.h>

struct tree {
    int info;
    struct tree *left;
    struct tree *right; 
};

struct tree *insert(struct tree *,int);
void inorder(struct tree *);
void postorder(struct tree *);
void preorder(struct tree *);
struct tree *delet(struct tree *,int);
struct tree *search(struct tree *);

int main(void) {
    struct tree *root;
    int choice, item,item_no;
    root = NULL;
    printf("============================================\n");
    printf("             BINARY SEARCH TREE             \n");
    printf("============================================\n");

    do {
        do {
            printf("\n1. INSERTION ");
            printf("\n2. DELETION ");
            printf("\n3. INORDER TRAVERSAL");
            printf("\n4. POSTORDER TRAVERSAL");
            printf("\n5. PREORDER TRAVERSAL");
            printf("\n6. SEARCH");
            printf("\n7. EXIT ");
            printf("\n\n ENTER YOUR CHOICE : ");
            
            scanf(" %d",&choice);
            if(choice<1 || choice>7)
                printf("\n INVALID CHOICE - TRY AGAIN \n");
        } while (choice<1 || choice>7);
        
        switch(choice) {
            case 1:
                printf("\n ENTER NEW ELEMENT: ");
                scanf("%d", &item);
                root= insert(root,item);
                printf("\n ROOT NODE : %d\n",root->info);
                printf("\n UPDATED BINARY TREE (INORDER TRAVERSAL): ");
                inorder(root);
                printf("\n");
                break;

            case 2:
                printf("\n ENTER THE ELEMENT TO BE DELETED : ");
                scanf(" %d",&item_no);
                root=delet(root,item_no);
                printf("\n ROOT NODE : %d\n",root->info);
                printf("\n UPDATED BINARY TREE (INORDER TRAVERSAL): ");
                inorder(root);
                printf("\n");
                break;

            case 3:
                printf("\n INORDER TRAVERSAL OF BINARY TREE: ");
                inorder(root);
                printf("\n");
                break;

            case 4:
                printf("\n POSTORDER TRAVERSAL OF BINARY TREE: ");
                postorder(root);
                printf("\n");
                break;

            case 5:
                printf("\n PREORDER TRAVERSAL OF BINARY TREE: ");
                preorder(root);
                printf("\n");
                break;

            case 6:
                root=search(root);
                printf("\n");
                break;

            default:
                printf("\n\t\t\tEND OF PROGRAM \n");
        }
    } while(choice !=7);
    return(0);
}

// to insert elements
struct tree *insert(struct tree *root, int x) {
    if(!root) {
        root=(struct tree*)malloc(sizeof(struct tree));
        root->info = x;
        root->left = NULL;
        root->right = NULL;
        return(root);
    }

    if(root->info > x)
        root->left = insert(root->left,x);

    else {
        if(root->info < x)
        root->right = insert(root->right,x);
    }
    return(root);
}

// inorder traversal
void inorder(struct tree *root) {
    if(root != NULL) {
        inorder(root->left);
        printf(" %d",root->info);
        inorder(root->right);
    }
    return;
}

// post order traversal
void postorder(struct tree *root) {
    if(root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf(" %d",root->info);
    }
    return;
}

// pre order traversal
void preorder(struct tree *root) {
    if(root != NULL) {
        printf(" %d",root->info);
        preorder(root->left);
        preorder(root->right);
    }
    return;
}

// to delete node
struct tree *delet(struct tree *ptr,int x) {
    struct tree *p1,*p2;

    if(!ptr) {
        printf("\n ELEMENT NOT FOUND \n");
        return(ptr);
    }

    else {
            if(ptr->info < x) {
                ptr->right = delet(ptr->right,x);
            }

        else if (ptr->info >x) {
            ptr->left=delet(ptr->left,x);
            return ptr;
        }

        else  {
            if(ptr->info == x) {
                if(ptr->left == ptr->right) {
                    free(ptr);
                    return(NULL);
                }

                else if(ptr->left==NULL) {
                    p1=ptr->right;
                    free(ptr);
                    return p1;
                }   

                else if(ptr->right==NULL) {
                    p1=ptr->left;
                    free(ptr);
                    return p1;
                }

                else {
                    p1=ptr->right;
                    p2=ptr->right;

                    while(p1->left != NULL)
                    p1=p1->left;
                    p1->left=ptr->left;

                    free(ptr);
                    return p2;
                }
            }
        }
    }
    return(ptr);
}

// to search element
struct tree *search(struct tree *root) {
    int no,i,ino;
    struct tree *ptr;
    ptr=root;

    printf("\n ENTER THE ELEMENT TO BE SEARCHED : ");
    scanf(" %d",&no);
    fflush(stdin);

    while(ptr) {
        if(no>ptr->info)
        ptr=ptr->right;

        else if(no<ptr->info)
            ptr=ptr->left;
            else break;
    }

    if(ptr) {
        printf("\n ELEMENT %d WAS FOUND ",no);
    }

    else
        printf("\n ELEMENT %d DOES NOT EXIST IN THE BINARY TREE \n",no);
    return(root);
}