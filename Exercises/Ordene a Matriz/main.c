#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int a[6][6], b[36];

  populateMatrix(a);
  ordenar(a, b);
  return 0;
}

void transpileToArray(int a[6][6], int b[36])
{
  int k = 0;

  for (int i = 0; i < 6; i++)
  {
    for (int j = 0; j < 6; j++)
    {
      b[k] = a[i][j];
      k += 1;
    }
  }
}

void ordenar(int a[6][6], int b[36])
{
  int temp, ordenado[6][6];
  transpileToArray(a, b);

  for (int i = 0; i < 36; i++)
  {
    for (int j = 0; j < (35 - i); j++)
    {
      if (b[j] > b[j + 1])
      {
        temp = b[j];
        b[j] = b[j + 1];
        b[j + 1] = temp;
      }
    }
  }

  int k = 0;
  for (int i = 0; i < 6; i++)
  {
    for (int j = 0; j < 6; j++)
    {
      ordenado[i][j] = b[k];
      k++;
    }
  }

  printf("Matriz Antiga:\n");
  for (int i = 0; i < 6; i++)
  {
    for (int j = 0; j < 6; j++)
    {
      printf("[%i][%i] = %i\t", i, j, a[i][j]);
    }
    printf("\n");
  }

  printf("Matriz ordenada:\n");
  for (int i = 0; i < 6; i++)
  {
    for (int j = 0; j < 6; j++)
    {
      printf("[%i][%i] = %i\t", i, j, ordenado[i][j]);
    }
    printf("\n");
  }
}

void populateMatrix(int a[6][6])
{
  srand(time(NULL));

  for (int i = 0; i < 6; i++)
  {
    for (int j = 0; j < 6; j++)
    {
      a[i][j] = rand() % 50;
    }
  }
}