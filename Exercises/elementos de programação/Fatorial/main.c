#include <stdio.h>

int calculaFatorial(int numero)
{
  int fatorial = 1;

  for (int i = numero; i > 0; i--)
  {
    fatorial *= i;
  }

  return fatorial;
}

int main()
{
  // Valor para o Fatorial
  int ValorToFatorial = 3;

  int FatorialCalculado = calculaFatorial(ValorToFatorial);
  printf("Fatorial de %i = '%i'\n", ValorToFatorial, FatorialCalculado);

  return 0;
}