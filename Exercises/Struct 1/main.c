#include <stdio.h>

struct dma
{
  int dia;
  int mes;
  int ano;
} data1, data2;

int main()
{
  printf("Entre com a primeira data no esquema: 'dd mm aaaa' exemplo: 12 5 2019\n");
  scanf("%i %i %i", &data1.dia, &data1.mes, &data1.ano);

  printf("\nAgora passe a segunda data para contar os dias, mesmo esquema 'dd mm aaaa'\n");
  scanf("%i %i %i", &data2.dia, &data2.mes, &data2.ano);

  if (!data1.dia || !data1.mes || !data1.ano)
    return ThrowError("Sua primeira data eh invalida");
  if (!data2.dia || !data2.mes || !data2.ano)
    return ThrowError("Sua segunda data eh invalida");

  if (data1.dia < 1 || data1.dia > 31)
    return ThrowError("O dia na primeira data eh invalido");
  if (data1.mes < 1 || data1.mes > 12)
    return ThrowError("O mes na primeira data eh invalido");
  if (data2.dia < 1 || data2.dia > 31)
    return ThrowError("O dia na segunda data eh invalido");
  if (data2.mes < 1 || data2.mes > 12)
    return ThrowError("O mes na segunda data eh invalido");

  calcDate();
}

void calcDate()
{

  int diasDosMeses[12] = {31,
                          28,
                          31,
                          30,
                          31,
                          30,
                          31,
                          31,
                          30,
                          31,
                          30,
                          31};

  // Calcular Bissexto

  int bissextos = 0;

  for (int i = data1.ano; i <= data2.ano; i++)
  {
    if (i % 4 == 0 && data2.mes >= 2)
      bissextos++;
  }

  // Calcular Dias

  int diasPelosMeses = 0;

  for (int i = data1.mes; i < data2.mes; i++)
  {
    diasPelosMeses += diasDosMeses[i - 1];
  }

  //resto
  int anoDiff = data2.ano - data1.ano;
  int diaDiff = data2.dia - data1.dia;

  int totalDias = ((anoDiff * 365) + (bissextos)) + (diasPelosMeses) + diaDiff;

  if (totalDias < 0)
    totalDias *= -1;

  printf("\nA diferenca de dias entre %i/%i/%i e %i/%i/%i eh de %i dias", data1.dia, data1.mes, data1.ano, data2.dia, data2.mes, data2.ano, totalDias);
  printf("\nLembrando que este numero nao eh exato, uma vez que este algoritmo nao leva em conta meses como fevereiro, e os que vao ate 31, nem anos bissextos");
}

int ThrowError(char ErrorMessage[])
{
  printf("\n\nPrograma Encerrado\n======================\nError: %s", ErrorMessage);
  return 136;
}