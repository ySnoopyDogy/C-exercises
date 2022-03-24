# Interrupção Externa e de Timer

## Proposta
Considerando o núcleo ARM STM32F411RE (446), o led verde da placa e o botão
azul tipo push button, também da placa, edite um programa em linguagem C empregando
instruções HAL, de modo que, quando o botão for pressionado pela primeira vez, faça o led
piscar com frequencia de **1 Hz**. No pressionamento seguinte, a frequência é alterada para
**5 Hz**, e assim por diante, repetindo o processo. Para desligar o pisca-pisca basta
pressionar-se o botão de resset.

## Como Resolver

> Primeiro vemos o que temos

Cálculo de Tempo: 

[comment]: # (Site usado para as equações: https://latex.codecogs.com/)

![equação](https://latex.codecogs.com/png.image?\inline&space;\large&space;\dpi{100}\bg{white}Tempo&space;=&space;(PSC&space;&plus;&space;1)(CP&space;&plus;&space;1)&space;/&space;Fosc&space;)

Default Fosc: `84MHz`.

Frequência Inicial: `1Hz`. 

Período Total: `1s` (`0,5s para ON, 0,5s para OFF`)

1. Resolução: `0,5 = (PSC + 1)(CP + 1) / 84e+6`

2. Em Prática (Adotando CP + 1 = 100)

  `PSC + 1 = (0,5 x 84e+6) / 100`
  
  `PSC = 419999`
