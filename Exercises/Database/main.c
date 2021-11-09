#include <stdio.h>

 struct AlunoData {
        char nome [80];
        int idade;
        float altura;
        char sexo;
} aluno;

FILE *fp;

void clear(){
system("cls");
}

int main(void) {

    fp= fopen("data/alunos.db", "a+b");

    printf("\n\n===========================================================\n              Banco de Dados Liberato\n\nQual a query de hoje?\n\n");
    printf("(i) - Pesquisar por idade\n(a) - Pesquisar por altura\n(s) - Pesquisar por sexo\n(n) - Pesquisar por nome\n(+) - Adicionar Dados\n(0) - Sair Do Programa\n\n");

    char operation;

    fflush(stdin);
    scanf("%c", &operation);

    switch(operation) {
        case '0': {
           return 0;
        }
        case '+': {
            addData();
            break;
        }
        case 'i': {
            searchByAge();
            break;
        break;
        }
        default: {
            clear();
            printf("\n\nESTA OPERACAO AINDA NAO FOI IMPLEMENTADA");
            return main();
        }
    }
    clear();
    main();

}

void searchByAge() {
    clear();

    char operation;

    printf("Qual a forma de pesquisa de idades?\n\n(b) - Todas idades entre dois valores\n(m) - Todas idades maiores que um valor\n(n) - Todas as idades menores que um valor\n(0) - Cancelar");

    scanf("%c", &operation);

    switch(opeartion){
        case '0': return;

        case 'b': {

        // TODO: all alunos queries
        struct AlunoData alunossss;

        }

    default: return;
    }

}

void addData() {
    fflush(stdin);
    clear();
    int toSearch = 0;

    printf("Quantos alunos voce vai acrescentar? \n0 para cancelar\n");
    scanf("%i", &toSearch);

       for (int i = toSearch; i > 0; i--) {
        fflush(stdin);
        printf("\nNome do aluno\n");
        gets(aluno.nome);
        printf("\nIdade do Aluno\n");
        scanf("%i", &aluno.idade);
        printf("\Altura\n");
        scanf("%f", &aluno.altura);
        fflush(stdin);
        printf("\nSexo do Aluno\n");
        scanf("%c", &aluno.sexo);
        fwrite(&aluno, sizeof aluno, 1, fp);
    }
}
