#include <stdio.h>
#include <stdlib.h>

struct DEQueue
{
    int size, f, r;
    int *arr;
};


int isEmpty(struct DEQueue *q)
{
    if (q->f == -1 && q->r == -1)
    {
        return 1;
    }
    return 0;
}
int isFull(struct DEQueue *q)
{
    if ((q->f == q->r + 1) || (q->f == 0 && q->r == q->size - 1))
    {
        return 1; //We can also write q->f==(q->r+1)%size instead of above condition.
    }
    return 0;
}

void Enqueue_front(struct DEQueue *q, int data)
{
    if (isFull(q))
    {
        printf("Queue overflow!No further insertions\n");
    }
    else if (isEmpty(q))
    {
        q->f = q->r = 0;
        q->arr[q->f] = data;
    }
    else if (q->f == 0) // We can write only one else instead  of these last 
    {
        q->f = q->size - 1; //two else and do circular decrement as q->f=(q->f+size-1)%size;
        q->arr[q->f] = data;
    }
    else
    {
        q->f--;
        q->arr[q->f] = data;
    }
}
void Enqueue_rear(struct DEQueue *q, int data)
{
    if (isFull(q))
    {
        printf("Queue overflow!No further insertions\n");
    }
    else if (isEmpty(q))
    {
        q->f = q->r = 0;
        q->arr[q->r] = data;
    }
    else if (q->r == q->size-1) // We can write only one else instead  of these last 
    {
        q->r = 0; //two else and do circular increment as q->r=(q->r+1)%size;
        q->arr[q->r] = data;
    }
    else
    {
        q->r++;
        q->arr[q->r] = data;
    }
}

void Dequeue_front(struct DEQueue *q)
{
    if(isEmpty(q))
    {
        printf("Queue underflow!No further deletions\n");
    }
    else if(q->f==q->r)//only one element in queue then make it empty
    {
        q->f=q->r=-1;

    }
    else if(q->f==q->size-1)// We can write only one else instead  of these last 
    {
        q->f=0;//two else and do circular increment as q->f=(q->f+1)%size;
    }
    else
    {
        q->f++;
    }

}
void Dequeue_rear(struct DEQueue *q)
{
    if(isEmpty(q))
    {
        printf("Queue underflow!No further deletions\n");
    }
    else if(q->f==q->r)//only one element in queue then make it empty
    {
        q->f=q->r=-1;

    }
    else if(q->r==0)// We can write only one else instead  of these last 
    {
        q->r=q->size-1;//two else and do circular decrement as q->r=(q->r+size-1)%size;
    }
    else
    {
        q->r--;
    }

}

int getFront(struct DEQueue *q)
{ 
    return q->arr[q->f];
}
int getrear(struct DEQueue *q)
{
    return q->arr[q->r];
}

void DEQueue_travesal(struct DEQueue *q)
{
    if(isEmpty(q))
    {
        printf("Queue is Empty\n");
    }
    else
    {
    int i=q->f;
    while(i!=q->r)
    {
        printf("%d\t",q->arr[i]);
        i=(i+1)%q->size;
    }
    printf("%d\t",q->arr[i]);//at this point i=q->r.
    }
}


int main()
{
    struct DEQueue *q = (struct DEQueue *)malloc(sizeof(struct DEQueue));
    q->size = 8;
    q->f = q->r = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));
    Enqueue_front(q,5);
    Enqueue_front(q,12);
    Enqueue_front(q,13);
    Enqueue_front(q,4);
    Enqueue_rear(q,22);
    Enqueue_rear(q,27);
    Enqueue_rear(q,29);
    Enqueue_rear(q,67);
    Dequeue_rear(q);
    Dequeue_rear(q);
    Dequeue_rear(q);
    Dequeue_rear(q);
    Dequeue_rear(q);
    Dequeue_rear(q);
    //Dequeue_rear(q);
    //Dequeue_rear(q);
    printf("The front value is %d\t",getFront(q));
    printf("The rear value is %d\t",getrear(q));
 
    
    DEQueue_travesal(q);

}