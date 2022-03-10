#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MATRIX_MAX 6

int main()
{
  int a[MATRIX_MAX][MATRIX_MAX], colls[MATRIX_MAX], lines[MATRIX_MAX];
  populateMatrix(a);

  addMatrix(a, colls, lines);

  printResult(colls, lines);
  return 0;
}

void printResult(int colls[MATRIX_MAX], int lines[MATRIX_MAX])
{
  printf("Soma das Colunas: [");
  for (int i = 0; i < MATRIX_MAX; i++)
  {
    printf("%i, ", colls[i]);
  }
  printf("]");

  printf("\n\nSoma das Linhas: [");
  for (int i = 0; i < MATRIX_MAX; i++)
  {
    printf("%i, ", lines[i]);
  }
  printf("]");
}

void addMatrix(int matrix[MATRIX_MAX][MATRIX_MAX], int colls[MATRIX_MAX], int lines[MATRIX_MAX])
{

  for (int i = 0; i < MATRIX_MAX; i++)
  {
    colls[i] = 0;

    for (int j = 0; j < MATRIX_MAX; j++)
    {

      if (j == 0)
      {
        lines[i] = 0;
        colls[i] = 0;
      }

      lines[i] += matrix[i][j];
      colls[i] += matrix[j][i];
    }
  }
}

void populateMatrix(int matrix[MATRIX_MAX][MATRIX_MAX])
{
  srand(time(NULL)); // Seta uma seed pro rand

  for (int i = 0; i < MATRIX_MAX; i++)
  {
    for (int j = 0; j < MATRIX_MAX; j++)
    {
      matrix[i][j] = rand() % 100;
    }
  }
}