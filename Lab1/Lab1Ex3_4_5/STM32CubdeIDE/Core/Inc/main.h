/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define VERTICAL_RED_Pin GPIO_PIN_1
#define VERTICAL_RED_GPIO_Port GPIOA
#define VERTICAL_YELLOW_Pin GPIO_PIN_2
#define VERTICAL_YELLOW_GPIO_Port GPIOA
#define VERTICAL_GREEN_Pin GPIO_PIN_3
#define VERTICAL_GREEN_GPIO_Port GPIOA
#define HORIZONTAL_RED_Pin GPIO_PIN_4
#define HORIZONTAL_RED_GPIO_Port GPIOA
#define HORIZONTAL_YELLOW_Pin GPIO_PIN_5
#define HORIZONTAL_YELLOW_GPIO_Port GPIOA
#define HORIZONTAL_GREEN_Pin GPIO_PIN_6
#define HORIZONTAL_GREEN_GPIO_Port GPIOA
#define TIMER_A_Pin GPIO_PIN_0
#define TIMER_A_GPIO_Port GPIOB
#define TIMER_B_Pin GPIO_PIN_1
#define TIMER_B_GPIO_Port GPIOB
#define TIMER_C_Pin GPIO_PIN_2
#define TIMER_C_GPIO_Port GPIOB
#define TIMER_D_Pin GPIO_PIN_3
#define TIMER_D_GPIO_Port GPIOB
#define TIMER_E_Pin GPIO_PIN_4
#define TIMER_E_GPIO_Port GPIOB
#define TIMER_F_Pin GPIO_PIN_5
#define TIMER_F_GPIO_Port GPIOB
#define TIMER_G_Pin GPIO_PIN_6
#define TIMER_G_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
