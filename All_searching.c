#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int rand();
void srand();

FILE *fp;

void display(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {

        printf("%d ", arr[i]);
    }

    printf("\n");
}
void random(int *arr, int n)
{
    fp = fopen("D://ALL  PROGRAMS/FILE HANDLING/random.txt", "a+");
    srand(time(0));
    int i, j;

    for (i = 0; i < n; i++)
    {
        int r = (rand() % n) + 1;
        for (j = 0; j < i; j++)
        {
            if (r == arr[j])
            {
                break;
            }
        }
        if (i == j)
        {
            arr[i] = r;
            fprintf(fp, "%d ", arr[i]);
            fscanf(fp, "%d", &arr[i]);
        }
        else
        {
            i--;
        }
    }
    fprintf(fp, "\n\n");
    fclose(fp);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int *arr, int low, int high)
{
    int pivot = arr[low];
    int i = low + 1, j = high;
    do
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }
    } while (i < j);

    swap(&arr[low], &arr[j]);
    return j;
}

void quick_sort(int *arr, int low, int high)
{
    int partition_index;
    if (low < high)
    {
        partition_index = partition(arr, low, high);
        quick_sort(arr, low, partition_index - 1);
        quick_sort(arr, partition_index + 1, high);
    }
}
int linear_search(int *arr, int n, int key)
{
    for (int i = 0; i < n; i++)
    {

        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int binary_search(int *arr, int n, int element) //for ascending sorted array.o(logn)
{
    int low, mid, high; //for descending sorted array low=mid-1;high=mid+1;
    low = 0;
    high = n - 1;
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
int interpolation_search(int *arr, int n, int key)
{

    int low, mid, high;
    low = 0;
    high = n - 1;
    while (arr[low] <= key && arr[high] >= key)
    {

        mid = low + ((key - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else if (arr[mid] > key)
        {
            high = mid - 1;
        }
        else
        {

            return mid;
        }
    }
    return -1;
}
void file_display(FILE *fp, int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        fprintf(fp, "%d ", arr[i]);
    }
    fprintf(fp, "\n");
}

int main()
{
    int n, i, j, ch, key, ind;
    clock_t start, end, total;
    printf("Enter the MAX limit of random number\n");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    random(arr, n);
    printf("The unsorted array is :\n");
    display(arr, n);
    printf("\n------------SEARCHING MENU -----------");
    printf("\n1.Linear Search");
    printf("\n2.Binary Search. ");
    printf("\n3.Interpolation Search. ");
    printf("\n4.Exit");
    printf("\nEnter your choice::");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        fp = fopen("D://ALL  PROGRAMS/FILE HANDLING/linear_search.txt", "a");
        fprintf(fp, "Array of random input\n");
        file_display(fp, arr, n);
        printf("\nEnter the element to be searched)::");
        scanf("%d", &key);
        fprintf(fp, "\nThe element to be searched is :: %d\n", key);
        start = clock();
        ind = linear_search(arr, n, key);
        end = clock();
        total = (double)(end - start);
        if (ind == -1)
        {
            printf("Element not found\n");
            fprintf(fp, "Element not found\n");
        }
        else
        {
            printf("Element found at index %d\n", ind);
            fprintf(fp, "Element found at index %d\n", ind);
        }
        printf("Execution time is %li \n", (long int)total);
        fprintf(fp, "Execution time is %li \n", (long int)total);
        fclose(fp);
        break;
    case 2:
        fp = fopen("D://ALL  PROGRAMS/FILE HANDLING/binary_search.txt", "a");
        fprintf(fp, "Array of random input/unsorted array\n");
        file_display(fp, arr, n);
        quick_sort(arr, 0, n - 1);
        printf("sorted array\n");
        display(arr, n);
        fprintf(fp, "Sorted array..........\n");
        file_display(fp, arr, n);
        printf("\nEnter the element to be searched)::");
        scanf("%d", &key);
        fprintf(fp, "\nThe element to be searched is :: %d\n", key);
        start = clock();
        ind = binary_search(arr, n, key);
        end = clock();
        total = (double)(end - start);
        if (ind == -1)
        {
            printf("Element not found\n");
            fprintf(fp, "Element not found\n");
        }
        else
        {
            printf("Element found at index %d\n", ind);
            fprintf(fp, "Element found at index %d\n", ind);
        }
        printf("Execution time is %li \n", (long int)total);
        fprintf(fp, "Execution time is %li \n", (long int)total);
        fclose(fp);
        break;

    case 3:
        fp = fopen("D://ALL  PROGRAMS/FILE HANDLING/interpolation.txt", "a");
        fprintf(fp, "Array of random input/unsorted array\n");
        file_display(fp, arr, n);
        quick_sort(arr, 0, n - 1);
        printf("sorted array\n");
        display(arr, n);
        fprintf(fp, "Sorted array..........\n");
        file_display(fp, arr, n);
        printf("\nEnter the element to be searched)::");
        scanf("%d", &key);
        fprintf(fp, "\nThe element to be searched  in uniform data is :: %d\n", key);
        start = clock();
        ind = interpolation_search(arr, n, key);
        end = clock();
        total = (double)(end - start);
        if (ind == -1)
        {
            printf("Element not found\n");
            fprintf(fp, "Element not found\n");
        }
        else
        {
            printf("Element found at index %d\n", ind);
            fprintf(fp, "Element found at index %d\n", ind);
        }
        printf("Execution time  for uniform data is %li \n", (long int)total);
        fprintf(fp, "Execution time for uniform data  %li \n", (long int)total);
        arr[n - 1] = 100000000; //making data non-uniform.
        arr[n - 3] = 1000000;
        start = clock();
        interpolation_search(arr, n, key);
        end = clock();
        total = (double)(end - start);
        printf("Execution time  for non-uniform data is %li \n", (long int)total);
        fprintf(fp, "Execution time for non-uniform data  %li \n", (long int)total);
        fclose(fp);
        break;
    case 4:
        exit(0);
    default:
        printf("\nWrong Choice!!");
    }

    free(arr);
    return 0;
}