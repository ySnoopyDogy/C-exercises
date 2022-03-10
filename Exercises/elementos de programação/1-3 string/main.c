#include <stdlib.h>
#include <stdio.h>

int main()
{
  printf("=========================\nEXERCICIO 1\n");
  exercicioUm();
  printf("\n=========================\nEXERCICIO 2\n");
  exercicioDois();
  printf("\n=========================\nEXERCICIO 3\n");
  exercicioTres();
  return 0;
}

/* ------------ Exercícios -------------- */

void exercicioUm()
{
  char string[50];
  printf("Entre com uma string de limite 50\n");
  gets(string);
  printf("\nSua string eh: %s", string);
  inverte_e_mostra(string);
}

void exercicioDois()
{
  char first_string[50], second_string[50];
  printf("Entre com a primeira string de no maximo 50 caracteres:\n");
  gets(first_string);
  printf("\nEntre com a segunda string de no maximo 50 caracteres:\n");
  gets(second_string);

  int first_string_length = tamanhoDaString(first_string);
  int second_string_length = tamanhoDaString(second_string);

  printf("\nA primeira string tem %i caracteres de tamanho, e a segunda tem %i", first_string_length, second_string_length);
  concatena_e_mostra(first_string, second_string, first_string_length, second_string_length);
}

void exercicioTres()
{
  char s[30];

  printf("Digite uma frase de no maximo 30 caracteres\n");
  gets(s);

  escreve_palavras(s);
}

/* --------------- Funções usadas pros exercícios ------------------ */

void escreve_palavras(char string[])
{

  printf("\n");
  int tamanhoString = tamanhoDaString(string);

  for (int i = 0; i < tamanhoString; i++)
  {
    if (string[i] == ' ')
    {
      printf("\n");
    }
    else
    {
      printf("%c", string[i]);
    }
  }
}

void concatena_e_mostra(char str1[], char str2[], int strleng1, int strleng2)
{
  char conc_strings[100];

  for (int i = 0; i < strleng1; i++)
  {
    conc_strings[i] = str1[i];
  }
  for (int j = 0; j < strleng2; j++)
  {
    conc_strings[strleng1 + j] = str2[j];
  }

  conc_strings[strleng1 + strleng2] = '\0';

  printf("\nA concatenacao das strings eh: %s", conc_strings);
}

int tamanhoDaString(char str[])
{
  int tamanho = 0;
  for (int a = 0; a < 255; a++)
  {
    if (str[a] == '\0')
      break;
    tamanho++;
  }

  return tamanho;
}

void inverte_e_mostra(char str[])
{
  int strlen = tamanhoDaString(str);
  for (int i = 0; i < strlen / 2; i++)
  {
    char temp = str[i];
    str[i] = str[strlen - i - 1];
    str[strlen - i - 1] = temp;
  }

  printf("\nAo contrario, sua string eh: %s", str);
}