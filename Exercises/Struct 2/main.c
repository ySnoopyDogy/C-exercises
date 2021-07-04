#include <stdio.h>

struct notas
{
  float prova1;
  float prova2;
  float prova3;
};

struct aluno
{
  unsigned int matricula;
  char nome[50];
  struct notas notas;
} alunos[20];

int main()
{
  int registredAlunos = listenToInputs();
  highestGrade(registredAlunos);
  calculateAverage(registredAlunos);
  finaljudgment(registredAlunos);

  return 0;
}

void finaljudgment(int alunosCount)
{
  printf("\n\nBOLETIM FINAL\n-----------------------------\n");
  for (int i = 0; i < alunosCount; i++)
  {
    float alunoMedia = (alunos[i].notas.prova1 + alunos[i].notas.prova2 + alunos[i].notas.prova3) / 3;

    printf("ALUNO: %s (%i)", alunos[i].nome, alunos[i].matricula);
    printf("\nMEDIA: %.2f", alunoMedia);

    (alunoMedia < 6) ? printf("\nRESULTADO: Reprovado\n\n") : printf("\nRESULTADO: Aprovado!\n\n");
  }
}

void calculateAverage(int alunosCount)
{
  struct averages
  {
    int index;
    float average;
  };

  struct AverageAlunos
  {
    struct averages lowestAverage;
    struct averages highestAverage;
  } average;

  // Initialize
  average.highestAverage.average = 0.00;
  average.lowestAverage.average = 10.00;

  for (int i = 0; i < alunosCount; i++)
  {
    float media = (alunos[i].notas.prova1 + alunos[i].notas.prova2 + alunos[i].notas.prova3) / 3;
    if (media > average.highestAverage.average)
    {
      average.highestAverage.average = media;
      average.highestAverage.index = i;
    }
    if (media < average.lowestAverage.average)
    {
      average.lowestAverage.average = media;
      average.lowestAverage.index = i;
    }
  }

  printf("\n\nMEDIAS\n---------------------\nMaior Media:\nALUNO: %s\nNOTAS: %.2f, %.2f, %.2f\nMEDIA: %.2f", alunos[average.highestAverage.index].nome, alunos[average.highestAverage.index].notas.prova1, alunos[average.highestAverage.index].notas.prova2, alunos[average.highestAverage.index].notas.prova3, average.highestAverage.average);
  printf("\n---------------------\nMenor Media:\nALUNO: %s\nNOTAS: %.2f, %.2f, %.2f\nMEDIA: %.2f\n", alunos[average.lowestAverage.index].nome, alunos[average.lowestAverage.index].notas.prova1, alunos[average.lowestAverage.index].notas.prova2, alunos[average.lowestAverage.index].notas.prova3, average.lowestAverage.average);
}

void highestGrade(int alunosCount)
{
  struct HighestProva
  {
    int index;
    float nota;
  } pv1, pv2, pv3;

  // Initialize

  pv1.nota = 0.00;
  pv2.nota = 0.00;
  pv3.nota = 0.00;

  for (int i = 0; i < alunosCount; i++)
  {
    if (alunos[i].notas.prova1 > pv1.nota)
    {
      pv1.nota = alunos[i].notas.prova1;
      pv1.index = i;
    }
    if (alunos[i].notas.prova2 > pv2.nota)
    {
      pv2.nota = alunos[i].notas.prova2;
      pv2.index = i;
    }
    if (alunos[i].notas.prova3 > pv3.nota)
    {
      pv3.nota = alunos[i].notas.prova3;
      pv3.index = i;
    }
  }

  printf("\n\nMAIORES NOTAS NAS PROVAS\n----------------------\nProva 1:\nALUNO: %s (%i)\nNOTA: %.2f", alunos[pv1.index].nome, alunos[pv1.index].matricula, pv1.nota);
  printf("\n----------------------\nProva 2:\nALUNO: %s (%i)\nNOTA: %.2f", alunos[pv2.index].nome, alunos[pv2.index].matricula, pv2.nota);
  printf("\n----------------------\nProva 3:\nALUNO: %s (%i)\nNOTA: %.2f", alunos[pv3.index].nome, alunos[pv3.index].matricula, pv3.nota);
}

int listenToInputs()
{
  char choice;
  int listenedAlunos = 0;

  printf("Vamos comecar recebendo os dados dos alunos\n");

  do
  {
    fflush(stdin);

    if (listenedAlunos != 0)
    {
      printf("Deseja parar de adicionar dados? (s/N)");
      scanf("%c", &choice);

      if (choice == 's')
        break;
    }

    printf("\nQual a matricula do aluno?\n");
    scanf("%i", &alunos[listenedAlunos].matricula);

    fflush(stdin);
    printf("\nQual o nome deste aluno?: ");
    gets(alunos[listenedAlunos].nome);

    printf("\nAgora, entre as 3 notas deste aluno, separado por espacos\n");
    scanf("%f %f %f", &alunos[listenedAlunos].notas.prova1, &alunos[listenedAlunos].notas.prova2, &alunos[listenedAlunos].notas.prova3);

    listenedAlunos++;

  } while (listenedAlunos < 20);

  printf("\n=====================================\n");
  return listenedAlunos;
}
