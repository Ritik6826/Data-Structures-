#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}
void insertion_at_begining(int *arr, int element, int capacity, int size) //worst case and best case Bigtheta(n)
{
    if (size >= capacity)
    {
        printf("overflow");
    }
    else
    {
        for (int i = size - 1; i >= 0; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[0] = element;
    }
}
void insertion_at_end(int *arr, int element, int capacity, int size) //worst case and best case o(1)
{
    if (size >= capacity)
    {
        printf("overflow");
    }
    else
    {
        
        arr[size] = element;
    }
}
void insertion_at_index(int *arr, int element, int capacity, int size, int index) //worst case o(n),best case o(1)
{
    if (size >= capacity)
    {
        printf("overflow");
    }
    else
    {
        for (int i = size - 1; i >= index; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[index] = element;
    }
}
void insertion_without_order(int *arr, int size, int element, int index, int capacity) //worst and best case o(1)
{
    if (size >= capacity)//without order means placing the element at index and that index element to last.
    {
        printf("overflow");
    }
    else
    {
        arr[size]=arr[index];
        arr[index]=element;


    }
}
void deletion_at_begining(int *arr, int size) //worst case bigtheta(n)
{

    for (int i = 0; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
}
void deletion_at_index(int *arr, int size, int index) //worst case o(n)
{

    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
}
void deletion_at_end(int *arr, int size) //worst case o(1)
{

    arr[size - 1] = arr[size];
}
void deletion_without_order(int *arr, int size, int index)
{
    arr[index] = arr[size-1]; //just taking last element to index
    arr[size -1]=arr[size];
}
int linear_search(int *arr, int size, int element) //worst case o(n)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}
int binary_search(int *arr, int size, int element) //for ascending sorted array.o(logn)
{
    int low, mid, high;//for descending sorted array low=mid-1;high=mid+1;
    low = 0;
    high = size - 1; 
    while (low <= high)
    {
        mid = (low + high) / 2; 
        if (arr[mid] == element)
        {
            return mid;
        }
        else if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
void ascending_sort(int *arr, int size) //o(n^2)-selection sort
{
    int min;
    for (int i = 0; i < size - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
            {
                int temp = arr[j];
                arr[j] = arr[min];
                arr[min] = temp;
            }
        }
    }
}
void descending_sort(int *arr, int size) //o(n^2)-selection sort
{
    int max;
    for (int i = 0; i < size - 1; i++)
    {
        max = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] > arr[max])
            {
                int temp = arr[j];
                arr[j] = arr[max];
                arr[max] = temp;
            }
        }
    }
}

int main()
{
    int capacity, size, element, index;
    printf("Enter the maximum size of array\n");
    scanf("%d", &capacity);
    int *ptr = (int *)malloc(capacity * sizeof(int));
    printf("Enter the size of array you wanna use\n");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        printf("Enter the %dth index element :", i);
        scanf("%d", (ptr + i));
    }
    int choice;
    char inchoice, delchoice, searchchoice, sortchoice;
    printf("press 1 to insert\npress 2 to delete\npress 3 to search\npress 4 to sort\n");
    printf("press any key other than 1 to 5 to travese");
    printf("Enter the operation you want to do with array\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("press a for insertion at beginning\npress b for insertion at any index\npress c for insertion at the end\n");
        printf("press d for insertion without maintaining the order\n");
        printf("Enter your choice\n");
        scanf(" %c",&inchoice);
        switch (inchoice)
        {
        case 'a':
            printf("Enter the element to be inserted\n");
            scanf("%d", &element);
            insertion_at_begining(ptr, element, capacity, size);
            size++;
            display(ptr, size);
            break;
        case 'b':
            printf("Enter the index and element to be inserted\n");
            printf("Enter the index,element\n");
            scanf("%d%d", &index, &element);
            insertion_at_index(ptr, element, capacity, size, index);
            size++;
            display(ptr, size);
            break;
        case 'c':
            printf("Enter the element to be inserted\n");
            scanf("%d", &element);
            insertion_at_end(ptr, element, capacity, size);
            size++;
            display(ptr, size);
            break;
        case 'd':
            printf("Enter the element  and index to be inserted\n");
            scanf("%d%d", &element,&index);
            insertion_without_order(ptr, size, element, index, capacity); /*here we will insert the element at index i and shift the ith index element to last*/
            size++;
            display(ptr, size);
            break;
        }
        break;
    case 2:
        printf("press a for deletion at beginning\npress b for deletion at any index\npress c for deletion at the end\n");
        printf("press d for deletion without maintaining the order\n");
        printf("Enter your choice\n");
        scanf(" %c", &delchoice);
        switch (delchoice)
        {
        case 'a':
            deletion_at_begining(ptr, size);
            size--;
            display(ptr, size);
            break;
        case 'b':
            printf("Enter the element index you wanna delete\n");
            scanf("%d", &index);
            deletion_at_index(ptr, size, index);
            size--;
            display(ptr, size);
            break;
        case 'c':
            deletion_at_end(ptr, size);
            size--;
            display(ptr, size);
            break;
        case 'd':
            printf("Enter the element index you wanna delete\n");
            scanf("%d", &index);
            deletion_without_order(ptr, size, index); //here we will delete the element at index i and place the last element to i
            size--;
            display(ptr, size);
            break;
        }
        break;
    case 3:
        printf("press a for linear search\npress b for binary search;binary search works only in sorted array\n ");
        printf("Enter your choice\n");
        scanf(" %c", &searchchoice); 
        switch (searchchoice)
        {
        case 'a':
            printf("Enter the elemnet you wanna search\n");
            scanf("%d", &element);
            int l = linear_search(ptr, size, element);
            if (l == -1)
            {
                printf("The element %d not found", element);
            }
            else
            {
                printf("The element %d found at index %d\n", element, l);
            }

            break;
        case 'b':
            printf("Enter the elemnet you wanna search.Note the array should be sorted in ascending order.Otherwise use linear search\n");
            scanf("%d", &element);
            int l1 = binary_search(ptr, size, element);
            if (l1 == -1)
            {
                printf("The element %d not found", element);
            }
            else
            {
                printf("The element %d found at index %d\n", element, l1);
            }

            break;
        }
        break;
    case 4:
        printf("press a for sorting in ascending order\npress b for sorting in descending order\n");
        printf("Enter your choice\n");
        scanf(" %c", &sortchoice);
        switch (sortchoice)
        {
        case 'a':
            ascending_sort(ptr, size);
            display(ptr, size);
            break;
        case 'b':
            descending_sort(ptr, size);
            display(ptr, size);
            break;
        }
        break;
    default:
        display(ptr, size);
        break;
    }

    return 0;
}