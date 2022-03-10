# 3 Exercícios Sobre Strings

## Proposta

O sor entregou uma lista com 12 exercícios, e éramos pra resolver somente a 1 a 2 e a 3, elas eram todas sobre strings, e não poderia usar funções da lib `<string.h>`. Eramos pra usar funções, então separei meus três exercícios por funções.

1. Escrever um programa que lê uma string e a escreve. Através de uma função, escrever a mesma string em ordem inversa.

2. Escrever um programa que lê duas strings e informa o tamanho, a igualdade entre elas e no final escrever as strings concatenadas.

3. Escrever um programa que lê uma string s\[30\]. Uma função deve escrever cada palavra desta string numa nova linha.

## Resolução

Vamos lá, na minha `main` eu chamei 3 funções, dividindo elas por prints dizendo qual é cada exercício. Cada função é um exercício diferente. Comecaremos pelo exercicio um.

### Exercício 1

```c
char string[50];
printf("Entre com uma string de limite 50\n");
gets(string);
printf("\nSua string eh: %s", string);
inverte_e_mostra(string);
```

Eu começo criando um array de char de 50 valores, que será minha `string`. Em seguida, executo o `gets`, que recebe como parâmetro um vetor de char. Essa função é um `scanf` de strings, basicamente. Como pedido no primeiro exercício, eu mostro na tela qual é a string, e em seguida chamo minha função para inverter.

A função `inverte_e_mostra` é do tipo `void` e recebe um array como parâmetro, A primeira coisa que ela faz é criar um `int` chamado strle, que chama a função `tamanhoDaString`. Vamos ver o que essa função faz antes de continuar.

```c
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
```

A tamanhoDaString é uma função que retorna um `int` e recebe uma string como parâmetro, ela primeiro cria uma variável chamada `tamanho` que vai armazenar o tamanho de nossa string. Então, eu crio um laço **for** para loopar por toda minha string. Coloquei para loopar 255 vezes, ja que a string terá menos que isso. Dentro do for, ele faz uma checagem para saber se está no fim da string, já que o último valor de uma string sempre é `\0`, eu checko que o valor de `str` atual, ou seja, `str[a]` é '\0', como `a` é minha variável do loop, ele sempre vai aumentar o valor de acordo com o loop. Caso o valor de `str[a]` for '\0', o loop vai breakar, ou seja, o código vai pular pra fora do loop. E caso ele não pule, ele vai aumentar o valor de `tamanho` em +1. Assim, quando passar por toda string, tamanho vai ser a quantidade de char da string, ou seja, o tamanho da string. Retorno isso para a função com `return tamanho`.

Agora que temos strlen, eu posso criar um loop para correr por toda string. A leitura do loop ficou assim: **i é igual a 0, e enquanto i for igual à metade do tamanho da string, some 1 à i**. Eu peço somente à metade do tamnho da String pois para inverter uma string só precisamos passar metade dos caracteres para depois do meio. para invertermos a string, faremos um processo chamado `swap`, que só vamos swapar os chars. Então criaremos uma variável temporaria com o caracter atual, em seguida settaremos o caractere atual com a localização inversa da string desse caracter, e por fim, vamos colocar o caractere aual na localização da inversa. E pronto, esse foi o swap. Como não é possível retornar uma função com um vetor, vamos printar direto na função inverte, por isso que é chamada de inverte_e_mostra. Printamos a invertida e ta lá, primeira questão Resolvida!

### Exercício 2

Agora pro segundo exercício, vamos primeiro criar dois arrays com tamanho 50 cada um, e fazer `gets` para pegar o valor de cada array. Usarmos a função já explicada `tamanhoDaString` para pegar o tamanho de cada uma das duas strings, e vamos armazenar isso em inteiros. Como pedido pela questão, printaremos o tamanho de cada string, e em seguida, vamos concatená-las. (Concatenar é uma palavra bonita para juntar).

```c
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

  conc_strings[strleng1 + strleng2] = str2[strleng2];

  printf("\nA concatenacao das strings eh: %s", conc_strings);
}
```

A função `concatena_e_mostra` é do tipo `void`, ou seja, não vai retornar nenhum valor, e ela recebe 4 parâmetros, duas strings, e o tamanho dessas strings.
Na primeira linha criamos uma nova string com 100 de tamanho. Para juntarmos as duas strings não tem segredo, vamos loopar entre as duas strings, e ir adicionando na nova.
O primeiro **for** loopa entre toda string 1, e armazena na `conc_strings`, o segundo **for** loopa entre toda a segunda string, e na hora de adicionar na conc_strings, ele leva em consideração o tamanho da primeira string, para adicionar os caracteres depois da primeira. Depois dos dois loops, eu adiciono o '\0' no fim da string para settar que aquele é o final. Para terminar a questão, printo na tela o resultado da concatenação.

### Exercício 3

O exercício 3 pede para que o usuário digite uma string de no máximo 30 caracteres, que vai ser armazenada no `char s[30]` com a função `gets`. Então, chamamos a função `escreve_palavras` que fará a escrita de cada palavra da string em uma linha diferente.

```c
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
```

A função `escreve_palavras` recebe a string, e logo no início já armazenamos o tamanho dela no `int tamanhoString` a partir da nossa função `tamanhoDaString`. Então, com um laço **for** eu passo por todos caracteres da string, e verifico se o caractere atual for um espaço em branco (_' '_), se for, printamos uma nova linha, caso contrario, printamos cada caractere na linha atual. Na minha opinião essa foi a questão mais fácil.
