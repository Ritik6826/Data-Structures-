#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack
{
    int size;
    char *arr;
    int top;
};
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
void push(struct stack *s, char element)
{
    if (isFull(s))
    {
        printf("stack overflow!%c cant't be pushed\n", element);
    }
    else
    {
        s->top++;
        s->arr[s->top] = element;
    }
}
char pop(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("stack underflow\n");
    }
    else
    {
        char element = s->arr[s->top];
        s->top--;
        return element;
    }
}
int match(char a, char b)
{
    if (a == '{' && b == '}')
    {
        return 1;
    }
    if (a == '(' && b == ')')
    {
        return 1;
    }
    if (a == '[' && b == ']')
    {
        return 1;
    }
    return 0;
}
int parenthsis_match(struct stack *s)
{
    char popped_element;
    int i = 0;
    while (s->arr[i] != '\0')
    {
        if (s->arr[i] == '(' || s->arr[i] == '{' || s->arr[i] == '[')
        {
            push(s, s->arr[i]);
        }
        else if (s->arr[i] == ')' || s->arr[i] == '}' || s->arr[i] == ']')
        {
            if (isEmpty(s))
            {
                return 0;
            }
            else
            {
                popped_element = pop(s);
                if (!match(popped_element, s->arr[i]))
                {
                    return 0;
                }
            }
        }
        i++;
    }
    if (isEmpty(s))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 100;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));
    strcpy(s->arr, "[{()}]");

    if (parenthsis_match(s))
    {
        printf("Parenthesis Matching\n");
    }
    else
    {
        printf("Parenthesis not Matching\n");
    }

    return 0;
}