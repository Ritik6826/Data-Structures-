#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  srand(time(0));
  int **mat1, **mat2, **result, r1, r2, c1, c2;
  printf("Enter the  number of rows and colums for mat1\n");
  scanf("%d%d", &r1, &c1);
  printf("Enter the  number of rows and colums for mat2\n");
  scanf("%d%d", &r2, &c2);
  if (c1 == r2)
  {
    mat1 = (int **)malloc(r1 * sizeof(int *));
    for (int i = 0; i < r1; i++)
    {
      mat1[i] = (int *)malloc(c1 * sizeof(int));
    }
    mat2 = (int **)malloc(r2 * sizeof(int *));
    for (int i = 0; i < r2; i++)
    {
      mat2[i] = (int *)malloc(c2 * sizeof(int));
    }

    for (int i = 0; i < r1; i++)
    {
      for (int j = 0; j < c1; j++)
      {
        mat1[i][j] = rand() % 10;
      }
    }
    for (int i = 0; i < r2; i++)
    {
      for (int j = 0; j < c2; j++)
      {
        mat2[i][j] = rand() % 10;
      }
    }

    printf("\nMatrix one is :\n");
    for (int i = 0; i < r1; i++)
    {
      for (int j = 0; j < c1; j++)
      {
        printf("%d  ", mat1[i][j]);
      }
      printf("\n");
    }
    printf("\nMAtrix two is :\n");
    for (int i = 0; i < r2; i++)
    {
      for (int j = 0; j < c2; j++)
      {
        printf("%d  ", mat2[i][j]);
      }
      printf("\n");
    }
    result = (int **)malloc(r1 * sizeof(int *));
    for (int i = 0; i < r1; i++)
    {
      result[i] = (int *)malloc(c2 * sizeof(int));
    }
    for (int i = 0; i < r1; i++)
    {
      for (int j = 0; j < c2; j++)
      {
        result[i][j] = 0;
        for (int k = 0; k < c1; k++)
        {
          result[i][j] = result[i][j] + mat1[i][k] * mat2[k][j];
        }
      }
    }

    printf("\nResultant matrix is :\n");
    for (int i = 0; i < r1; i++)
    {
      for (int j = 0; j < c2; j++)
      {
        printf("%d  ", result[i][j]);
      }
      printf("\n");
    }
  }
  else
  {
    printf("Can't do multiplication\n");
  }

  return 0;
}