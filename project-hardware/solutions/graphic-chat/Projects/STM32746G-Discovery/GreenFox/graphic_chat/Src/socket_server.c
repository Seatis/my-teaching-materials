/* Includes ------------------------------------------------------------------*/
/*
#include "lwip/opt.h"
#include "main.h"
#include "lwip/dhcp.h"
#include "app_ethernet.h"
#include "ethernetif.h"
*/
#include "socket_server.h"
#include "lcd_log.h"
#include "cmsis_os.h"
#include "app_ethernet.h"
#include "lwip/sockets.h"
#include "stm32746g_discovery_ts.h"
#include <string.h>

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

void terminate_thread()
{
	while (1)
		osThreadTerminate(NULL);
}

void LCD_Log_Num(int num)
{
	char buff[32];
	LCD_UsrLog(itoa(num, buff, 32));
	LCD_UsrLog("\n");
}

// TODO:
// Implement this function!
void socket_server_thread(void const *argument)
{
	LCD_UsrLog("Socket server - startup...\n");
	LCD_UsrLog("Socket server - waiting for IP address...\n");

	// Wait for an IP address
	while (!is_ip_ok())
		osDelay(10);
	LCD_UsrLog("Socket server - IP address is ok\n");

	// Create server socket
	int server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
	if (server_socket < 0) {
		LCD_ErrLog("Socket server - can't create socket\n");
		terminate_thread();
	}
	LCD_UsrLog("Socket server - socket created\n");

	// Create address structure and bind the socket to it
	struct sockaddr_in server_addr;
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(SERVER_PORT);
	server_addr.sin_addr.s_addr = INADDR_ANY;
	if (bind(server_socket, (struct sockaddr*)&(server_addr), sizeof(server_addr)) < 0) {
		LCD_ErrLog("Socket server - can't bind socket\n");
		terminate_thread();
	}
	LCD_UsrLog("Socket server - socket bind ok\n");

	// Start listening
	if (listen(server_socket, SERVER_QUEUE_SIZE) < 0) {
		LCD_ErrLog("Socket server - can't listen\n");
		terminate_thread();
	}
	LCD_UsrLog("Socket server - listening...\n");

	struct sockaddr_in client_addr;
	socklen_t client_addr_len = sizeof(client_addr);
	int client_socket;

	while (1) {
		// Accept incoming connections
		client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_addr_len);
		LCD_UsrLog("Socket server - connection accepted\n");
		// Check the client socket
		if (client_socket < 0) {
			LCD_ErrLog("Socket server - invalid client socket\n");
		} else {
			int received_bytes;
			// Receive data
			do {
				TS_StateTypeDef ts_data;
				received_bytes = recv(client_socket, &ts_data, SERVER_BUFF_LEN, 0);

				// Check for error
				if (received_bytes < 0) {
					// recv failed
					LCD_ErrLog("Socket server - can't receive\n");
				} else if (received_bytes != (SERVER_BUFF_LEN)) {
					// recv received too much or not enough bytes
					LCD_ErrLog("Socket server - recv bytes count invalid: ");
					LCD_Log_Num(received_bytes);
				} else {
					// Print circles
					if (ts_data.touchDetected) {
						BSP_LCD_SetTextColor(LCD_COLOR_RED);
						BSP_LCD_FillCircle(ts_data.touchX[0], ts_data.touchY[0], 5);
					}
				}
			} while (received_bytes > 0);

			// Close the socket
			closesocket(client_socket);
			LCD_UsrLog("Socket server - connection closed\n");
		}
	}

	// Close socket
	closesocket(server_socket);

	while (1) {
		LCD_UsrLog("Socket server - server socket closed\n");
		osDelay(1000);
	}
}


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
