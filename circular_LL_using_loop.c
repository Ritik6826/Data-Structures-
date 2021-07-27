#include <stdio.h>
#include <stdlib.h>
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
    temp->next=*head;//for circular ll
}
struct node *insertion_at_index(struct node *ptr, int data, int index)
{
    struct node *head=ptr;
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    if (index == 0)
    {
        n->next = ptr;
        while(ptr->next!=head)
        {
            ptr=ptr->next;
        }
        ptr->next=n;
        ptr = n;
       return ptr;
    }
    else
    {
        struct node *temp = ptr;
        int i = 0;
        while (i != index - 1)
        {
            temp = temp->next;
            i++;
        }
        n->next = temp->next;
        temp->next = n;
        return ptr;
    }
}
struct node *deletion_at_index(struct node *head, int index)
{
    struct node *ptr=head;
    struct node *q;
    if (index == 0)
    {
        q = head;
        while(ptr->next!=head)
        {
            ptr=ptr->next;
        }
        ptr->next=head->next;
        head = head->next;

        free(q);
        return head;
    }
    else
    {
        struct node *temp = head;
        int i = 0;
        while (i != index-1)
        {
            temp = temp->next;
            i++;
        }
        q = temp->next;
        temp->next = q->next;
        free(q);
        return head;
    }
}
void circular_linkedlist_traversal(struct node *ptr) //Bigtheta(n)
{
    struct node *head=ptr;
    while (ptr->next != head)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("%d\t",ptr->data);
    ptr=ptr->next;
     while (ptr->next != head)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("%d\t",ptr->data);
    printf("\n");
}
int main()
{
    struct node *head, *ptr;
    create_node(&head, 5);
    //head=insertion_at_index(head,32,5);
    head=deletion_at_index(head,4);
    circular_linkedlist_traversal(head);

    return 0;
}