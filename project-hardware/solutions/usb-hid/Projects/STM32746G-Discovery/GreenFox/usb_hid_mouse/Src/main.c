/**
 ******************************************************************************
 * @file    USB_Device/HID_Standalone/Src/main.c
 * @author  MCD Application Team
 * @version V1.2.0
 * @date    30-December-2016
 * @brief   USB device HID demo main file
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2016 STMicroelectronics International N.V.
 * All rights reserved.</center></h2>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted, provided that the following conditions are met:
 *
 * 1. Redistribution of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. Neither the name of STMicroelectronics nor the names of other
 *    contributors to this software may be used to endorse or promote products
 *    derived from this software without specific written permission.
 * 4. This software, including modifications and/or derivative works of this
 *    software, must execute solely and exclusively on microcontroller or
 *    microprocessor devices manufactured by or for STMicroelectronics.
 * 5. Redistribution and use of this software other than as permitted under
 *    this license is void and will automatically terminate your rights under
 *    this license.
 *
 * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
 * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT
 * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include <math.h>

/* Private typedef -----------------------------------------------------------*/
typedef struct {
	int32_t x;
	int32_t y;
} coordinate_t;

/* Private define ------------------------------------------------------------*/
#define TS_CLICK_THRESHOLD	3

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
USBD_HandleTypeDef USBD_Device;
uint8_t HID_Buffer[4];

/* Private function prototypes -----------------------------------------------*/
static void SystemClock_Config(void);
static void Error_Handler(void);
static void CPU_CACHE_Enable(void);

/* Private functions ---------------------------------------------------------*/

/**
 * @brief  Main program
 * @param  None
 * @retval None
 */
int main(void) {
	/* Enable the CPU Cache */
	CPU_CACHE_Enable();

	/* STM32F7xx HAL library initialization:
	 - Configure the Flash ART accelerator on ITCM interface
	 - Configure the Systick to generate an interrupt each 1 msec
	 - Set NVIC Group Priority to 4
	 - Low Level Initialization
	 */
	HAL_Init();

	/* Configure the System clock to have a frequency of 216 MHz */
	SystemClock_Config();

	/* Configure LED1 */
	BSP_LED_Init(LED1);

	/* Init Device Library */
	USBD_Init(&USBD_Device, &HID_Desc, 0);

	/* Add Supported Class */
	USBD_RegisterClass(&USBD_Device, USBD_HID_CLASS);

	/* Start Device Process */
	USBD_Start(&USBD_Device);

	BSP_TS_Init(BSP_LCD_GetXSize(), BSP_LCD_GetYSize());

	TS_StateTypeDef ts_state;

	coordinate_t last_ts_coord;
	last_ts_coord.x = 0;
	last_ts_coord.y = 0;

	coordinate_t first_ts_coord;
	first_ts_coord.x = 0;
	first_ts_coord.y = 0;

	uint8_t first_touch_detected_flag = 0;
	uint8_t possible_click_event = 0;

	/* Run Application (Interrupt mode) */
	while (1) {
		// Get touch screen state
		BSP_TS_GetState(&ts_state);
		// Reset USB HID buffer
		HID_Buffer[0] = 0;
		HID_Buffer[1] = 0;
		HID_Buffer[2] = 0;

		if (ts_state.touchDetected) {
			BSP_LED_On(LED1);

			if (!first_touch_detected_flag) {
				first_touch_detected_flag = 1;
				possible_click_event = 1;
				last_ts_coord.x = ts_state.touchX[0];
				last_ts_coord.y = ts_state.touchY[0];
				first_ts_coord.x = ts_state.touchX[0];
				first_ts_coord.y = ts_state.touchY[0];
			} else {
				int8_t diff_x = ts_state.touchX[0] - last_ts_coord.x;
				int8_t diff_y = ts_state.touchY[0] - last_ts_coord.y;

				HID_Buffer[1] = diff_x * 3;
				HID_Buffer[2] = diff_y * 3;

				last_ts_coord.x = ts_state.touchX[0];
				last_ts_coord.y = ts_state.touchY[0];

				// Check if the user finger left a predefined area
				// This means that this is not a clicking, just a cursor movement
				int32_t click_diff_x = ts_state.touchX[0] - first_ts_coord.x;
				int32_t click_diff_y = ts_state.touchY[0] - first_ts_coord.y;
				if (abs(click_diff_x) > TS_CLICK_THRESHOLD || abs(click_diff_y) > TS_CLICK_THRESHOLD)
					possible_click_event = 0;

				USBD_HID_SendReport(&USBD_Device, HID_Buffer, 4);
			}
		} else {
			BSP_LED_Off(LED1);
			first_touch_detected_flag = 0;
			if (possible_click_event) {
				HAL_Delay(10);
				HID_Buffer[0] = 0b001;
				USBD_HID_SendReport(&USBD_Device, HID_Buffer, 4);
				HAL_Delay(10);
				HID_Buffer[0] = 0;
				USBD_HID_SendReport(&USBD_Device, HID_Buffer, 4);
				possible_click_event = 0;
			}
		}
	}
}

