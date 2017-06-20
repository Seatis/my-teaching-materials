 /**
  ******************************************************************************
  * @file    Templates/Src/main.c 
  * @author  MCD Application Team
  * @version V1.0.3
  * @date    22-April-2016 
  * @brief   STM32F7xx HAL API Template project 
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2016 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32746g_discovery_lcd.h"

/** @addtogroup STM32F7xx_HAL_Examples
  * @{
  */

/** @addtogroup Templates
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
typedef struct {
	uint32_t ovf;
	uint32_t prev;
	uint32_t last;
} input_capture_data_t;

/* Private define ------------------------------------------------------------*/
//#define USE_P_CTRLER


/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef pwm_handle;
TIM_OC_InitTypeDef pwm_oc_init;
ADC_HandleTypeDef adc_handle;
ADC_ChannelConfTypeDef adc_ch_conf;
TIM_HandleTypeDef ic_handle;
TIM_IC_InitTypeDef ic_ic_init;

input_capture_data_t ic_cntr = {0, 0, 0};
uint32_t ovf_cntr = 0;
float prev_rpm_value = 0;

uint8_t clear_string[] = "                ";

/* Private function prototypes -----------------------------------------------*/
static void SystemClock_Config(void);
static void Error_Handler(void);
static void MPU_Config(void);
static void CPU_CACHE_Enable(void);

void pwm_init();
void pwm_set_duty(float duty);
void adc_init();
uint16_t adc_measure();
void ic_init();
float get_freq();
float get_rpm();

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{
  /* This project template calls firstly two functions in order to configure MPU feature
     and to enable the CPU Cache, respectively MPU_Config() and CPU_CACHE_Enable().
     These functions are provided as template implementation that User may integrate
     in his application, to enhance the performance in case of use of AXI interface
     with several masters. */

  /* Configure the MPU attributes as Write Through */
  MPU_Config();

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


  /* Add your application code here
     */
  BSP_LED_Init(LED_GREEN);
  pwm_init();
  adc_init();
  ic_init();
  BSP_LCD_Init();
  BSP_LCD_LayerDefaultInit(0, LCD_FB_START_ADDRESS);
  BSP_LCD_SelectLayer(0);
  BSP_LCD_DisplayOn();
  BSP_LCD_Clear(LCD_COLOR_BLACK);

  p_ctrler_t p_ctrler;
  pi_ctrler_t pi_ctrler;

  p_init(&p_ctrler);
  p_ctrler.out_max = 100;
  p_ctrler.out_min = 0;
  pi_init(&pi_ctrler);
  pi_ctrler.out_max = 100;
  pi_ctrler.out_min = 0;

  /* Infinite loop */
  while (1)
  {
	  float ref = (float)adc_measure() / 4095 * 4500;
	  float rpm = get_rpm();
	  p_ctrler.ref = ref;
	  p_ctrler.sense = rpm;
	  pi_ctrler.ref = ref;
	  pi_ctrler.sense = rpm;

#ifdef USE_P_CTRLER
	  float duty = p_control(&p_ctrler);

#else
	  float duty = pi_control(&pi_ctrler);
#endif

	  pwm_set_duty(duty);

	  uint8_t buffer[100];
	  sprintf((char*)buffer, "ref   %.f", ref);
	  BSP_LCD_DisplayStringAtLine(1, clear_string);
	  BSP_LCD_DisplayStringAtLine(1, buffer);

	  sprintf((char*)buffer, "sense %.f", rpm);
	  BSP_LCD_DisplayStringAtLine(2, clear_string);
	  BSP_LCD_DisplayStringAtLine(2, buffer);

	  sprintf((char*)buffer, "duty  %.f", duty);
	  BSP_LCD_DisplayStringAtLine(3, clear_string);
	  BSP_LCD_DisplayStringAtLine(3, buffer);

	  HAL_Delay(10);
  }
}

/**
  * @brief  This function will be called if a timer input capture interrupt occures
  * @param  Timer handle, which identifies which timer input capture triggered the interrupt
  * @retval None
  */
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
	ic_cntr.prev = ic_cntr.last;
	ic_cntr.last = TIM2->CCR1;
	ic_cntr.ovf = ovf_cntr;
	ovf_cntr = 0;
}

