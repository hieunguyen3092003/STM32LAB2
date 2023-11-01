/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#define MAX_LED_MATRIX  8
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "SoftwareTimer.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
int rowScanning_flag = 0;
int charShifting_flag = 0;
int CHAR_A_TABLE[MAX_LED_MATRIX][MAX_LED_MATRIX] = {
		{1, 1, 1, 0, 0, 1, 1, 1},
		{1, 1, 0, 1, 1, 0, 1, 1},
		{1, 1, 0, 1, 1, 0, 1, 1},
		{1, 0, 0, 1, 1, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 1, 1, 1, 0, 1},
		{1, 0, 1, 1, 1, 1, 0, 1},
		{1, 0, 1, 1, 1, 1, 0, 1}
};
int index_led_matrix = 0;
int cursor_matrix = 0;
uint8_t matrix_buffer[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
void updateLEDMatrix(int index){
    switch (index){
        case 0:
        	HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, RESET);
        	HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, SET);
        	HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, SET);
        	HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, SET);
        	HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, SET);
        	HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, SET);
        	HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, SET);
        	HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, SET);
            break;
        case 1:
        	HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, SET);
        	HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, RESET);
        	HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, SET);
        	HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, SET);
        	HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, SET);
        	HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, SET);
        	HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, SET);
        	HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, SET);
            break;
        case 2:
        	HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, SET);
        	HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, SET);
        	HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, RESET);
        	HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, SET);
        	HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, SET);
        	HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, SET);
        	HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, SET);
        	HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, SET);
            break;
        case 3:
        	HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, SET);
        	HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, SET);
        	HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, SET);
        	HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, RESET);
        	HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, SET);
        	HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, SET);
        	HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, SET);
        	HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, SET);
            break;
        case 4:
        	HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, SET);
        	HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, SET);
        	HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, SET);
        	HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, SET);
        	HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, RESET);
        	HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, SET);
        	HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, SET);
        	HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, SET);
            break;
        case 5:
        	HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, SET);
        	HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, SET);
        	HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, SET);
        	HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, SET);
        	HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, SET);
        	HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, RESET);
        	HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, SET);
        	HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, SET);
            break;
        case 6:
        	HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, SET);
        	HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, SET);
        	HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, SET);
        	HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, SET);
        	HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, SET);
        	HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, SET);
        	HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, RESET);
        	HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, SET);
            break;
        case 7:
        	HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, SET);
        	HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, SET);
        	HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, SET);
        	HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, SET);
        	HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, SET);
        	HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, SET);
        	HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, SET);
        	HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, RESET);
            break;
        default:
            break;
    }
}
void ledMatrixDispRow(int elementColEnable[], int cursor) {
	if(cursor + 0 <= 7) {
		HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, elementColEnable[0 + cursor]);
	}
	else HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, 1);
	if(cursor + 1 <= 7) {
		HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, elementColEnable[1 + cursor]);
	}
	else HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, 1);
	if(cursor + 2 <= 7) {
		HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, elementColEnable[2 + cursor]);
	}
	else HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, 1);
	if(cursor + 3 <= 7) {
		HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, elementColEnable[3 + cursor]);
	}
	else HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, 1);
	if(cursor + 4 <= 7) {
		HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, elementColEnable[4 + cursor]);
	}
	else HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, 1);
	if(cursor + 5 <= 7) {
		HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, elementColEnable[5 + cursor]);
	}
	else HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, 1);
	if(cursor + 6 <= 7) {
		HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, elementColEnable[6 + cursor]);
	}
	else HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, 1);
	if(cursor + 7 <= 7) {
		HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, elementColEnable[7 + cursor]);
	}
	else HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, 1);
}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(&htim2);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  setTimer1(100);
  while (1)
  {
	  if(timer1Flag == 1){
		  setTimer1(100);
		  //TODO
		  HAL_GPIO_TogglePin(redLed_GPIO_Port, redLed_Pin);
	  }
	  if(rowScanning_flag) {
		  rowScanning_flag = 0;
		  updateLEDMatrix(index_led_matrix);
		  ledMatrixDispRow(CHAR_A_TABLE[index_led_matrix], cursor_matrix);
		  index_led_matrix = (index_led_matrix + 1) % MAX_LED_MATRIX;
	  }
	  if(charShifting_flag) {
		  charShifting_flag = 0;
		  cursor_matrix = (cursor_matrix + 1) % MAX_LED_MATRIX;

	  }

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 7999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, DOT_Pin|redLed_Pin|EN0_Pin|EN1_Pin
                          |EN2_Pin|EN3_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, aLed_Pin|bLed_Pin|cLed_Pin|dLed_Pin
                          |eLed_Pin|fLed_Pin|gLed_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : DOT_Pin redLed_Pin EN0_Pin EN1_Pin
                           EN2_Pin EN3_Pin */
  GPIO_InitStruct.Pin = DOT_Pin|redLed_Pin|EN0_Pin|EN1_Pin
                          |EN2_Pin|EN3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : aLed_Pin bLed_Pin cLed_Pin dLed_Pin
                           eLed_Pin fLed_Pin gLed_Pin */
  GPIO_InitStruct.Pin = aLed_Pin|bLed_Pin|cLed_Pin|dLed_Pin
                          |eLed_Pin|fLed_Pin|gLed_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

//	void HAL_TIM_PeriodElapsedCallback	(TIM_HandleTypeDef *htim){
//		timerRun();
//	}
#define COL_SCANNING_LIMIT 	2					// 10ms
#define CHAR_SHIFTING_LIMIT 500					// 0.5s
	int rowScanning_counter = COL_SCANNING_LIMIT;
	int charShifting_counter = CHAR_SHIFTING_LIMIT;
	void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
		rowScanning_counter--;
		charShifting_counter--;
		if(rowScanning_counter == 0) {
			rowScanning_flag = 1;
			rowScanning_counter = COL_SCANNING_LIMIT;
		}
		if(charShifting_counter == 0) {
			charShifting_flag = 1;
			charShifting_counter = CHAR_SHIFTING_LIMIT;
		}
	}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
