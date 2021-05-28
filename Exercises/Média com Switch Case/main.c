#include <stdio.h>
#include <stdlib.h>

int main()
{
  float nota_um, nota_dois, nota_tres;

  printf("Digite 3 notas do aluno para calcular a media\n");

  printf("Primeira nota: ");
  scanf("%f", &nota_um);

  printf("\nSegunda nota: ");
  scanf("%f", &nota_dois);

  printf("\nTerceira nota: ");
  scanf("%f", &nota_tres);

  if (nota_um < 0 || nota_um > 10 || nota_dois < 0 || nota_dois > 10 || nota_tres < 0 || nota_tres > 10 || !nota_um || !nota_dois || !nota_tres)
  {
    printf("\nUma nota que digitastes nao esta no intervalo de 0 a 10");
    return 1;
  }

  int media = (nota_um + nota_dois + nota_tres) / 3;

  printf("\n\n=====================================================\n");
  printf("A media do aluno foi %i", media);

  switch (media)
  {
  case 0:
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
    printf("\nO MLK RODO MANOKKKK INSUFICIENTE PRA TI MANITO");
    break;
  case 6:
  case 7:
    printf("\nESCUTA AQUI SEU MEDIOCRE, PASSASTES NAQUELAS EIN, mas passou manito, congratulations");
    break;
  case 8:
  case 9:
  case 10:
    printf("\nBAAAAAH TU EH O BOM ENTAO. TU EH O EINSTEIN. EXCELENTE MLK");
  }

  return 0;
}