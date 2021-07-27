#include<stdio.h>
#include<stdlib.h>
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
    temp=*head;
    for (int i = 2; i <= n; i++)
    {
       
        new_node=(struct node *)malloc(sizeof(struct node));
        printf("Enter the %d node data\n",i);
        scanf("%d", &data);
        new_node->data = data;
        new_node->next=NULL;
        temp->next=new_node;
        temp=temp->next;      

    }
}
int main()
{
    int n,index;
    struct node *head,*ptr;
    printf("Enter the size of linked list\n");
    scanf("%d",&n);
    create_node(&head,n);
    printf("Enter the index you wanna reach\n");
    scanf("%d",&index);
    int i=0;//Here we are considering index starts from 0.But in LL it can be from anywhere.
    ptr=head;
    while(i!=index&&ptr->next!=NULL)//It will reach to node at index.Not pointer at index.
    {
        ptr=ptr->next;   //ptr->next!=NULL checks that index only valid to last node.
        i++; 
    }
    if(i==index)
    {
    printf("The element at index %d is %d",index,ptr->data);
    }
    else
    {
        printf("THE index don't exist");
    }

    //Now suppose index starts from 7 means i=7(means at head node)
    //Then if element at index 10 is required means we need
    //to print element of node in (10-7+1)=4th position.

return 0;
}