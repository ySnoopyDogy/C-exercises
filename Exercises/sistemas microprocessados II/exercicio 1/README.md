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

2. Em Prática (Adotando CP + 1 = 1000)

  `PSC + 1 = (0,5 x 84e+6) / 1000`
  
  `PSC = 41999`

3. No final

 `t=0,5s {
   PSC = 41999
   CP = 999
 }`

 `t = 0,1s {
   PSC = 8399
   CP = 999
 }`

 ### Iniciando TIM2 no IOC

 ![ioc](https://i.imgur.com/j337r9T.png)

 ### Ativando Interrupções

 > Devemos configurar a interrupção do B1 (Blue Button) e a interrupção do TIM2 em System Core > NVIC
 > ATENÇAO!!! O TIM2 DEVE TER PRIORIDADE MÁXIMA!! OU SEJA, O BOTAÕ 1 DEVE TER UMA PRIORIDADE `1` ENQUANTO TIM2 `0`

 ![interrupt](https://i.imgur.com/Gf27jSS.png)

 ### Código

 Começamos settando as interrupções, dento do USER_CODE_BEGIN_4, criamos nossa função de interrupção

 ```c
 // NÃO É EXIT, É EXTI = EXTernal Interrup
 void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
   // Verifica DEBOUNCE para não termos problema do botão REPICAR
	if(DEBOUNCE == 0) {

    /* É importante checar o pino de onde veio a interrupção para que, 
     caso haja mais de uma interrupção declarada, sabermos qual interrupção foi triggada 
    */

		if(GPIO_Pin == B1_Pin) {
      // hasPressed é uma variável global para checar se é a primeira vez que o botão foi pressionado, para mudar a frequencia do tim

      if(hasPressed == 0) {
        HAL_TIM_Base_Stop_IT(&htim2);
        TIM1 -> PSC = 41999;

        // Liga o Timer
        HAL_TIM_Base_Start_IT(&htim2);
        hasPressed = 1;
      } else { 
        // Sempre é bom parar o timer para mudar o valor dele

        HAL_TIM_Base_Stop_IT(&htim2);
        TIM1 -> PSC = 8399;

        // Restarta o timer
        HAL_TIM_Base_Start_IT(&htim2);
        
        hasPressed = 0;
      }

      HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
    }
		
		DEBOUNCE = 1;
  }
}
```

> DEBOUNCE e b1_flag são variáveis settadas no PV_VARIABLES

Agora, devemos configurar a interrupção do TIM2, que vai triggar quando o timer estourar

```c
// htim é um **ponteiro**!!
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {

  /* É importante testar qual foi o timer que triggou este interrupt para o caso
   de termos mais de um timer configurado
   Aqui verificamos se a Instância do htim é o TIM2, que configuramos no .ioc
   */
  if(htim -> Instance == TIM2) {
    // Trocar o valor do pino do led, para alternar entre ON e OFF no estouro do TIM2 
       HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
  }
}
```

Feito isso, podemos finalizar nosso código adicionando um delay no DEBOUNCE dentro do nosso while

```c
   /* USER CODE BEGIN WHILE */
  while (1)
  {
	  if(DEBOUCE == 1) {
      // Da um delay de 60ms (que é o padrão para o repique parar)
      HAL_Delay(60);
      // Verifica se o boca de gamela não está segurando o botão
      while(HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin) == 0) {}
      HAL_Delay(60);
      DEBOUNCE = 0;
	  }

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
```

