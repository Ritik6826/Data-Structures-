#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int size, f, r;
    int *arr;
};
int isEmpty(struct queue *q)
{
    if (q->f == -1 && q->r == -1)
    {
        return 1;
    }
    return 0;
}
void queue_traversal(struct queue *q)//here in travesal never use i<=q->r.
//This will cause infinite loop.
{
    if (isEmpty(q))
    {
        printf("Queue is empty");
    }
    else
    {
        for (int i = q->f; i != q->r; i = (i + 1) % q->size)
        {
            printf("%d\t", q->arr[i]);
        }
        printf("%d\t", q->arr[q->r]);
    }
}

int isFull(struct queue *q)
{
    if ((q->r + 1) % q->size == q->f)
    {
        return 1;
    }
    return 0;
}

void Enqueue(struct queue *q, int data)
{
    if (isFull(q))
    {
        printf("queue overflow!No further insertions\n");
    }
    else
    {
        if (isEmpty(q)) //When queue is empty then f and r both was -1.so at first both made 0
        {
            q->f = q->r = 0;
            q->arr[q->r] = data;
        }
        else
        {
            q->r = (q->r + 1) % q->size;
            q->arr[q->r] = data;
        }
    }
}
void Dequeue(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("queue underflow!No further deletions\n");
    }
    else
    {
        if (q->f == q->r) //When one element  is present at any index.
        {
            q->f = q->r = -1;
        }
        else
        {
            q->f = (q->f + 1) % q->size;
        }
    }
}
int main()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 5;
    q->f = q->r = -1; //Total insertion possible is always size-1 not size.
    q->arr = (int *)malloc(q->size * sizeof(int));
    Enqueue(q, 34);
    Enqueue(q, 34);
    Enqueue(q, 34);
    Enqueue(q, 34);
    Enqueue(q, 34);
    Dequeue(q);
    Enqueue(q, 5);
    Dequeue(q);
    Dequeue(q);
    Dequeue(q);
    Dequeue(q);
    Dequeue(q);
    queue_traversal(q);

    return 0;
}