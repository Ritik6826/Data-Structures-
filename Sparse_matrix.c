#include <stdio.h>
#include <stdlib.h>
int main()
{

  int **mat, **sparse, r, c, count = 0, k = 1;
  printf("Enter the number of rows and columns of sparse matrix\n");
  scanf("%d%d", &r, &c);
  mat = (int **)malloc(r * sizeof(int *));
  for (int i = 0; i < r; i++)
  {
    mat[i] = (int *)malloc(c * sizeof(int));
  }
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      printf("Enter mat[%d][%d] ::", i, j);
      scanf("%d", &mat[i][j]);
    }
  }
  printf("\nSparse MAtrix ::\n");
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      printf("%d  ", mat[i][j]);
      if (mat[i][j] != 0)
      {
        count++;
      }
    }
    printf("\n");
  }
  sparse = (int **)malloc((count + 1) * sizeof(int *));
  for (int i = 0; i <=count; i++)
  {
    sparse[i] = (int *)malloc(3 * sizeof(int));
  }

  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {

      if (mat[i][j] != 0)
      {
        sparse[k][0] = i;
        sparse[k][1] = j;
        sparse[k][2] = mat[i][j];
        k++;
      }
    }
  }
  sparse[0][0] = r;
  sparse[0][1] = c;
  sparse[0][2] = k - 1;

  printf("\nSparse Matrix Triplet ::\n");
  printf("ROWS COLUMNS VALUES\n");
  for (int i = 0; i < k; i++)
  {

    for (int j = 0; j < 3; j++)
    {
      printf("%d\t",sparse[i][j]);
    }
    printf("\n");
  }

  return 0;
}