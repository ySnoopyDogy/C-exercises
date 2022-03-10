#include <stdio.h>

void ordena(int *n1, int *n2, int *n3, char ordem)
{
  printf("%i, %i, %i", n1, &n2, *n3);
  int x = 0, y = 0, c = 0;

  if (ordem == 'c')
  {
    if (*n1 > *n2)
    {
      c = *n1;
      *n1 = *n2;
      *n2 = c;
    }
    if (*n2 > *n3)
    {
      c = *n2;
      *n2 = *n3;
      *n3 = c;
    }
    if (*n1 > *n2)
    {
      c = *n1;
      *n1 = *n2;
      *n2 = c;
    }
    printf("%i eh n1 %i eh n2 %i eh n3\n\n", *n1, *n2, *n3);
  }
  if (ordem == 'd')
  {
    if (*n1 < *n2)
    {
      c = *n1;
      *n1 = *n2;
      *n2 = c;
    }
    if (*n2 < *n3)
    {
      c = *n2;
      *n2 = *n3;
      *n3 = c;
    }
    if (*n1 < *n2)
    {
      c = *n1;
      *n1 = *n2;
      *n2 = c;
    }

    printf("%i eh n1 %i eh n2 %i eh n3\n\n", *n1, *n2, *n3);
  }
}

int main()
{

  int *n1, *n2, *n3;
  char ordem;
  printf("coloque a ordem\n\n");
  fflush(stdin);
  scanf("%c", &ordem);

  printf("coloque o valor de n1, n2 e n3\n\n");
  fflush(stdin);
  scanf("%i", &n1);
  fflush(stdin);
  scanf("%i", &n2);
  fflush(stdin);
  scanf("%i", &n3);
  fflush(stdin);
  ordena(&n1, &n2, &n3, ordem);
  printf("%i eh n1 %i eh n2 %i eh n3\n\n", *n1, *n2, *n3);
  return 0;
}