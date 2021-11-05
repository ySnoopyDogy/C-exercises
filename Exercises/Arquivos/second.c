#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *fp;

int execution()
{
  char string[30];
  puts("\n\nDigite uma string de no maximo 30 caratceres\n");

  fgets(string, 30, stdin);

  for (int i = 0; string[i] != '\0'; i++)
  {
    if (string[i] == ' ')
      putc('\n', fp);
    else
      putc(string[i], fp);
  }
}

int main(void)
{
  char name[20];
  printf("Digite o nome do arquivo de no maximo 20 caracteres\n");
  fgets(name, 20, stdin);

  strcat(name, ".txt");
  fp = fopen(name, "wt");

  execution();

  fclose(fp);
}