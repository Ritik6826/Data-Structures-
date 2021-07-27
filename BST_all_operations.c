#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root != NULL)
    {

        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root != NULL)
    {

        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void insertBST(struct node **root, int key)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = key;
    newNode->left = NULL;
    newNode->right = NULL;
    if (*root == NULL)
    {
        *root = newNode;
        return;
    }
    else
    {

        struct node *ptr = *root, *parent = NULL;
        while (ptr != NULL)
        {
            parent = ptr;

            if (key == ptr->data)
            {
                printf("Duplicates are not allowed\n");
                return;
            }
            else if (key > ptr->data)
            {
                ptr = ptr->right;
            }
            else
            {
                ptr = ptr->left;
            }
        }
        if (key < parent->data)
        {
            parent->left = newNode;
        }
        else if (key > parent->data)
        {
            parent->right = newNode;
        }
    }
}

struct node *findmax(struct node *root)
{
    if (root->right == NULL || root == NULL)
        return root;
    else
        return findmax(root->right);
}

struct node *deleteBST(struct node *root, int key)
{

    struct node *temp;
    if (key < root->data)
        root->left = deleteBST(root->left, key);
    else if (key > root->data)
        root->right = deleteBST(root->right, key);
    else
    {
        if (root->left && root->right)
        {
            temp = findmax(root->left);
            root->data = temp->data;
            root->left = deleteBST(root->left, temp->data);
        }
        else
        {
            temp = root;
            if (root->left == NULL && root->right == NULL)
            {
                free(temp);
                root = NULL;
            }
            else if (root->left != NULL)
            {
                struct node *ptr = root->left;
                free(root);
                return ptr;
            }
            else
            {
                struct node *ptr = root->right;
                free(root);
                return ptr;
            }
        }
        return root;
    }
}
struct node *search(struct node *root, int key)
{

    if (root == NULL || root->data == key)
        return root;

    if (root->data < key)
        return search(root->right, key);

    else
        return search(root->left, key);
}

int main()
{
    int key, ch;
    struct node *root = NULL, *temp = NULL;
    while (1)
    {
        printf("press 1 to insert\n2 to deleteBST\n3 to search\n4 to display\n5to exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the element to insert\n");
            scanf("%d", &key);
            insertBST(&root, key);
            break;
        case 2:
            if (root == NULL)
            {
                printf("Tree does not exist.\n");
            }
            else
            {
                printf("Enter the element to deleteBST\n");
                scanf("%d", &key);
                temp = search(root, key);
                if (temp == NULL)
                    printf("Element not found.\n");
                else
                    root = deleteBST(root, key);
            }
            break;
        case 3:
            if (root == NULL)
            {
                printf("Tree does not exist.\n");
            }
            else
            {
                printf("Enter element to search :");
                scanf("%d", &key);
                temp = search(root, key);
                if (temp == NULL)
                    printf("Element not found.\n");
                else
                    printf("Element found.\n");
            }
            break;
        case 4:
            if (root == NULL)
            {
                printf("Tree does not exist.\n");
            }
            else
            {
                printf("Preorder: ");
                preorder(root);
                printf("\nInorder: ");
                inorder(root);
                printf("\nPostorder: ");
                postorder(root);
                printf("\n");
            }
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Please enter a valid choice between (1/2/3/4/5).\n");
        }
    }

    return 0;
}