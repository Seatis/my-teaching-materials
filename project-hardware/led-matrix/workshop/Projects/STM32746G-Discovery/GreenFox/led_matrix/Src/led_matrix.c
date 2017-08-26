/* Includes ------------------------------------------------------------------*/
#include "led_matrix.h"
#include "stm32f7xx_hal.h"
#include "lcd_log.h"
#include "cmsis_os.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

// Each LED state is stored in this 2D array
GPIO_PinState led_matrix_state[LED_MATRIX_ROWS][LED_MATRIX_COLS];

// Mutex definition
osMutexDef(LED_MATRIX_MUTEX_DEF);

// Mutex global variable
osMutexId led_matrix_mutex_id;

/* Private function prototypes -----------------------------------------------*/
void led_matrix_set(uint8_t row, uint8_t col, uint8_t state);
/* Private functions ---------------------------------------------------------*/

// TODO:
// Write this function!
void led_matrix_set(uint8_t row, uint8_t col, uint8_t state) {
	// TODO:
	// Wait for the mutex

	// TODO:
	// Change the LED in the selected row and col to the specified state
	// Use the led_matrix_state 2D array variable!

	// TODO:
	// Release the mutex
}

// TODO:
// Write this function!
void led_matrix_update_thread(void const *argument)
{
	// TODO:
	// Initialize the pins as outputs and the led_matrix_state 2D array

	// TODO:
	// Create a mutex
	// Use the LED_MATRIX_MUTEX_DEF

	LCD_UsrLog("led_matrix - initialized\n");

	// Infinite loop
	while (1) {
		// TODO:
		// Implement the led matrix updater functionality

		// Step 1:
		// Iterate through every column or row

			// Step 2:
			// Wait for the mutex


			// Step 3:
			// Turn on the column or row


			// Step 4:
			// Turn on the leds in that column or row


			// Step 5:
			// Release the mutex


			// Step 6:
			// Delay


			// Step 7:
			// Turn off the column or row
	}

	// Terminating thread
	while (1) {
		LCD_ErrLog("led_matrix - terminating...\n");
		osThreadTerminate(NULL);
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
