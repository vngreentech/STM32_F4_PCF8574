/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
typedef struct
{
	uint8_t Button_1;
	uint8_t Button_2;
	uint8_t Button_3;
	uint8_t Button_4;
	uint8_t Button_5;
	uint8_t Button_6;
	uint8_t Button_7;
	uint8_t Button_8;
}BUTTON;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define PCF8574_ADD_WRITE 0x40
#define PCF8574_ADD_READ 0x41

#define bit_set 0xff
#define bit_clear 0x00

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
#define SetAll(port) port |= bit_set;
#define ClearAll(port) port &= bit_clear;
#define SetBit(port, bit) port |= (1<<bit);
#define ClearBit(port, bit) port &= ~(1<<bit);
#define ReadBit(port, bit) port & (1<<bit);
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;

/* USER CODE BEGIN PV */
//uint8_t port, data;
uint8_t BIT_STATUS;
BUTTON Button_Ris_1;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
uint8_t Read_ALL()
{
	uint8_t port;
	HAL_I2C_Master_Receive(&hi2c1, PCF8574_ADD_READ, &port, 1, 500);
	return port;
}
uint8_t Read_BIT(uint8_t bit)
{
	uint8_t port = Read_ALL();
	if(port & (1<<bit)) return 1;
	else return 0;
}

void Set_ALL() //bật tất cả bit
{
	uint8_t port = bit_set;
	HAL_I2C_Master_Transmit(&hi2c1, PCF8574_ADD_WRITE, &port, 1, 500);
}
void Clear_ALL()
{
	uint8_t port = bit_clear;
	HAL_I2C_Master_Transmit(&hi2c1, PCF8574_ADD_WRITE, &port, 1, 500);
}
void Set_BIT(uint8_t bit)
{
	uint8_t port;
	uint8_t data = Read_ALL();
	SetBit(port, bit);
	port |= data;
	HAL_I2C_Master_Transmit(&hi2c1, PCF8574_ADD_WRITE, &port, 1, 500);
}
void Clear_BIT(uint8_t bit)
{
	uint8_t port;
	uint8_t data = Read_ALL();
	ClearBit(port, bit);
	port &= data;
	HAL_I2C_Master_Transmit(&hi2c1, PCF8574_ADD_WRITE, &port, 1, 500);
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
  MX_I2C1_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

//	  Set_BIT(0);

//	  BIT_STATUS = Read_BIT(0);
//	  BIT_STATUS = Read_ALL();

//	  Button_Ris_1.Button_1 = Read_BIT(0);
//	  Button_Ris_1.Button_2 = Read_BIT(Read_ALL(), 1);
//	  Button_Ris_1.Button_3 = Read_BIT(Read_ALL(), 2);
//	  Button_Ris_1.Button_4 = Read_BIT(Read_ALL(), 3);
//
//	  Button_Ris_1.Button_5 = Read_BIT(Read_ALL(), 4);
//	  Button_Ris_1.Button_6 = Read_BIT(Read_ALL(), 5);
//	  Button_Ris_1.Button_7 = Read_BIT(Read_ALL(), 6);
//	  Button_Ris_1.Button_8 = Read_BIT(Read_ALL(), 7);
//	  HAL_Delay(10);

//	  Clear_ALL();
//	  HAL_Delay(1000);
//
//	  data=port=0;
//	  data = Read_ALL();
//	  SetBit(port, 2);
//	  port |= data;
//	  HAL_I2C_Master_Transmit(&hi2c1, PCF8574_ADD_WRITE, &port, 1, 100);
//	  HAL_Delay(1000);
//
//	  data=port=0;
//	  data = Read_ALL();
//	  SetBit(port, 5);
//	  port |= data;
//	  HAL_I2C_Master_Transmit(&hi2c1, PCF8574_ADD_WRITE, &port, 1, 100);
//	  HAL_Delay(1000);
//
//	  Set_ALL();
//	  HAL_Delay(1000);

//	  Clear_ALL();
//	  HAL_Delay(1000);

//	  for(int i=0; i<=7; i++)
//	  {
//		  Set_BIT(i);
//		  HAL_Delay(500);
//	  }
//	  HAL_Delay(2000);
//	  for(int i=7; i>=0; i--)
//	  {
//		  Clear_BIT(i);
//		  HAL_Delay(500);
//	  }
//	  HAL_Delay(2000);

//	  Set_ALL();
//	  HAL_Delay(1000);
//	  Clear_ALL();
//	  HAL_Delay(1000);
//	  Set_ALL();
//	  HAL_Delay(1000);
//	  Clear_ALL();
//	  HAL_Delay(1000);
//	  Set_ALL();
//	  HAL_Delay(3000);

//	  Set_ALL();
//	  BIT_STATUS = Read_BIT(5);
//	  HAL_Delay(3000);
//
//	  Clear_ALL();
//	  BIT_STATUS = Read_BIT(5);
//	  HAL_Delay(3000);

	  /*Set_ALL();
	  HAL_Delay(1000);
	  Clear_ALL();
	  HAL_Delay(1000);

	  for(int i=0; i<=7; i++)
	  {
		  Set_BIT(i);
		  HAL_Delay(100);
	  }
	  HAL_Delay(1000);
	  for(int i=7; i>=0; i--)
	  {
		  Set_BIT(i);
		  HAL_Delay(100);
	  }
	  HAL_Delay(3000);*/
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

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 100000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

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
