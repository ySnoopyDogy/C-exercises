#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *fp;

int execution()
{
  char toWrite[254];
  puts("\n\nDigite uma string de no maximo 254 caratceres\n");

  fgets(toWrite, 254, stdin);

  for (int i = strlen(toWrite); i >= 0; i--)
  {
    if (toWrite[i] == '\0')
      continue;
    putc(toWrite[i], fp);
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