/**
  * @brief  This function will be called if a timer overflow occures
  * @param  Timer handle, which identifies which timer had overflow
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	ovf_cntr++;
}

/**
  * @brief  Initializes TIM3 as PWM source
  * @param  None
  * @retval None
  */
void pwm_init()
{
	// TIM3 init as PWM
	pwm_handle.Instance = TIM3;
	pwm_handle.State = HAL_TIM_STATE_RESET;
	pwm_handle.Channel = HAL_TIM_ACTIVE_CHANNEL_1;
	pwm_handle.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	pwm_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	pwm_handle.Init.CounterMode = TIM_COUNTERMODE_UP;
	pwm_handle.Init.Period = 0xFFFF;
	pwm_handle.Init.Prescaler = 0;
	HAL_TIM_PWM_Init(&pwm_handle);

	pwm_oc_init.OCFastMode = TIM_OCFAST_DISABLE;
	pwm_oc_init.OCIdleState = TIM_OCIDLESTATE_RESET;
	pwm_oc_init.OCMode = TIM_OCMODE_PWM1;
	pwm_oc_init.OCPolarity = TIM_OCPOLARITY_HIGH;
	pwm_oc_init.Pulse = 0x7FFF;
	HAL_TIM_PWM_ConfigChannel(&pwm_handle, &pwm_oc_init, TIM_CHANNEL_1);
}

/**
  * @brief  Sets the duty cycle of TIM3 CH1
  * @param  duty - duty cycle to set (0.0-100.0)
  * @retval None
  */
void pwm_set_duty(float duty)
{
	uint32_t pulse = pwm_handle.Init.Period * (duty / 100.0);
	pwm_oc_init.Pulse = pulse;
	HAL_TIM_PWM_ConfigChannel(&pwm_handle, &pwm_oc_init, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&pwm_handle, TIM_CHANNEL_1);
}

/**
  * @brief  Initializes ADC3 to measure voltage on CH0
  * @param  None
  * @retval None
  */
void adc_init()
{
	adc_handle.State = HAL_ADC_STATE_RESET;
	adc_handle.Instance = ADC3;
	adc_handle.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2;
	adc_handle.Init.Resolution = ADC_RESOLUTION_12B;
	adc_handle.Init.EOCSelection = ADC_EOC_SEQ_CONV;
	adc_handle.Init.DMAContinuousRequests = DISABLE;
	adc_handle.Init.DataAlign = ADC_DATAALIGN_RIGHT;
	adc_handle.Init.ContinuousConvMode = DISABLE;
	adc_handle.Init.DiscontinuousConvMode = DISABLE;
	adc_handle.Init.ScanConvMode = DISABLE;
	HAL_ADC_Init(&adc_handle);

	adc_ch_conf.Channel = ADC_CHANNEL_0;
	adc_ch_conf.Offset = 0;
	adc_ch_conf.Rank = 1;
	adc_ch_conf.SamplingTime = ADC_SAMPLETIME_480CYCLES;
	HAL_ADC_ConfigChannel(&adc_handle, &adc_ch_conf);
}

/**
  * @brief  Measures the voltage with ADC3 on CH0
  * @param  None
  * @retval Measured value (0-4095)
  */
uint16_t adc_measure()
{
	HAL_ADC_Start(&adc_handle);
	HAL_ADC_PollForConversion(&adc_handle, HAL_MAX_DELAY);
	return HAL_ADC_GetValue(&adc_handle);
}

/**
  * @brief  Initializes TIM2 in input capture mode (CH1)
  * @param  None
  * @retval None
  */
