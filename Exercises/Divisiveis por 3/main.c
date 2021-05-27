#include <stdio.h>
#include <stdlib.h>

void main()
{

  int PrimeiroNumero = 0, SegundoNumero = 0, i, Divisiveis = 0;

  printf("============================================================================================\n                            Boas vindas ao CHEQUE OS MULTIPLOS DE 3\nPara comecar, indique um intervalo de numeros inteiros para calcular\n\nPrimeiro Numero: ");

  scanf("%i", &PrimeiroNumero);
  printf("\nSegundo numero: ");
  scanf("%i", &SegundoNumero);
  printf("\n");

  if (PrimeiroNumero > SegundoNumero)
  {
    printf("\nTu nao podes passar o primeiro numero sendo maior que o primeiro :(");
    return;
  }

  for (i = PrimeiroNumero; i <= SegundoNumero; i++)
  {
    if (i != 0)
    {
      int temp = i / 3;
      int test = temp * 3;

      if (test == i)
      {
        Divisiveis++;
        printf("%i,", i);
      }
    }
  }

  if (Divisiveis > 0)
    printf("\n\nEntre %i e %i, %i numeros sao divisiveis por 3!\n", PrimeiroNumero, SegundoNumero, Divisiveis);
  else
    printf("\n\nNenhum numero entre %i e %i eh divisivel por 3\n", PrimeiroNumero, SegundoNumero);

  printf("\n\n============================================================================================\n");
  system("pause");
}