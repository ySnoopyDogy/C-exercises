#include <stdio.h>
#include <stdlib.h>

void main()
{

  char choice;

  float first_number, second_number, result;

  printf("=====================================================\nTecle de acordo com sua escolha:");

  do
  {
    fflush(stdin); // Função secretinha pra limpar a entrada
    printf("\n(M) Multiplicar\n(D) Dividir\n(A) Adicao\n(S) Subtrair\n(Q) Finalizar o programa\n");
    scanf("%c", &choice);

    if (choice == 'q')
      return;

    printf("\nSelecione o primeiro numero da operacao: ");
    scanf("%f", &first_number);

    printf("\nSelecione o segundo numero da operacao: ");
    scanf("%f", &second_number);

    switch (choice)
    {
    case 'm':
      result = first_number * second_number;
      printf("\n%.2f * %.2f = %.2f\n", first_number, second_number, result);
      break;
    case 'd':
      result = first_number / second_number;
      printf("\n%.2f / %.2f = %.2f\n", first_number, second_number, result);
      break;
    case 'a':
      result = first_number + second_number;
      printf("\n%.2f + %.2f = %.2f\n", first_number, second_number, result);
      break;
    case 's':
      result = first_number - second_number;
      printf("\n%.2f - %.2f = %.2f\n", first_number, second_number, result);
      break;
    default:
      printf("Essa escolha nao eh valida, tente novamente");
    }

  } while (choice != 'q');
}