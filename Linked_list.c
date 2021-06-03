#include <stdio.h>
#include <stdlib.h>
//Searching is not a part of this program.

/*Note here in this program i personally used double pointer so that i don't need to return
any value from function and the function choice is voide also.
If don't wanna use double pointer then we need to make functions of struct node * return type
and finally this returned value passed to head in main function.
The same is done in circularly linked list and doubly linked list where i used single pointer and struct node * return
type function.*/
struct node
{
    int data;
    struct node *next;
};
void linkedlist_traversal(struct node *ptr) //Bigtheta(n)
{
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
}
void insertion_at_begin(struct node **head, int data) //O(1) or Bigtheta(1)
{
    //struct node *p=*head;
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = (*head);
    (*head) = ptr;
}
void insertion_at_index(struct node **head, int data, int index) //O(n)
{
    struct node *p = *head;

    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    for (int i = 0; i != index - 1; i++)
    {
        p = p->next;
    }
    ptr->next = p->next;
    p->next = ptr;
}

void insertion_at_end(struct node **head, int data) //Bigtheta(n)
{
    struct node *p = *head;

    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    while (p->next != NULL) //p->next is last node.
    {
        p = p->next;
    }
    ptr->next = NULL;
    p->next = ptr;
}
void insertion_after_node(struct node **head, struct node *prev, int data) //O(1)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = prev->next;
    prev->next = ptr;
}
//In deletion always remember p is that pointer which traverses in just before the node to be deleted.
//q is that pointer which always points to node to be deleted.so that we can free q.
void deletion_at_begin(struct node **head) //O(1)
{
    struct node *p = *head;
    *head = (*head)->next;
    free(p);
}
void deletion_at_index(struct node **head, int index) //O(n)
{
    struct node *p = *head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    struct node *q = p->next;
    p->next = p->next->next; //or p->next=q->next;
    free(q);
}
void deletion_at_end(struct node **head) //Bigtheta(n)
{
    struct node *p = *head;
    while (p->next->next != NULL) //p->next->next is second last node
    {
        p = p->next;
    }
    struct node *q = p->next;
    p->next = NULL;
    free(q);
}
void deletion_at_value(struct node **head, int value) //Delete the node having particular value stored
{
    struct node *p = *head; //O(n)
    while (p->next->data != value && p->next != NULL)
    {
        p = p->next;
    }
    if (p->next->data == value)
    {
        struct node *q = p->next;
        p->next = q->next;
        free(q);
    }
}

int main()
{
    int choice, data, index, value;
    struct node *head, *second, *third, *four;
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    four = (struct node *)malloc(sizeof(struct node));

    head->data = 35;
    head->next = second;
    second->data = 67;
    second->next = third;
    third->data = 89;
    third->next = four;
    four->data = 90;
    four->next = NULL;
    printf("Enter 1 for insertion\nEnter 2 for deletion\nEnter any other integer to traverse\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Enter 1 for insertion at begining\nEnter 2 for insertion in between(except first)\nEnter 3 for insertion at end\nEnter 4 for insertion after a given node\n");
        int ch_in;
        scanf("%d", &ch_in);
        switch (ch_in)
        {
        case 1:
            printf("Enter the data you wanaa insert\n");
            scanf("%d", &data);
            insertion_at_begin(&head, data);
            break;
        case 2:
            printf("Enter the data and index you wanaa insert\n");
            scanf("%d%d", &data, &index);
            insertion_at_index(&head, data, index);
            break;
        case 3:
            printf("Enter the data you wanaa insert\n");
            scanf("%d", &data);
            insertion_at_end(&head, data);
            break;
        case 4:
            printf("Enter the data  you wanaa insert\n");
            scanf("%d", &data);
            insertion_after_node(&head, second, data);
            break;
        }
        break;
    case 2:
        printf("Enter 1 for deletion at begining\nEnter 2 for deletion in between(except first)\nEnter 3 for deletion at end\nEnter 4 for deletion at a given value\n");
        int ch_del;
        scanf("%d", &ch_del);
        switch (ch_del)
        {
        case 1:
            deletion_at_begin(&head);
            break;
        case 2:
            printf("Enter the index you wanna delete\n");
            scanf("%d", &index);
            deletion_at_index(&head, index);
            break;
        case 3:
            deletion_at_end(&head);
            break;
        case 4:
            printf("Enter the value you wanna delete except first value\n");
            scanf("%d", &value);
            deletion_at_value(&head, value);
            break;
        }
        break;
    }
    linkedlist_traversal(head);

    return 0;
}