/**
 * @brief This function provides accurate delay (in milliseconds) based
 *        on SysTick counter flag.
 * @note This function is declared as __weak to be overwritten in case of other
 *       implementations in user file.
 * @param Delay: specifies the delay time length, in milliseconds.
 * @retval None
 */

void HAL_Delay(__IO uint32_t Delay) {
	while (Delay) {
		if (SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) {
			Delay--;
		}
	}
}

/**
 * @brief  System Clock Configuration
 *         The system Clock is configured as follow :
 *            System Clock source            = PLL (HSE)
 *            SYSCLK(Hz)                     = 216000000
 *            HCLK(Hz)                       = 216000000
 *            AHB Prescaler                  = 1
 *            APB1 Prescaler                 = 4
 *            APB2 Prescaler                 = 2
 *            HSE Frequency(Hz)              = 25000000
 *            PLL_M                          = 25
 *            PLL_N                          = 432
 *            PLL_P                          = 2
 *            VDD(V)                         = 3.3
 *            Main regulator output voltage  = Scale1 mode
 *            Flash Latency(WS)              = 7
 * @param  None
 * @retval None
 */
void SystemClock_Config(void) {
	RCC_ClkInitTypeDef RCC_ClkInitStruct;
	RCC_OscInitTypeDef RCC_OscInitStruct;

	/* Enable HSE Oscillator and activate PLL with HSE as source */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	RCC_OscInitStruct.HSEState = RCC_HSE_ON;
	RCC_OscInitStruct.HSIState = RCC_HSI_OFF;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	RCC_OscInitStruct.PLL.PLLM = 25;
	RCC_OscInitStruct.PLL.PLLN = 432;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	RCC_OscInitStruct.PLL.PLLQ = 9;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		Error_Handler();
	}

	/* Activate the OverDrive to reach the 216 Mhz Frequency */
	if (HAL_PWREx_EnableOverDrive() != HAL_OK) {
		Error_Handler();
	}

	/* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2
	 clocks dividers */
	RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK |
	RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK) {
		Error_Handler();
	}
}

/**
 * @brief  This function is executed in case of error occurrence.
 * @param  None
 * @retval None
 */
static void Error_Handler(void) {
	/* User may add here some code to deal with this error */
	while (1) {
	}
}

/**
 * @brief  CPU L1-Cache enable.
 * @param  None
 * @retval None
 */
static void CPU_CACHE_Enable(void) {
	/* Enable I-Cache */
	SCB_EnableICache();

	/* Enable D-Cache */
	SCB_EnableDCache();
}

#ifdef  USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t* file, uint32_t line)
{
	/* User can add his own implementation to report the file name and line number,
	 ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

	/* Infinite loop */
	while (1)
	{
	}
}
#endif

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
