# Interrupção Externa e de Timer (PWM) (Apenas o exemplo)

## Proposta 

Faça um programa em C usando interrupções para o microcontrolador ARM Cortex M4, de modo que ao pressionar-se o botão B1 da placa, o led, também da placa,
pisque alternadamente com período de 0,5s e 100ms. O próximo pressionamento coloca o processo em repouso. A seguir, nos próximos pressionamentos tem-se a repetição
do processo acima

## Como Resolver

> O que é um PWN?

**Pulse With Modulation** - No PMW o período _( 1 / T )_ é constante, o que muda é o ciclo de ativação.

> Cálculo de Ciclo de Trabalho

![](https://latex.codecogs.com/png.image?\dpi{110}\bg{white}\delta_{%}=&space;\frac{T_{on}}{T}&space;100%)

### Cálculos

`T = 1 / 2Hz = 0,5s`

`T = 1 / 10Hz = 100ms`

Pegando como base `PSC = 41999 para 500ms e PSC = 8400 para 100ms` e `CP = 999`



> (VER COMO CONFIGURAR INTERRUPT E TUDO NO .IOC NO EXRCICIO 1)

### Código

Interrupt do Botão (Debounce é uma bool declarada em PRIVATE VARIABLES)

```c
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	if(GPIO_Pin == B1_Pin) {
		// Checa se está em debounce
		if(DEBOUNCE) return;
		// Inicia o timer
		HAL_TIM_Base_Start_IT(&htim9);
		// Troca o estado do Led
		HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
		// Nego o valor de debounce
		DEBOUNCE = !DEBOUNCE;
	}
}
```

Inerrupt do Timer 

```c
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {

	// Verifica se o tim que estourou é o 9
	if(htim -> Instance != TIM9) return;

	// Guarda o estado atual do led
	int isLedOn = HAL_GPIO_ReadPin(LD2_GPIO_Port, LD2_Pin);

	// Troca o estado do Led
    HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);

    // Se o LED estiver desligado, não queremos mudar mais nada
	if(!isLedOn) return;

	// É importante parar o timer para mexer em seu psc
	HAL_TIM_Base_Stop_IT(&htim9);

	// Verifica quanto vale o PSC atualmente
	if(TIM9 -> PSC == 8399)
		TIM9 -> PSC = 41999;
	else
		TIM9 -> PSC = 8399;

	// Restarta o tim com o novo prescale
   HAL_TIM_Base_Start_IT(&htim9);
}
```

Código do while para tratar repique

```c
  while (1)
  {
	  if(DEBOUNCE) {
	      // Da um delay de 60ms (que é o padrão para o repique parar)
	      HAL_Delay(60);
	      // Verifica se o boca de gamela não está segurando o botão
	      while(HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin) == 0) {}
	      HAL_Delay(60);
	      // Nega o valor de debounce
	      DEBOUNCE = !DEBOUNCE;
	  }

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  /* USER CODE END 3 */
}
```
