#include <stdio.h>
#include <stdlib.h>
//Searching is not a part of this program.
/*here i used single pointer so i have to return head but if we don't wanna return anything
then use double pointer and pass the adress of head*/

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
void doubly_ll_traversal(struct node *head)
{
    while (head != NULL)
    {
        printf("%d\t", head->data);
        head = head->next;
    }
    printf("\n");
}
void reverse_traversal(struct node *ptr)
{
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->prev;
    }
}
struct node *insertion_at_begin(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->prev = NULL;
    ptr->next = head;
    head->prev = ptr;
    head = ptr;
    return (head);
}
struct node *insertion_at_index(struct node *head, int data, int index)
{
    struct node *p = head;
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    ptr->prev = p;
    p->next->prev = ptr;
    p->next = ptr;

    return (head);
}
struct node *insertion_at_end(struct node *head, int data)
{
    struct node *p = head;
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    while (p->next != NULL)
    {
        p = p->next;
    }

    ptr->next = NULL;
    ptr->prev = p;
    p->next = ptr;
    return (head);
}
struct node *insertion_after_node(struct node *head, struct node *before, int data)
{
    struct node *p = head;
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = before->next;
    ptr->prev = before;
    before->next->prev = ptr;
    before->next = ptr;
    return (head);
}
struct node *deletion_at_begin(struct node *head)
{

    struct node *q = head;
    head->next->prev = NULL;
    head = head->next;
    free(q);
    return (head);
}
struct node *deletion_at_index(struct node *head, int index)
{
    struct node *p = head;
    struct node *q = head->next;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = q->next;
    q->next->prev = p;
    free(q);
    return head;
}
struct node *deletion_at_end(struct node *head)
{
    struct node *p = head;
    struct node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}
struct node *deletion_at_given_value(struct node *head, int value)
{
    struct node *p = head;
    struct node *q = head->next;
    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == value)
    {
        p->next = q->next;
        q->next->prev = p;
        free(q);
    }

    return head;
}

int main()
{
    int choice, data, index, value;
    struct node *head, *second, *third, *four, *five;
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    four = (struct node *)malloc(sizeof(struct node));
    five = (struct node *)malloc(sizeof(struct node));
    head->data = 23;
    head->next = second;
    head->prev = NULL;
    second->data = 32;
    second->next = third;
    second->prev = head;
    third->data = 45;
    third->next = four;
    third->prev = second;
    four->data = 90;
    four->next = five;
    four->prev = third;
    five->data = 55;
    five->next = NULL;
    five->prev = four;
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
            head = insertion_at_begin(head, data);
            break;
        case 2:
            printf("Enter the data and index you wanaa insert\n");
            scanf("%d%d", &data, &index);
            head = insertion_at_index(head, data, index);
            break;
        case 3:
            printf("Enter the data you wanaa insert\n");
            scanf("%d", &data);
            head = insertion_at_end(head, data);
            break;
        case 4:
            printf("Enter the data  you wanaa insert\n");
            scanf("%d", &data);
            head = insertion_after_node(head, second, data);
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
            head = deletion_at_begin(head);
            break;
        case 2:
            printf("Enter the index you wanna delete\n");
            scanf("%d", &index);
            head = deletion_at_index(head, index);
            break;
        case 3:
            head = deletion_at_end(head);
            break;
        case 4:
            printf("Enter the value you wanna delete except first and last value\n");
            scanf("%d", &value);
            head = deletion_at_given_value(head, value);
            break;
        }
        break;
    }

    doubly_ll_traversal(head);
    printf("doubly LL in reverse order\n");
    reverse_traversal(head);

    return 0;
}