#include <stdio.h>

int main()
{

  float oposto, adjacente, hipotenusa;

  printf("Digite os valores do triangulo. Utilize 0 como o seu X\n\nCateto Oposto: ");
  scanf("%f", &oposto);

  printf("\nCateto Adjacente: ");
  scanf("%f", &adjacente);

  printf("\nHipotenusa: ");
  scanf("%f", &hipotenusa);

  int res = triangulo_retangulo(&oposto, &adjacente, &hipotenusa);
  if (res == 0)
    printf("\n\nCateto Oposto: %.1f\nCateto Adjacente: %.1f\nHipotenusa: %.1f", oposto, adjacente, hipotenusa);
  else
    printf("Erro de Parametro");

  return res;
}

int triangulo_retangulo(float *oposto, float *adjacente, float *hipotenusa)
{
  if (*oposto != 0 && *adjacente != 0 && *hipotenusa != 0)
    return -1;

  if (*oposto == 0 && (*adjacente == 0 || *hipotenusa == 0))
    return -1;

  if (*adjacente == 0 && (*oposto == 0 || *hipotenusa == 0))
    return -1;

  if (*hipotenusa == 0 && (*adjacente == 0 || *oposto == 0))
    return -1;

  if (*oposto == 0)
  {
    *oposto = sqrt(pow(*hipotenusa, 2) - pow(*adjacente, 2));
    return 0;
  }

  if (*adjacente == 0)
  {
    *adjacente = sqrt(pow(*hipotenusa, 2) - pow(*oposto, 2));
    return 0;
  }

  *hipotenusa = sqrt(pow(*adjacente, 2) + pow(*oposto, 2));
  return 0;
}