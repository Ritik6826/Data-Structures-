#include <stdio.h>
#include <stdlib.h>
//Travesal occurs with front.
struct queue
{
    int data;
    struct queue *next;
};
void queue_travesal(struct queue *front)
{
    while (front != NULL)
    {
        printf("%d\t", front->data);
        front = front->next;
    }
    printf("\n");
}

int isEmpty(struct queue *front, struct queue *back)
{
    if (front == NULL && back == NULL) //here front=back=NULL
    {
        return 1;
    }
    return 0;
}
int isFull(struct queue *front, struct queue *back)
{
    struct queue *n = (struct queue *)malloc(sizeof(struct queue));
    if (n == NULL)
    {
        return 1;
    }
    return 0;
}
struct queue *Enqueue(struct queue *front, struct queue **back, int data)
{
    struct queue *n = (struct queue *)malloc(sizeof(struct queue));
    n->data = data;
    n->next = NULL;

    if (isFull(front, *back))
    {
        printf("Queue overflow\n");
    }
    else
    {
        if (front == NULL && *back == NULL) //Empty queue condition same as in array
        {
            front = *back = n; //adding 1st element.
            return front;
        }
        else
        {

            (*back)->next = n;
            (*back) = n;
            return front; //Note here we are returning front always.
        }
    }
}
struct queue *Dequeue(struct queue *front, struct queue **back)
{
    if (isEmpty(front, *back))
    {
        printf("queue underflow\n");
    }
    else
    {
        if (front == *back)
        {
            front = *back = NULL;
            return front;
        }
        else
        {
            struct queue *ptr = front;
            front = front->next;
            free(ptr);
            return front;
        }
    }
}
int main()
{
    struct queue *front = NULL;
    struct queue *back = NULL;
    front = Enqueue(front, &back, 64);
    front = Enqueue(front, &back, 63);
    front = Enqueue(front, &back, 63);
    front = Enqueue(front, &back, 63);
    front = Dequeue(front, &back);
    front = Dequeue(front, &back);
    front = Dequeue(front, &back);
    front = Dequeue(front, &back);
    queue_travesal(front);

    return 0;
}
