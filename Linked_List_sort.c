#include <stdio.h>
#include <stdlib.h>

//In order to avoid extra space we need to use iterative way to sort in linked list.since time complexity
//not mattering so i am using selection sort.But efficient way is to use merge sort iteratively.
struct node
{
    int data;
    struct node *next;
};

void create_node(struct node **head, int n)
{
    struct node *temp, *new_node;
    int data;
    *head = (struct node *)malloc(sizeof(struct node));
    printf("Enter the 1st node data\n");
    scanf("%d", &data);
    (*head)->data = data;
    (*head)->next = NULL;
    temp = *head;
    for (int i = 2; i <= n; i++)
    {

        new_node = (struct node *)malloc(sizeof(struct node));
        printf("Enter the %d node data\n", i);
        scanf("%d", &data);
        new_node->data = data;
        new_node->next = NULL;
        temp->next = new_node;
        temp = temp->next;
    }
}

void selection_sort(struct node **head)
{
    int temp;
    struct node *ptr1 = *head;
    struct node *ptr2 = *head;
    while (ptr1 != NULL)
    {
        ptr2 = ptr1->next;
        while (ptr2 != NULL)
        {
            if (ptr2->data < ptr1->data)
            {

                temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}

void display(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
int main()
{
    int ch, n;
    struct node *head = NULL;

    while (1)
    {
        printf("-----------MENU---------------\n");
        printf("Enter 1 to create LL\n Enter 2 to sort LL\nEnter 3 to exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the number of node  ::");
            scanf("%d", &n);
            create_node(&head, n);
            printf("linked_list before sorting\n");
            display(head);
            break;
        case 2:
            selection_sort(&head);
            printf("Linked list after sorting\n");
            display(head);
            break;
        case 3:
            exit(1);
        default:
            printf("Choose a valid option\n");
            break;
        }
    }

    return 0;
}