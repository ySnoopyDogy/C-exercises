# Calcular Média

## Proposta

Neste trabalho, o usuário deveria digitar 3 notas entre 0 e 10. Deveria se calcular a média da nota utilizando somente a parte inteira dela, e classificar a média utizando switch-case, onde se média <6 "insuficiente"
Se média maior ou igual a 6 e menor que 8 "mediocre"
e se média for maior ou igual a 8 "excelente"

## Resolução

Eu fiz tudo novamente somente na função main, começei criando três variáveis do tipo `float`, já que uma nota pode ser, por exemplo 6.3. Fiz alguns printf para dizer ao usuário o que fazer, e em seguida coloquei os `scanf` para armazenar a entrada do usuário nas variáveis que criei.

Eu fiz um if imenso só para checar se as notas eram válidas, ou seja, num intervalo entre 0 e 10.

```c
if (nota_um < 0 || nota_um > 10 || nota_dois < 0 || nota_dois > 10 || nota_tres < 0 || nota_tres > 10 || !nota_um || !nota_dois || !nota_tres)
```

Os `||` significam _ou_, então a minha leitura sob essa linha seria: _SE a nota um for menor que 0 ou a nota um for maior que 10 ou a nota dois for menor que 0 ou a nota dois for maior que 10 ou a nota tres for menor que 0 ou a nota 3 for maior que 10 ou a nota um não existe ou a nota dois não existe ou a nota tres não existe_, se ele se encaixar nisso, vai printar que a nota é inválida e vai retornar a função main com o número 1, que significa `erro`.

Passando por isso, eu crio uma variável do tipo `int` chamada `media` já que na proposta foi pedido para consideirar a parte inteira da nota. O valor da média é um calculo de média das três notas, ou seja, a soma das notas dividido por 3.

O jeito mais simples de continuar o código seria utilizando `if`, mas como foi pedido o uso de switch-case, eu vou ter que usá-lo.
O switch recebe um parâmetro, que é a variável que quero checkar, já os cases são absolutos, eles só podem ser um valor fixo, não poder ter por exemplo `case > 0`, deve ser absoluto, como `case 0`. Como do case 0 ao 5 eu vou fazer a mesma coisa, eu não preciso repitir a ação a cada case, eu posso fazer direto

```c
case 0:
case 1:
case 2:
...
```

A leitura ficaria _Caso media seja 0, 1, 2, 3, 4 ou 5, faça:_ então dou um print, e breako pra fora do swith. Repito isso para todos os valores, com prints para os respectivos casos, e por fim, termino meu sistema retornando 0 para a função main, dizendo que tudo ocorreu bem.
