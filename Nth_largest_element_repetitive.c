#include <stdio.h>
#include <stdlib.h>
void display(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void selection_sort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {

        for (int j = i + 1; j < n; j++)
        {

            if (arr[j] < arr[i])
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

int main()
{

    int arr[] = {1, 8, 8, 8, 6, 9, 3, 2, 2, 4, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);
    int i,j,k,x,y;
    printf("Enter the kth largest element in array\n");
    scanf("%d", &k);
    if (k > n)
    {
        printf("Enter the valid value of k\n");
    }
    else
    {
        selection_sort(arr,n);
        y=n-1;
        for (i=1; i < k; i++)
        {
            int x = arr[y];
            for (j = y; j >= 0;)
            {
                if (arr[j] != x)
                {
                    y = j;
                    break;
                }
                else
                {
                    j--;
                }
            }
        }
        printf("The %dth largest element is %d\n",k, arr[y]);
    }

    return 0;
}