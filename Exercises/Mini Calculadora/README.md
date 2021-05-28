# Calculando

## Proposta

O professor pedir para implementarmos uma mini calculadora que fizesse as 4 operações básicas. O programa deveria ficar em loop até que o usuário pedisse para sair. As entradas deveriam ser lidas com switch case, e elas devem ser:

- M para multiplicar
- D para dividir
- A para somar
- S para subtrair
- q para sair do programa

## Resolução

Vamos lá, primeiramente eu preciso criar as variáveis para meu programa

- choice, do tipo `char` para armazenar a escolha do usuário
- first_number, second_number e result do tipo `float` para armazenar os números da conta e o resultado.

Pra deixar o programa em loop, vou utilizar um laço Do-While, que FAZ algo ENQUANTO algo.

Primeira linha dentro do meu **do** já possui uma função diferente, a função `fflush(stdin)`, ela é uma função que o professor nos mostrou depois para resolver um problema da entrada ficar 'suja', então o fflush limpa a memória do `stdin` que é a entrada do usuário, desse jeito não vai ocorrer problemas com a entrada. Eu faço um `scanf` pedindo uma entrada do tipo `char`, e armazeno na variável `choice`.

Eu então checo se a variável choice é `q`, pois se for, devo sair do programa, então eu retorno a função. Como a minha main é do tipo `void`, eu não retorno nada. Faço dois `scanf` para receber os dois números da operação.

Vamos para a cabeça do sistema agora, o switch. Eu passo a `choice` para meu switch, pra que, dependendo da minha escolha, faça a operação da escolha.
Em cada escolha ele armazena o resultado da operação na variável result. Que sempre é `fist_number <operação> second_number`. Após a conta, ele da um printf mostrando a conta, mas com uma notação diferente. `%.2f` significa que eu quero apenas os 2 numeros após o ponto para mostrar do float, assim a tela n fica spammada com zeros ou números que não importam. Nesse switch eu também coloquei um `default` para dizer que caso a `choice` não seja uma operação válida, printe isso. Fechando meu do, eu abro o while falando para repitir tudo enquanto `choice` não for `q`, pois 'q' fecha o programa.
