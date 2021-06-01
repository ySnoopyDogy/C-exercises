#include <stdio.h>

int main()
{

  char str[100];
  char letra;
  int repetidas = 0;

  printf("Digite uma frase\n");
  gets(str);
  printf("\nAgora, digite um caractere para buscar: ");
  scanf("%c", &letra);

  printf("\n");

  for (int i = 0; i < 100; i++)
  {
    if (str[i] == '\0')
      break;

    if (str[i] == letra)
      repetidas++;
  }

  printf("O caractere %c aparece %i vezes na sua string", letra, repetidas);
  return 0;
}