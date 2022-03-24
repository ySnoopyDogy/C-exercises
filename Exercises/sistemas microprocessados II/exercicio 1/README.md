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

Cálculo de Tempo: `tempo = (PSC + 1)(CP + 1) / Fosc`

Default Fosc: `84MHz`.

Frequência Inicial: `1Hz`. 

Período Total: `1s` (`0,5s para ON, 0,5s para OFF`)

Resolução: `0,5 = (PSC + 1)(CP + 1) / 84e+6`
