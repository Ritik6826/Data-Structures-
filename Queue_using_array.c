#include <stdio.h>
#include <stdlib.h>
//In this queue once queue is full we can't insert any element even after dequeing or deleting
struct queue
{
    int size;
    int data, f, r;
    int *arr;
};
int isEmpty(struct queue *q)
{
    if (q->f ==-1 && q->r==-1)
    {
        return 1;
    }
    return 0;
}

void queue_traversal(struct queue *q)
{
   
    for(int i=q->f;i<=q->r;i++)
    {
        printf("%d\t",q->arr[i]);     
    }
    printf("\n");
}

int isFull(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}

void Enqueue(struct queue *q, int data)
{
    if (isFull(q))
    {
        printf("queue overflow\n");
    }
    else if(isEmpty(q))
    {
        q->f=q->r=0;
        q->arr[q->r]=data;
    }
    else
    {
        q->arr[++q->r]=data;
    }


}
void Dequeue(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue underflow\n");     
    }
    else if(q->r==q->f)
    {
        q->r=q->f=-1;
       
    }
    else
    {
         q->f++;
    }
}

int main()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->r = q->f = -1;
    q->size = 5;
    q->arr = (int *)malloc(q->size * sizeof(int));
    Enqueue(q,5);
    Enqueue(q,5);
    Enqueue(q,5);
    Enqueue(q,5);
    Enqueue(q,5);
    Dequeue(q);
    Enqueue(q,5);
    queue_traversal(q);
   
   


    return 0;
}