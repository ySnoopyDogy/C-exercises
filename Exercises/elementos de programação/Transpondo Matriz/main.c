#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int a[5][5], transposta[5][5];

  populateMatrix(a);
  transporMatriz(a, transposta);
  showResult(a, transposta);
  return 0;
}

void showResult(int a[5][5], int b[5][5])
{
  printf("Matriz Antiga:\n");
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      printf("[%i][%i] = %i      ", i, j, a[i][j]);
    }
    printf("\n");
  }

  printf("Matriz Transposta:\n");
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      printf("[%i][%i] = %i      ", i, j, b[i][j]);
    }
    printf("\n");
  }
}

void transporMatriz(int a[5][5], int b[5][5])
{
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      b[i][j] = a[j][i];
    }
  }
}

void populateMatrix(int a[5][5])
{
  srand(time(NULL));

  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      a[i][j] = rand() % 50;
    }
  }
}