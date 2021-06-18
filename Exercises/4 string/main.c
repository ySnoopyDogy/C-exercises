#include <stdio.h>

int main()
{
  char string[50];
  int i = 0;

  printf("Escreva uma frase: ");
  gets(string);

  while (string[i] != '\0')
  {
    if (string[i] >= 97)
      string[i] -= 32;
    i++;
  }

  printf("\n\nToUpperCase: %s", string);
  return 0;
}