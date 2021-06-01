# Contando Caracteres

## Proposta

O professor pediu pra criar um programa, solicitar para o usuário digitar uma frase.
Solicitar ao usuário que digite um caracter.
Contar quantas vezes esse caracter aparece dentro da string digitada.

## Resolução

Vou realizar tudo na função `main()`. Começo declarando 3 variáveis, um array de `char`, um `char` e um `int`. Logo, printo na tela para o usuário digitar uma frase, e pego o input dele com a funçãop `gets` que recebe o Array como parâmetro. Depois disso, peço para ele digitar um caractere para procurar na string, e armazeno na variável `letra`.
Para saber quantas letras existem nessa string, é so eu loopar por tudo e verificar se ela é a letra.

```c
 for (int i = 0; i < 100; i++)
  {
    if (str[i] == '\0')
      break;

    if (str[i] == letra)
      repetidas++;
  }
```
Eu crio um if dentro do for pra verificar se a string já acabou, se sim, eu saio do for com `break`. O segundo if é pra verificar se a letra do loop é igual à letra escolhida pelo usuário, se ela for, ele vai incrementar no valor de `repetidas`. Ao fim, printo quantos caracteres possui na string do usuário, e retorno `0` para a função main dizendo que tudo ocorreu bem.
