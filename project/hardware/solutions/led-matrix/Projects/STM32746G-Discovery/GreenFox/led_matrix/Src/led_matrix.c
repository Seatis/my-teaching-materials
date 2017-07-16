/* Includes ------------------------------------------------------------------*/
#include "led_matrix.h"
#include "stm32f7xx_hal.h"
#include "lcd_log.h"
#include "cmsis_os.h"

/* Private typedef -----------------------------------------------------------*/
typedef struct {
	GPIO_TypeDef *port;
	uint16_t pin;
} led_matrix_pin_t;

/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

// Each LED state is stored in this 2D array
GPIO_PinState led_matrix_state[LED_MATRIX_ROWS][LED_MATRIX_COLS];

// Mutex definition
osMutexDef(LED_MATRIX_MUTEX_DEF);

// Mutex global variable
osMutexId led_matrix_mutex_id;

const led_matrix_pin_t rows[] = {
		{GPIOH, GPIO_PIN_6},     //row[0]
		{GPIOI, GPIO_PIN_0},     //row[1]
		{GPIOG, GPIO_PIN_7},     //row[2]
		{GPIOB, GPIO_PIN_4},     //row[3]
		{GPIOG, GPIO_PIN_6},     //row[4]
		{GPIOC, GPIO_PIN_6},     //row[5]
		{GPIOC, GPIO_PIN_7}      //row[6]
};

const led_matrix_pin_t cols[] = {
		{GPIOB, GPIO_PIN_14},    //col[0]
		{GPIOB, GPIO_PIN_15},    //col[1]
		{GPIOA, GPIO_PIN_8},     //col[2]
		{GPIOA, GPIO_PIN_15},    //col[3]
		{GPIOI, GPIO_PIN_2}      //col[4]
};

/* Private function prototypes -----------------------------------------------*/
void led_matrix_clk_enable(GPIO_TypeDef *port);
void led_matrix_init();
void led_matrix_set(uint8_t row, uint8_t col, uint8_t state);
/* Private functions ---------------------------------------------------------*/

// TODO:
// Write this function!
void led_matrix_set(uint8_t row, uint8_t col, uint8_t state) {
	// TODO:
	// Wait for the mutex
	osMutexWait(led_matrix_mutex_id, osWaitForever);

	// TODO:
	// Change the LED in the selected row and col to the specified state
	// Use the led_matrix_state 2D array variable!
	if (state) {
		led_matrix_state[row][col] = GPIO_PIN_RESET;
	} else {
		led_matrix_state[row][col] = GPIO_PIN_SET;
	}

	// TODO:
	// Release the mutex
	osMutexRelease(led_matrix_mutex_id);
}

// TODO:
// Write this function!
void led_matrix_update_thread(void const *argument)
{
	// TODO:
	// Initialize the pins as outputs and the led_matrix_state 2D array
	led_matrix_init();

	// TODO:
	// Create a mutex
	// Hint: use the LED_MATRIX_MUTEX_DEF
	led_matrix_mutex_id = osMutexCreate(osMutex(LED_MATRIX_MUTEX_DEF));

	LCD_UsrLog("led_matrix - initialized\n");

	// Infinite loop
	while (1) {
		// TODO:
		// Implement the led matrix updater functionality

		// Step 1:
		// Iterate through every column or row
		for (uint8_t c = 0; c < LED_MATRIX_COLS; c++) {
			// Step 2:
			// Wait for the mutex
			osMutexWait(led_matrix_mutex_id, osWaitForever);

			// Step 3:
			// Turn on the column or row
			HAL_GPIO_WritePin(cols[c].port, cols[c].pin, GPIO_PIN_SET);

			// Step 4:
			// Turn on the leds in that column or row
			for (uint8_t r = 0; r < LED_MATRIX_ROWS; r++)
				HAL_GPIO_WritePin(rows[r].port, rows[r].pin, led_matrix_state[r][c]);

			// Step 5:
			// Release the mutex
			osMutexRelease(led_matrix_mutex_id);

			// Step 6:
			// Delay
			osDelay(1);

			// Step 7:
			// Turn off the column or row
			HAL_GPIO_WritePin(cols[c].port, cols[c].pin, GPIO_PIN_RESET);
		}
	}

	// Terminating thread
	while (1) {
		LCD_ErrLog("led_matrix - terminating...\n");
		osThreadTerminate(NULL);
	}
}

void led_matrix_clk_enable(GPIO_TypeDef *port)
{
	if (port == GPIOA)
		__HAL_RCC_GPIOA_CLK_ENABLE();
	else if (port == GPIOB)
		__HAL_RCC_GPIOB_CLK_ENABLE();
	else if (port == GPIOC)
		__HAL_RCC_GPIOC_CLK_ENABLE();
	else if (port == GPIOD)
		__HAL_RCC_GPIOD_CLK_ENABLE();
	else if (port == GPIOE)
		__HAL_RCC_GPIOE_CLK_ENABLE();
	else if (port == GPIOF)
		__HAL_RCC_GPIOF_CLK_ENABLE();
	else if (port == GPIOG)
		__HAL_RCC_GPIOG_CLK_ENABLE();
	else if (port == GPIOH)
		__HAL_RCC_GPIOH_CLK_ENABLE();
	else if (port == GPIOI)
		__HAL_RCC_GPIOI_CLK_ENABLE();
	else if (port == GPIOJ)
		__HAL_RCC_GPIOJ_CLK_ENABLE();
	else if (port == GPIOK)
		__HAL_RCC_GPIOK_CLK_ENABLE();
}

void led_matrix_init()
{
	GPIO_InitTypeDef init_tmp;
	init_tmp.Mode = GPIO_MODE_OUTPUT_PP;
	init_tmp.Pull = GPIO_NOPULL;
	init_tmp.Speed = GPIO_SPEED_FAST;

	// init rows
	for (uint8_t r = 0; r < LED_MATRIX_ROWS; r++) {
		led_matrix_clk_enable(rows[r].port);
		init_tmp.Pin = rows[r].pin;
		HAL_GPIO_Init(rows[r].port, &init_tmp);
	}

	// init columns
	for (uint8_t c = 0; c < LED_MATRIX_COLS; c++) {
		led_matrix_clk_enable(cols[c].port);
		init_tmp.Pin = cols[c].pin;
		HAL_GPIO_Init(cols[c].port, &init_tmp);
	}

	// Initialize the state 2D array
	for (uint8_t c = 0; c < LED_MATRIX_COLS; c++) {
		for (uint8_t r = 0; r < LED_MATRIX_ROWS; r++) {
			led_matrix_state[r][c] = GPIO_PIN_SET;
		}
	}

}

// This thread is a waterfall type animation
void led_matrix_waterfall_thread(void const *argument)
{
	while (1) {
		for (uint8_t r = 0; r < LED_MATRIX_ROWS; r++) {
			for (uint8_t c = 0; c < LED_MATRIX_COLS; c++) {
				led_matrix_set(r, c, 1);
				osDelay(50);
				led_matrix_set(r, c, 0);
			}
		}
	}

	while (1) {
			LCD_ErrLog("led_matrix_waterfall - terminating...\n");
			osThreadTerminate(NULL);
		}
}


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
