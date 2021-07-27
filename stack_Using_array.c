#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int *arr;
    int top; //top is the index of topmost element.
};
void array_display(struct stack *s)
{
    for (int i = 0; i <= s->top; i++)
    {
        printf("%d  ", s->arr[i]);
    }
    printf("\n");
}

int isEmpty(struct stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    else
        return 0;
}
int isFull(struct stack *s)
{
    if (s->top == s->size - 1)
    {
        return 1;
    }
    else
        return 0;
}

void push(struct stack *s, int element)
{
    if (isFull(s))
    {
        printf("stack overflow!%d cant't be pushed\n", element);
    }
    else
    {
        s->top++;
        s->arr[s->top] = element;
    }
}
void pop(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("stack underflow\n");
    }
    else
    {
        s->top--;
    }
}
int peek(struct stack *s, int pos) //The position of  the first element in stack is the last element or index of array.

// Note position is not index of array.
{
    int arrInd = s->top - pos + 1; //top value is fixed but arrindex is varying.
    if (arrInd < 0)
    {
        printf("This position don't exist in this stack\n");
    }
    else
    {
        return s->arr[arrInd];
    }
}
void stack_display(struct stack *s)
{
    for (int i = 1; i <= s->top + 1; i++)
    {
        printf("%d \n", peek(s, i), i);
    }
    printf("\n");
}

int stackTop(struct stack *s) //Top most element of stack or whose position is 1 or index of array is last or equals to top.
{
    if (isEmpty(s))
    {
        printf("stack underflow\n"); //Note here we don't returned anything because in else case we had already returned
    }
    else

        return s->arr[s->top];
}
int stackBottom(struct stack *s) //Bottom most element of stack or first index element of array
{
    if (isEmpty(s))
    {
        printf("stack underflow\n");
    }
    else
        return s->arr[0];
}

int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    push(s, 5);
    push(s, 9);
    push(s, 11);
    push(s, 18);
    push(s, 22);
    pop(s);
    pop(s);
    pop(s);
    push(s,35);
    

    printf("Array display :\n");
    array_display(s);
    printf("Stack display :\n");
    stack_display(s);
    printf("The element at top is %d\n", stackTop(s));
    printf("The element at bottom is %d", stackBottom(s));

    return 0;
}