#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int rand();
void srand();

FILE *fp;

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
void display(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {

        printf("%d ", arr[i]);
    }

    printf("\n");
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Bubble_sort(int *arr, int n)
{

    for (int i = 0; i < n - 1; i++)
    {

        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
void Modified_Bubble_sort(int *arr, int n)
{

    int issorted = 0;

    for (int i = 0; i < n - 1; i++)
    {
        issorted = 1;
        //printf("%dth pass\n", i + 1);

        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                issorted = 0;
            }
           // display(arr, n);
        }
        if (issorted)
        {
            return;
        }
    }
}

void selection_sort(int *arr, int n)
{
    int min_index;
    for (int i = 0; i < n; i++)
    {
        min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
            {
                swap(&arr[j], &arr[min_index]);
            }
        }
    }
}

void cocktail_sort(int *arr, int n)
{
    int issorted = 0;
    for (int i = 0; i < n - 1; i++)
    {
        issorted = 1;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                issorted = 0;
            }
        }
        issorted = 1;
        for (int k = n - 1 - i; k > 0; k--)
        {
            if (arr[k] < arr[k - 1])
            {
                swap(&arr[k], &arr[k - 1]);
                issorted = 0;
            }
        }
        if (issorted)
        {
            return;
        }
    }
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
    int n, i, j, ch;
    clock_t start, end, total;
    printf("Enter the MAX limit of random number\n");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    random(arr, n);
    printf("Array before sorting\n");
    display(arr, n);

    printf("SORTING MENU........\n");
    printf("press 1 for bubble sort\npress 2 for modified bubble sort\npress 3 for selection sort\n");
    printf("press 4 for quicksort\npress 5 for cocktailsort\npress 6 to exit\n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        fp = fopen("D://ALL  PROGRAMS/FILE HANDLING/Bubble_sort.txt", "a");
        fprintf(fp, "UNsorted array :\n");
        file_display(fp, arr, n);
        start = clock();
        Bubble_sort(arr, n);
        end = clock();
        printf("Array after bubble sort\n");
        display(arr, n);
        fprintf(fp, "\n After bubble sort \n");
        file_display(fp, arr, n);
        total = (double)(end - start);
        printf("Execution time is %li \n", (long int)total);
        fclose(fp);
        break;
    case 2:
        fp = fopen("D://ALL  PROGRAMS/FILE HANDLING/modified bubblesort.txt", "a");
        fprintf(fp, "unsorted array :\n");
        file_display(fp, arr, n);
        start = clock();
        Modified_Bubble_sort(arr, n);
        end = clock();
        printf("Array after modified bubble sort\n");
        display(arr, n);
        fprintf(fp, "\n After bubble sort\n");
        file_display(fp, arr, n);
        total = (double)(end - start);
        printf("Execution time is %li \n",(long int) total);
        fclose(fp);
        break;
    case 3:
        fp = fopen("D://ALL  PROGRAMS/FILE HANDLING/selectionsort.txt", "a");
        fprintf(fp, "unsorted array :\n");
        file_display(fp, arr, n);
        start = clock();
        selection_sort(arr, n);
        end = clock();
        printf("Array after selection sort\n");
        display(arr, n);
        fprintf(fp, "Array after selection sort\n");
        file_display(fp, arr, n);
        total = (double)(end - start) ;
        printf("Execution time is %li \n", (long int)total);
        fclose(fp);
        break;
    case 4:
        fp = fopen("D://ALL  PROGRAMS/FILE HANDLING/quick_sort.txt", "a");
        fprintf(fp, "unsorted array :\n");
        file_display(fp,arr,n);
        start = clock();
        quick_sort(arr, 0, n - 1);
        end = clock();
        printf("Array after quick sort\n");
        display(arr, n);
        fprintf(fp, "Array  quick sort\n");
        file_display(fp, arr, n);
        total = (double)(end - start) ;
        printf("Execution time is %li \n", (long int)total);
        fclose(fp);
        break;
    case 5:
        fp = fopen("D://ALL  PROGRAMS/FILE HANDLING/cocktailsort.txt", "a");
        fprintf(fp, "unsorted array :\n");
        file_display(fp, arr, n);
        start = clock();
        cocktail_sort(arr, n);
        end = clock();
        printf("Array after cocktail sort\n");
        display(arr, n);
        fprintf(fp, "Array after cocktail sort\n");
        file_display(fp, arr, n);
        total = (double)(end - start) ;
        printf("Execution time is %li \n", (long int)total);
        fclose(fp);
        break;
    case 6:
        exit(0);
        break;
    default:
        printf("Try again!Enter a valid option\n");
    }

    free(arr);

    return 0;
}