void ic_init()
{
	ic_handle.Instance = TIM2;
	ic_handle.State = HAL_TIM_STATE_RESET;
	ic_handle.Channel = HAL_TIM_ACTIVE_CHANNEL_1;
	ic_handle.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	ic_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	ic_handle.Init.CounterMode = TIM_COUNTERMODE_UP;
	ic_handle.Init.Period = 0xFFFF;
	ic_handle.Init.Prescaler = 0;
	HAL_TIM_IC_Init(&ic_handle);

	ic_ic_init.ICFilter = 0;
	ic_ic_init.ICPolarity = TIM_ICPOLARITY_RISING;
	ic_ic_init.ICPrescaler = TIM_ICPSC_DIV1;
	ic_ic_init.ICSelection = TIM_ICSELECTION_DIRECTTI;
	HAL_TIM_IC_ConfigChannel(&ic_handle, &ic_ic_init, TIM_CHANNEL_1);

	HAL_TIM_Base_Start_IT(&ic_handle);
	HAL_TIM_IC_Start_IT(&ic_handle, TIM_CHANNEL_1);
}

/**
  * @brief  Calculates measured signal frequency based on timer values
  * @param  None
  * @retval frequency in Hz
  */
float get_freq()
{
	HAL_NVIC_DisableIRQ(TIM2_IRQn);
	input_capture_data_t snapshot = ic_cntr;
	HAL_NVIC_EnableIRQ(TIM2_IRQn);

	float steps = (float)snapshot.ovf * ic_handle.Init.Period + snapshot.last - snapshot.prev;
	float tim3_clk_freq = (float)SystemCoreClock / 2 / (ic_handle.Init.Prescaler + 1); // Because clock division is 1x, so only sysclock matters
	float tim3_clk_period = 1/ tim3_clk_freq;
	float signal_period = steps * tim3_clk_period;
	float signal_freq = 1 / signal_period;

	if (isnan(signal_freq) || isinf(signal_freq))
		return -1;
	else
		return signal_freq;
}

/**
  * @brief  Calculates fan RPM
  * @param  None
  * @retval RPM in RPM
  */
float get_rpm()
{
	float rpm = get_freq() * 60 / 7;
	if (rpm < 0) {
		return prev_rpm_value;
	} else {
		prev_rpm_value = rpm;
		return rpm;
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
  *            PLL_Q                          = 9
  *            VDD(V)                         = 3.3
  *            Main regulator output voltage  = Scale1 mode
  *            Flash Latency(WS)              = 7
  * @param  None
  * @retval None
  */
static void SystemClock_Config(void)
{
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
  if(HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /* activate the OverDrive to reach the 216 Mhz Frequency */
  if(HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    Error_Handler();
  }
  
  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2 
     clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;  
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;  
  if(HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
static void Error_Handler(void)
{
  /* User may add here some code to deal with this error */
  while(1)
  {
  }
}

/**
  * @brief  Configure the MPU attributes as Write Through for SRAM1/2.
  * @note   The Base Address is 0x20010000 since this memory interface is the AXI.
  *         The Region Size is 256KB, it is related to SRAM1 and SRAM2  memory size.
  * @param  None
  * @retval None
  */
static void MPU_Config(void)
{
  MPU_Region_InitTypeDef MPU_InitStruct;
  
  /* Disable the MPU */
  HAL_MPU_Disable();

  /* Configure the MPU attributes as WT for SRAM */
  MPU_InitStruct.Enable = MPU_REGION_ENABLE;
  MPU_InitStruct.BaseAddress = 0x20010000;
  MPU_InitStruct.Size = MPU_REGION_SIZE_256KB;
  MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
  MPU_InitStruct.IsBufferable = MPU_ACCESS_NOT_BUFFERABLE;
  MPU_InitStruct.IsCacheable = MPU_ACCESS_CACHEABLE;
  MPU_InitStruct.IsShareable = MPU_ACCESS_SHAREABLE;
  MPU_InitStruct.Number = MPU_REGION_NUMBER0;
  MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL0;
  MPU_InitStruct.SubRegionDisable = 0x00;
  MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_ENABLE;

  HAL_MPU_ConfigRegion(&MPU_InitStruct);

  /* Enable the MPU */
  HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);
}

/**
  * @brief  CPU L1-Cache enable.
  * @param  None
  * @retval None
  */
static void CPU_CACHE_Enable(void)
{
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

/**
  * @}
  */ 

/**
  * @}
  */ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
