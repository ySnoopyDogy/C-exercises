#include <stdio.h>

int main()
{
  exercicioUm();
  printf("\n\n");
  exercicioDois();
  return 0;
}

void exercicioUm()
{
  char string[50];

  printf("Entre com uma palavra: ");
  gets(string);

  int numer = 0;

  for (int i = 0; i <= 50; i++)
  {
    if (string[i] == '\0')
      break;
    for (int j = 0; j <= 50; j++)
    {
      if (j > numer)
        break;
      if (string[j] == '\0')
        break;
      printf("%c", string[j]);
    }
    numer++;
    printf("\n");
  }
}

void exercicioDois()
{
  char string_to_copy[255];
  char string_to_paste[255];
  printf("Entre com a sua string para copiar: ");
  gets(string_to_copy);

  copia(string_to_copy, string_to_paste);
}

void copia(char str1[], char str2[])
{
  for (int i = 0; i < 256; i++)
  {
    str2[i] = str1[i];
    if (str1[i] == '\0')
      break;
  }
  printf("\nSua primeira String eh %s", str1);
  printf("\nA copia dela, adivinhe, eh %s", str2);
}