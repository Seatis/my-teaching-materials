#include "adc.h"

ADC_HandleTypeDef AdcHandle;

 void adc_init()
{
	// A0 is PA0, ADC3 IN0

	// Enable clocks
	__HAL_RCC_ADC3_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();

	// Initialize GPIO as input
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.Pin = GPIO_PIN_0;	// pin 0 of GPIOA
	GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	/*##-1- Configure the ADC peripheral #######################################*/
	AdcHandle.Instance          		 = ADC3;

	AdcHandle.Init.ClockPrescaler        = ADC_CLOCKPRESCALER_PCLK_DIV4;
	AdcHandle.Init.Resolution            = ADC_RESOLUTION_12B;
	AdcHandle.Init.ScanConvMode          = DISABLE;
	AdcHandle.Init.ContinuousConvMode    = DISABLE;
	AdcHandle.Init.DiscontinuousConvMode = DISABLE;
	AdcHandle.Init.NbrOfDiscConversion   = 0;
	AdcHandle.Init.DataAlign             = ADC_DATAALIGN_RIGHT;
	AdcHandle.Init.NbrOfConversion       = 1;
	AdcHandle.Init.DMAContinuousRequests = DISABLE;
	AdcHandle.Init.EOCSelection          = DISABLE;

	HAL_ADC_Init(&AdcHandle);

	/*##-2- Configure ADC regular channel ######################################*/
	ADC_ChannelConfTypeDef sConfig;

	sConfig.Channel      = ADC_CHANNEL_0;
	sConfig.Rank         = 1;
	sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
	sConfig.Offset       = 0;

	HAL_ADC_ConfigChannel(&AdcHandle, &sConfig);
}

 uint32_t adc_get_voltage(){
	 HAL_ADC_Start(&AdcHandle);
	 HAL_ADC_PollForConversion(&AdcHandle, HAL_MAX_DELAY);
	 return HAL_ADC_GetValue(&AdcHandle);
 }
