/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2025 STMicroelectronics.
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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "software_timer.h"
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
void display7SEG(int number){

	switch (number) {
	case 0:
		HAL_GPIO_WritePin(GATE_A_GPIO_Port, GATE_A_Pin, RESET);
		HAL_GPIO_WritePin(GATE_B_GPIO_Port, GATE_B_Pin, RESET);
		HAL_GPIO_WritePin(GATE_C_GPIO_Port, GATE_C_Pin, RESET);
		HAL_GPIO_WritePin(GATE_D_GPIO_Port, GATE_D_Pin, RESET);
		HAL_GPIO_WritePin(GATE_E_GPIO_Port, GATE_E_Pin, RESET);
		HAL_GPIO_WritePin(GATE_F_GPIO_Port, GATE_F_Pin, RESET);
		HAL_GPIO_WritePin(GATE_G_GPIO_Port, GATE_G_Pin, SET);
		break;
	case 1:
		HAL_GPIO_WritePin(GATE_A_GPIO_Port, GATE_A_Pin, SET);
		HAL_GPIO_WritePin(GATE_B_GPIO_Port, GATE_B_Pin, RESET);
		HAL_GPIO_WritePin(GATE_C_GPIO_Port, GATE_C_Pin, RESET);
		HAL_GPIO_WritePin(GATE_D_GPIO_Port, GATE_D_Pin, SET);
		HAL_GPIO_WritePin(GATE_E_GPIO_Port, GATE_E_Pin, SET);
		HAL_GPIO_WritePin(GATE_F_GPIO_Port, GATE_F_Pin, SET);
		HAL_GPIO_WritePin(GATE_G_GPIO_Port, GATE_G_Pin, SET);
		break;
	case 2:
		HAL_GPIO_WritePin(GATE_A_GPIO_Port, GATE_A_Pin, RESET);
		HAL_GPIO_WritePin(GATE_B_GPIO_Port, GATE_B_Pin, RESET);
		HAL_GPIO_WritePin(GATE_C_GPIO_Port, GATE_C_Pin, SET);
		HAL_GPIO_WritePin(GATE_D_GPIO_Port, GATE_D_Pin, RESET);
		HAL_GPIO_WritePin(GATE_E_GPIO_Port, GATE_E_Pin, RESET);
		HAL_GPIO_WritePin(GATE_F_GPIO_Port, GATE_F_Pin, SET);
		HAL_GPIO_WritePin(GATE_G_GPIO_Port, GATE_G_Pin, RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(GATE_A_GPIO_Port, GATE_A_Pin, RESET);
		HAL_GPIO_WritePin(GATE_B_GPIO_Port, GATE_B_Pin, RESET);
		HAL_GPIO_WritePin(GATE_C_GPIO_Port, GATE_C_Pin, RESET);
		HAL_GPIO_WritePin(GATE_D_GPIO_Port, GATE_D_Pin, RESET);
		HAL_GPIO_WritePin(GATE_E_GPIO_Port, GATE_E_Pin, SET);
		HAL_GPIO_WritePin(GATE_F_GPIO_Port, GATE_F_Pin, SET);
		HAL_GPIO_WritePin(GATE_G_GPIO_Port, GATE_G_Pin, RESET);
		break;
	case 4:
		HAL_GPIO_WritePin(GATE_A_GPIO_Port, GATE_A_Pin, SET);
		HAL_GPIO_WritePin(GATE_B_GPIO_Port, GATE_B_Pin, RESET);
		HAL_GPIO_WritePin(GATE_C_GPIO_Port, GATE_C_Pin, RESET);
		HAL_GPIO_WritePin(GATE_D_GPIO_Port, GATE_D_Pin, SET);
		HAL_GPIO_WritePin(GATE_E_GPIO_Port, GATE_E_Pin, SET);
		HAL_GPIO_WritePin(GATE_F_GPIO_Port, GATE_F_Pin, RESET);
		HAL_GPIO_WritePin(GATE_G_GPIO_Port, GATE_G_Pin, RESET);
		break;
	case 5:
		HAL_GPIO_WritePin(GATE_A_GPIO_Port, GATE_A_Pin, RESET);
		HAL_GPIO_WritePin(GATE_B_GPIO_Port, GATE_B_Pin, SET);
		HAL_GPIO_WritePin(GATE_C_GPIO_Port, GATE_C_Pin, RESET);
		HAL_GPIO_WritePin(GATE_D_GPIO_Port, GATE_D_Pin, RESET);
		HAL_GPIO_WritePin(GATE_E_GPIO_Port, GATE_E_Pin, SET);
		HAL_GPIO_WritePin(GATE_F_GPIO_Port, GATE_F_Pin, RESET);
		HAL_GPIO_WritePin(GATE_G_GPIO_Port, GATE_G_Pin, RESET);
		break;
	case 6:
		HAL_GPIO_WritePin(GATE_A_GPIO_Port, GATE_A_Pin, RESET);
		HAL_GPIO_WritePin(GATE_B_GPIO_Port, GATE_B_Pin, SET);
		HAL_GPIO_WritePin(GATE_C_GPIO_Port, GATE_C_Pin, RESET);
		HAL_GPIO_WritePin(GATE_D_GPIO_Port, GATE_D_Pin, RESET);
		HAL_GPIO_WritePin(GATE_E_GPIO_Port, GATE_E_Pin, RESET);
		HAL_GPIO_WritePin(GATE_F_GPIO_Port, GATE_F_Pin, RESET);
		HAL_GPIO_WritePin(GATE_G_GPIO_Port, GATE_G_Pin, RESET);
		break;
	case 7:
		HAL_GPIO_WritePin(GATE_A_GPIO_Port, GATE_A_Pin, RESET);
		HAL_GPIO_WritePin(GATE_B_GPIO_Port, GATE_B_Pin, RESET);
		HAL_GPIO_WritePin(GATE_C_GPIO_Port, GATE_C_Pin, RESET);
		HAL_GPIO_WritePin(GATE_D_GPIO_Port, GATE_D_Pin, SET);
		HAL_GPIO_WritePin(GATE_E_GPIO_Port, GATE_E_Pin, SET);
		HAL_GPIO_WritePin(GATE_F_GPIO_Port, GATE_F_Pin, SET);
		HAL_GPIO_WritePin(GATE_G_GPIO_Port, GATE_G_Pin, SET);
		break;
	case 8:
		HAL_GPIO_WritePin(GATE_A_GPIO_Port, GATE_A_Pin, RESET);
		HAL_GPIO_WritePin(GATE_B_GPIO_Port, GATE_B_Pin, RESET);
		HAL_GPIO_WritePin(GATE_C_GPIO_Port, GATE_C_Pin, RESET);
		HAL_GPIO_WritePin(GATE_D_GPIO_Port, GATE_D_Pin, RESET);
		HAL_GPIO_WritePin(GATE_E_GPIO_Port, GATE_E_Pin, RESET);
		HAL_GPIO_WritePin(GATE_F_GPIO_Port, GATE_F_Pin, RESET);
		HAL_GPIO_WritePin(GATE_G_GPIO_Port, GATE_G_Pin, RESET);
		break;
	case 9:
		HAL_GPIO_WritePin(GATE_A_GPIO_Port, GATE_A_Pin, RESET);
		HAL_GPIO_WritePin(GATE_B_GPIO_Port, GATE_B_Pin, RESET);
		HAL_GPIO_WritePin(GATE_C_GPIO_Port, GATE_C_Pin, RESET);
		HAL_GPIO_WritePin(GATE_D_GPIO_Port, GATE_D_Pin, RESET);
		HAL_GPIO_WritePin(GATE_E_GPIO_Port, GATE_E_Pin, SET);
		HAL_GPIO_WritePin(GATE_F_GPIO_Port, GATE_F_Pin, RESET);
		HAL_GPIO_WritePin(GATE_G_GPIO_Port, GATE_G_Pin, RESET);
		break;
	default:
		break;
	}
	return;
}
const int MAX_LED = 4;
int index_led = 0;
int led_buffer[4] = {1, 2, 3, 4};
void update7SEG(int index){
		switch (index) {
		case 0:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
			display7SEG(led_buffer[index_led]);
			break;
		case 1:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
			display7SEG(led_buffer[index_led]);
			break;
		case 2:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
			display7SEG(led_buffer[index_led]);
			break;
		case 3:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
			display7SEG(led_buffer[index_led]);
			break;
		default:
			break;
		}
	}

void updateClockBuffer(int hour, int minute){
	//set hour
	if (hour < 10) {
		led_buffer[0] = 0;
		led_buffer[1] = hour;
	}
	else {
		led_buffer[0] = hour / 10;
		led_buffer[1] = hour % 10;
	}

	// set minute
	if (minute < 10) {
		led_buffer[2] = 0;
		led_buffer[3] = minute;
	}
	else {
		led_buffer[2] = minute / 10;
		led_buffer[3] = minute % 10;
	}
	return;
}

// PORT/PIN for Columns
GPIO_TypeDef* COL_PORT[8] = {ENM0_GPIO_Port,ENM1_GPIO_Port,ENM2_GPIO_Port,ENM3_GPIO_Port
							,ENM4_GPIO_Port,ENM5_GPIO_Port,ENM6_GPIO_Port,ENM7_GPIO_Port};
uint16_t      COL_PIN[8]  = {ENM0_Pin,ENM1_Pin,ENM2_Pin,ENM3_Pin
							,ENM4_Pin,ENM5_Pin,ENM6_Pin,ENM7_Pin};

// PORT/PIN for Rows
GPIO_TypeDef* ROW_PORT[8] = {ROW0_GPIO_Port,ROW1_GPIO_Port,ROW2_GPIO_Port,ROW3_GPIO_Port
							,ROW4_GPIO_Port,ROW5_GPIO_Port,ROW6_GPIO_Port,ROW7_GPIO_Port};
uint16_t      ROW_PIN[8]  = {ROW0_Pin,ROW1_Pin,ROW2_Pin,ROW3_Pin
							,ROW4_Pin,ROW5_Pin,ROW6_Pin,ROW7_Pin};

const int MAX_LED_MATRIX = 8;
int index_led_matrix = 0;
uint8_t matrix_buffer[8] = {0x18, 0x3C, 0x66, 0x66, 0x7E, 0x7E, 0x66, 0x66};

void updateLEDMatrix(int index){
	 switch (index){
	 	 case 0:
	 		HAL_GPIO_WritePin(COL_PORT[0], COL_PIN[0], SET);
	 		 for (int i = 0; i < MAX_LED_MATRIX; i++){
	 			 if (matrix_buffer[index] & (1<<i)) {
			 		 HAL_GPIO_WritePin(ROW_PORT[i], ROW_PIN[i], SET);
	 			 }
	 			 else {
			 		 HAL_GPIO_WritePin(ROW_PORT[i], ROW_PIN[i], RESET);
	 			 }
	 		 }
	 		 index++;
		 break;
		 case 1:
	 		 for (int i = 0; i < MAX_LED_MATRIX; i++){
	 			 if (matrix_buffer[index] & 1<<i) {
			 		 HAL_GPIO_WritePin(ROW_PORT[i], ROW_PIN[i], SET);
	 			 }
	 			 else {
			 		 HAL_GPIO_WritePin(ROW_PORT[i], ROW_PIN[i], RESET);
	 			 }
	 		 }
	 		 index++;
		 break;
		 case 2:
	 		 for (int i = 0; i < MAX_LED_MATRIX; i++){
	 			 if (matrix_buffer[index] & 1<<i) {
			 		 HAL_GPIO_WritePin(ROW_PORT[i], ROW_PIN[i], SET);
	 			 }
	 			 else {
			 		 HAL_GPIO_WritePin(ROW_PORT[i], ROW_PIN[i], RESET);
	 			 }
	 		 }
	 		 index++;
		 break;
		 case 3:
	 		 for (int i = 0; i < MAX_LED_MATRIX; i++){
	 			 if (matrix_buffer[index] & 1<<i) {
			 		 HAL_GPIO_WritePin(ROW_PORT[i], ROW_PIN[i], SET);
	 			 }
	 			 else {
			 		 HAL_GPIO_WritePin(ROW_PORT[i], ROW_PIN[i], RESET);
	 			 }
	 		 }
	 		 index++;
		 break;
		 case 4:
	 		 for (int i = 0; i < MAX_LED_MATRIX; i++){
	 			 if (matrix_buffer[index] & 1<<i) {
			 		 HAL_GPIO_WritePin(ROW_PORT[i], ROW_PIN[i], SET);
	 			 }
	 			 else {
			 		 HAL_GPIO_WritePin(ROW_PORT[i], ROW_PIN[i], RESET);
	 			 }
	 		 }
	 		 index++;
		 break;
		 case 5:
	 		 for (int i = 0; i < MAX_LED_MATRIX; i++){
	 			 if (matrix_buffer[index] & 1<<i) {
			 		 HAL_GPIO_WritePin(ROW_PORT[i], ROW_PIN[i], SET);
	 			 }
	 			 else {
			 		 HAL_GPIO_WritePin(ROW_PORT[i], ROW_PIN[i], RESET);
	 			 }
	 		 }
	 		 index++;
		 break;
		 case 6:
	 		 for (int i = 0; i < MAX_LED_MATRIX; i++){
	 			 if (matrix_buffer[index] & 1<<i) {
			 		 HAL_GPIO_WritePin(ROW_PORT[i], ROW_PIN[i], SET);
	 			 }
	 			 else {
			 		 HAL_GPIO_WritePin(ROW_PORT[i], ROW_PIN[i], RESET);
	 			 }
	 		 }
	 		 index++;
		 break;
		 case 7:
	 		 for (int i = 0; i < MAX_LED_MATRIX; i++){
	 			 if (matrix_buffer[index] & 1<<i) {
			 		 HAL_GPIO_WritePin(ROW_PORT[i], ROW_PIN[i], SET);
	 			 }
	 			 else {
			 		 HAL_GPIO_WritePin(ROW_PORT[i], ROW_PIN[i], RESET);
	 			 }
	 		 }
	 		 index = 0;
		 break;
		 default:
		 break;
	}
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
  // hello world
  	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
  	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
  	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
  	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
  	int hour = 15, minute = 8, second = 50;
  	setTimer1(100);
  	setTimer2(2);
  	setTimer3(4);
  	setTimer4(10);
  	int index = 0;
//  	HAL_GPIO_WritePin(COL_PORT[0], COL_PIN[0], SET);
//  	HAL_GPIO_WritePin(COL_PORT[1], COL_PIN[1], SET);
//  	HAL_GPIO_WritePin(COL_PORT[2], COL_PIN[2], SET);
//  	HAL_GPIO_WritePin(COL_PORT[3], COL_PIN[3], SET);
//  	HAL_GPIO_WritePin(COL_PORT[4], COL_PIN[4], SET);
//  	HAL_GPIO_WritePin(COL_PORT[5], COL_PIN[5], SET);
//  	HAL_GPIO_WritePin(COL_PORT[6], COL_PIN[6], SET);
//  	HAL_GPIO_WritePin(COL_PORT[7], COL_PIN[7], SET);
  	while (1)
    {
  	  // LED_BLINK and DOT
  	  if (timer1_flag == 1) {
  		  setTimer1(100);
  		  HAL_GPIO_TogglePin(LED_BLINK_GPIO_Port, LED_BLINK_Pin);
  		  HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
  	  }
  	  // update hour and minute
  	  if (timer2_flag == 1) {
  		  setTimer2(100);
  		  second++;
  		  if (second >= 60) {
  		  	  second = 0;
  		      minute++;
  		  }
  		  if (minute >= 60) {
  		  	  minute = 0;
  		  	  hour++;
  		  }
  		  if (hour >=24){
  		  	  hour = 0;
  		  }
  		  updateClockBuffer(hour, minute);
  	  }
  	  // display hour and minute
  	  if (timer3_flag == 1) {
  		  setTimer3(4);
  		  switch (index_led){
  		  case 0:
  		  		update7SEG(index_led);
  		  		index_led++;
  		  		break;
  		  case 1:
  		  		update7SEG(index_led);
  		  		index_led++;
  		  		break;
  		  case 2:
  		  		update7SEG(index_led);
  		  		index_led++;
  		  		break;
  		  case 3:
  		  		update7SEG(index_led);
  		  		index_led = 0;
  		  		break;
  		  default:
  		  		break;
  		  }
  	  }
  	  // display matrix 8x8 led
  	  if (timer4_flag == 1){
  		  setTimer4(10);
  		  updateLEDMatrix(index++);
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
  HAL_GPIO_WritePin(GPIOA, ENM0_Pin|ENM1_Pin|DOT_Pin|LED_BLINK_Pin
                          |EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin
                          |ENM2_Pin|ENM3_Pin|ENM4_Pin|ENM5_Pin
                          |ENM6_Pin|ENM7_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GATE_A_Pin|GATE_B_Pin|GATE_C_Pin|ROW2_Pin
                          |ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin
                          |ROW7_Pin|GATE_D_Pin|GATE_E_Pin|GATE_F_Pin
                          |GATE_G_Pin|ROW0_Pin|ROW1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : ENM0_Pin ENM1_Pin DOT_Pin LED_BLINK_Pin
                           EN0_Pin EN1_Pin EN2_Pin EN3_Pin
                           ENM2_Pin ENM3_Pin ENM4_Pin ENM5_Pin
                           ENM6_Pin ENM7_Pin */
  GPIO_InitStruct.Pin = ENM0_Pin|ENM1_Pin|DOT_Pin|LED_BLINK_Pin
                          |EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin
                          |ENM2_Pin|ENM3_Pin|ENM4_Pin|ENM5_Pin
                          |ENM6_Pin|ENM7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : GATE_A_Pin GATE_B_Pin GATE_C_Pin ROW2_Pin
                           ROW3_Pin ROW4_Pin ROW5_Pin ROW6_Pin
                           ROW7_Pin GATE_D_Pin GATE_E_Pin GATE_F_Pin
                           GATE_G_Pin ROW0_Pin ROW1_Pin */
  GPIO_InitStruct.Pin = GATE_A_Pin|GATE_B_Pin|GATE_C_Pin|ROW2_Pin
                          |ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin
                          |ROW7_Pin|GATE_D_Pin|GATE_E_Pin|GATE_F_Pin
                          |GATE_G_Pin|ROW0_Pin|ROW1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	timerRun();
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
