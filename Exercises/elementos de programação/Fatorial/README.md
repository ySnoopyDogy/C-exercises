# Fatorial

## Proposta

Neste exercício deveríamos calcular o fatorial de um número. Nós estavamos aprendendo sobre loops, e não havíamos aprendido `scanf` ainda, então o número era hardcodado na função. Para não ser tão simples de se fazer, eu tentei fazer utilizando funções para aprender melhor.

## Resolução

Meu código se baseia em duas funções, a `main` (obviamente) e a `calculaFatorial` que recebe como parâmetro um número inteiro, ou seja, do tipo `int`.

Logo no início da main eu declaro uma varíavel inteira chamada `ValorToFatorial`, que como disse acima, é hardcoded. O número que usei é 3, mas pode ser qualquer um.

> Qualquer um eu digo qualquer um que se encaixe nos limites de bytes do inteiro após ser calculado o fatorial.

Abaixo eu chamo a função `calculaFatorial` passando o `ValorToFatorial` como parâmetro. Como a função retorna um inteiro, eu armazenei ela num outro inteiro chamado `FatorialCalculado`.

**Função calculaFatorial:** Dentro da função eu defino um inteiro chamado fatorial, que eu defino como 1.

> Pra quem não se lembra, o fatorial é a multiplicação de todos os números até um, contando ele.

Então eu crio um laço `for` que eu gosto de ler assim: _i é igual ao numero, enquanto i for maior que zero, roda tudo que está aqui dentro, e ao fim, retire um do valor de i_. Com isso, eu só preciso fazer o cálculo do fatorial, que será o valor do fatorial, vezes o `i`
Então, retorno a função com o valor de fatorial.

> Ali no meu cálculo eu usei a notação *=, que seria o mesmo que `fatorial = fatorial * i`.

De volta a função main, eu executo um printf mostrando o valor de dois inteiros, que eu informo eles nos parâmetros do printf. E por fim, retorno a função main com valor 0 para dizer que tudo ocorreu bem, e que o sistema pode terminar a execução.
