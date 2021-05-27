# Divisíveis por 3

## Proposta

Neste trabalho, o sor pediu para fazermos um programa que:

- Recebe um intervalo de dois números do usuário
- Calcula quantos desses números são divisíveis por 3
- Printa na tela quantos números e quais são eles

> Nesta atividade não poderia utilizar o "%" para a divisão, pois não havíamos aprendido

## Resolução

Todo o código é feito em somente uma função `main`. Ela é do tipo `void`, então não preciso retornar nenhum valor.

Começo declarando quatro variáveis do tipo `int` para armazenar:

- O primeiro número do intervalo
- O segundo número do intervalo
- Auxilar no laço for
- Armazenar a quantidade de números divisíveis por 3

As primeiras funções chamadas são as `printf` e `scanf`. Com `printf` eu falo o que o usuário deve fazer, e com `scanf` eu recebo o input do usuário.

```c
scanf("%i", &PrimeiroNumero);
```

^^^ A função scanf recebe dois parâmetros, o tipo de entrada, e o _endereço_ da variável para armazenar o input. O tipo do input é passado assim como se fosse num printf, com `%i`, o I é de int. No segundo parâmetro eu insiro `&PrimeiroNumero`, PirmeiroNumero é o nome da variável, e o `&` antes dela faz com que eu pegue somente o endereço dessa variável.
Nas Próximas linhas eu faço uma checagem para ver se o número dos intervalos é válido. Então, _Se (primeiro numero) for maior que (segundo numero) printe ("....") e então, retorne a função_. Eu gosto de ler dessa forma meus códigos para entender melhor a lógica.

Passado disso entramos em um loop for, que usa o primeiro número como base, e enquanto esse numero for menor ou igual ao segundo número, repita tudo entre isso, e a cada fim de repetição, some um ao primeiro numero.
No loop a primeira coisa que eu faço é checar se o `i` é zero, pois se for, não quero utilizar ele.
Dentro do for eu crio dois inteiros, `temp` e `test`. Temp recebe o valor de `i / 3`. Já a test recebe o valor de `temp * 3`. Desse jeito, caso a variável _i_ não for um divisível por 3, o valor vai ser um número com vírgula, diferente do i, então ele não passaria pelo próximo if, o _se test for igual a i_. Se ele for igual, ele adiciona 1 na variável divisíveis, e printa o valor que é divisível por 3 na tela,

Ao fim do loop, ele vai fazer mais um if: _se divisíveis for maior que 0_ ele vai printar os números divisíveis, caso contrário, ele vai printar que nenhum número é divisível por 3. Por fim, o programa vai executar um comando do `system` (sistema) que é o `pause` que faz com que o console pare, dando tempo para o usuário ler o resultado caso ele abra o binário executável direto.
