// Implementing Binary Tree in C

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct tree
{
    int info;
    struct tree *left;
    struct tree *right;
};
struct tree *insert(struct tree *, int);
void inorder(struct tree *);
void postorder(struct tree *);
void preorder(struct tree *);
struct tree *delet(struct tree *, int);
struct tree *search(struct tree *);
int main(void)
{
    struct tree *root;
    int choice, item, item_no;
    root = NULL;

    /* rear  = NULL;*/
    do
    {
        do
        {
            printf("\n1. Insert in Binary Tree  ");
            printf("\n2. Delete from Binary Tree ");
            printf("\n3. Inorder traversal of Binary tree");
            printf("\n4. Postorder traversal of Binary tree");
            printf("\n5. Preorder traversal of Binary tree");
            printf("\n6. Search and replace ");
            printf("\n7. Exit ");
            printf("\nEnter choice : ");
            scanf(" %d", &choice);
            if (choice < 1 || choice > 7)
                printf("\nInvalid choice - try again\n");
        } while (choice < 1 || choice > 7);
        switch (choice)
        {
        case 1:
            printf("\nEnter new element: ");
            scanf("%d", &item);
            root = insert(root, item);
            printf("\nRoot is %d", root->info);
            printf("\nInorder traversal of binary tree is : ");
            inorder(root);
            printf("\n");
            break;
        case 2:
            printf("\nEnter the element to be deleted : ");
            scanf(" %d", &item_no);
            root = delet(root, item_no);
            inorder(root);
            printf("\n");
            break;
        case 3:
            printf("\nInorder traversal of binary tree is : ");
            inorder(root);
            printf("\n");
            break;
        case 4:
            printf("\nPostorder traversal of binary tree is : ");
            postorder(root);
            printf("\n");
            break;
        case 5:
            printf("\nPreorder traversal of binary tree is : ");
            preorder(root);
            printf("\n");
            break;
        case 6:
            printf("\nSearch and replace operation in binary tree ");
            root = search(root);
            printf("\n");
            break;
        default:
            printf("\nEnd of program ");
        }
        /* end of switch */
    } while (choice != 7);
    return (0);
}
struct tree *insert(struct tree *root, int x)
{
    if (!root)
    {
        root = (struct tree *)malloc(sizeof(struct tree));
        root->info = x;
        root->left = NULL;
        root->right = NULL;
        return (root);
    }
    if (root->info > x)
        root->left = insert(root->left, x);
    else
    {
        if (root->info < x)
            root->right = insert(root->right, x);
    }
    return (root);
}
void inorder(struct tree *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf(" %d", root->info);
        inorder(root->right);
    }
    return;
}
void postorder(struct tree *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf(" %d", root->info);
    }
    return;
}
void preorder(struct tree *root)
{
    if (root != NULL)
    {
        printf(" %d", root->info);
        preorder(root->left);
        preorder(root->right);
    }
    return;
}
/* FUNCTION TO DELETE A NODE FROM A BINARY TREE */
struct tree *delet(struct tree *ptr, int x)
{
    struct tree *p1, *p2;
    if (!ptr)
    {
        printf("\nNode not found ");
        return (ptr);
    }
    else
    {
        if (ptr->info < x)
        {
            ptr->right = delet(ptr->right, x);
            /*return(ptr);*/
        }
        else if (ptr->info > x)
        {
            ptr->left = delet(ptr->left, x);
            return ptr;
        }
        else
        /* no. 2 else */ {
            if (ptr->info == x)
            /* no. 2 if */ {
                if (ptr->left == ptr->right)
                /*i.e., a leaf node*/ {
                    free(ptr);
                    return (NULL);
                }
                else if (ptr->left == NULL)
                /* a right subtree */ {
                    p1 = ptr->right;
                    free(ptr);
                    return p1;
                }
                else if (ptr->right == NULL)
                /* a left subtree */ {
                    p1 = ptr->left;
                    free(ptr);
                    return p1;
                }
                else
                {
                    p1 = ptr->right;
                    p2 = ptr->right;
                    while (p1->left != NULL)
                        p1 = p1->left;
                    p1->left = ptr->left;
                    free(ptr);
                    return p2;
                }
            }
            /*end of no. 2 if */
        }
        /* end of no. 2 else */
        /* check which path to search for a given no. */
    }
    return (ptr);
}
/* function to search and replace an element in the binary tree */
struct tree *search(struct tree *root)
{
    int no, i, ino;
    struct tree *ptr;
    ptr = root;
    printf("\nEnter the element to be searched: ");
    scanf(" %d", &no);
    fflush(stdin);
    while (ptr)
    {
        if (no > ptr->info)
            ptr = ptr->right;
        else if (no < ptr->info)
            ptr = ptr->left;
        else
            break;
    }
    if (ptr)
    {
        printf("\n Element %d which was searched is found and is = %d", no, ptr->info);
        printf("\n Do you want replace it, press 1 for yes : ");
        scanf(" %d", &i);
        if (i == 1)
        {
            printf("\n Enter new element: ");
            scanf(" %d", &ino);
            ptr->info = ino;
        }
        else
            printf("\n\t It's okay");
    }
    else
        printf("\n Element %d does not exist in the binary tree", no);
    return (root);
}
