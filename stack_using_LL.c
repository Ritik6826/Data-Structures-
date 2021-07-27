#include <stdio.h>
#include <stdlib.h>
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
int isEmpty(struct node *s)
{
    if (s == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct node *s)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
struct node *push(struct node *s, int element)
{
    if (isFull(s))
    {
        printf("Stack overflow\n");
    }
    else
    {
        struct node *ptr = (struct node *)malloc(sizeof(struct node));
        ptr->data = element;
        ptr->next = s;
        s = ptr;
        return s;
    }
}
struct node *pop(struct node *s)
{
    if (isEmpty(s))
    {
        printf("Stack underflow\n");
    }
    else
    {
        struct node *q = s;
        s = s->next;
        free(q);
        return s;
    }
}
int peek(struct node *s, int pos)
{
    struct node *p = s;
    int i = 1;
    while (i != pos && p != NULL)
    {
        p = p->next;
        i++;
    }
    if (p != NULL)
    {
        return p->data;
    }
    else
    {
        printf("Not a valid position\n");
        return -1;
    }
}
int stackTop(struct node *s)
{
    return s->data;
}
int stackBottom(struct node *s)
{
    while(s->next!=NULL)
    {
        s=s->next;
    }
    return s->data;
}

int main()
{
    struct node *top = NULL;
    top = push(top, 23);
    top = push(top, 36);
    top = push(top, 56);
    top = push(top, 69);
    top = push(top, 96);
    top = push(top, 20);
    top = push(top, 43);
    top = push(top, 24);
    top = pop(top);
    top = pop(top);
    top = pop(top);
    top = pop(top);
    printf("%d\n", peek(top, 5));
    printf("%d\n", stackBottom(top));
    printf("%d\n", stackTop(top));


    linkedlist_traversal(top);

    return 0;
}