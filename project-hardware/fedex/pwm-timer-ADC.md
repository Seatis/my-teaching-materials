# Closed loop control

How to initialize a TIM low level resource?
- First  look around in your STM32CubeF7 system folder:
there is a folder called *Examples*. In that folder you can find like twenty other folder, we are looking for the TIM low layer resources so we go to the folder called *TIM*. You can find a *readme.txt*, it contains a lot of useful (and useless) information.
- read the *readme.txt*
- After that open example project you have found earlier in Eclipse.
- In the *Drivers* folder you can find the *STM32F7xx_HAL_Driver* folder which contains a .c file for each resource.
- Find and open *stm32f7xx_hal_tim.c*, you will find the whole documentation there.

```
==============================================================================
 ##### TIMER Generic features #####
 ==============================================================================
 [..] The Timer features include:
 (#) 16-bit up, down, up/down auto-reload counter.
 (#) 16-bit programmable prescaler allowing dividing (also on the fly) the
 counter clock frequency either by any factor between 1 and 65536.
 (#) Up to 4 independent channels for:
 (++) Input Capture
 (++) Output Compare
 (++) PWM generation (Edge and Center-aligned Mode)
 (++) One-pulse mode output

 ##### How to use this driver #####
 ==============================================================================
 [..]
 (#) Initialize the TIM low level resources by implementing the following functions
 depending from feature used :
 (++) Time Base : HAL_TIM_Base_MspInit()
 (++) Input Capture : HAL_TIM_IC_MspInit()
 (++) Output Compare : HAL_TIM_OC_MspInit()
 (++) PWM generation : HAL_TIM_PWM_MspInit()
 (++) One-pulse mode output : HAL_TIM_OnePulse_MspInit()
 (++) Encoder mode output : HAL_TIM_Encoder_MspInit()

 (#) Initialize the TIM low level resources :
 (##) Enable the TIM interface clock using __HAL_RCC_TIMx_CLK_ENABLE();
 (##) TIM pins configuration
 (+++) Enable the clock for the TIM GPIOs using the following function:
 __HAL_RCC_GPIOx_CLK_ENABLE();
 (+++) Configure these TIM pins in Alternate function mode using HAL_GPIO_Init();

 (#) The external Clock can be configured, if needed (the default clock is the
 internal clock from the APBx), using the following function:
 HAL_TIM_ConfigClockSource, the clock configuration should be done before
 any start function.

 (#) Configure the TIM in the desired functioning mode using one of the
 initialization function of this driver:
 (++) HAL_TIM_Base_Init: to use the Timer to generate a simple time base
 (++) HAL_TIM_OC_Init and HAL_TIM_OC_ConfigChannel: to use the Timer to generate an
 Output Compare signal.
 (++) HAL_TIM_PWM_Init and HAL_TIM_PWM_ConfigChannel: to use the Timer to generate a
 PWM signal.
 (++) HAL_TIM_IC_Init and HAL_TIM_IC_ConfigChannel: to use the Timer to measure an
 external signal.
 (++) HAL_TIM_OnePulse_Init and HAL_TIM_OnePulse_ConfigChannel: to use the Timer
 in One Pulse Mode.
 (++) HAL_TIM_Encoder_Init: to use the Timer Encoder Interface.

 (#) Activate the TIM peripheral using one of the start functions depending from the feature used:
 (++) Time Base : HAL_TIM_Base_Start(), HAL_TIM_Base_Start_DMA(), HAL_TIM_Base_Start_IT()
 (++) Input Capture :  HAL_TIM_IC_Start(), HAL_TIM_IC_Start_DMA(), HAL_TIM_IC_Start_IT()
 (++) Output Compare : HAL_TIM_OC_Start(), HAL_TIM_OC_Start_DMA(), HAL_TIM_OC_Start_IT()
 (++) PWM generation : HAL_TIM_PWM_Start(), HAL_TIM_PWM_Start_DMA(), HAL_TIM_PWM_Start_IT()
 (++) One-pulse mode output : HAL_TIM_OnePulse_Start(), HAL_TIM_OnePulse_Start_IT()
 (++) Encoder mode output : HAL_TIM_Encoder_Start(), HAL_TIM_Encoder_Start_DMA(), HAL_TIM_Encoder_Start_IT().

 (#) The DMA Burst is managed with the two following functions:
 HAL_TIM_DMABurst_WriteStart()
 HAL_TIM_DMABurst_ReadStart()
```
Read it!
Try out simple ideas.
Discover how the functions work.

## Exercise

Creat a simple project where you initialize for example an ADC peripheral. Try to controll two DC motors with it. Try to controll the motors through sockets. For example create a project where you controll the voltage for the motor via ADC and the reference through a socket.
