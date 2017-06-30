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
			// Define buffer for incoming message, which will contain one TS_StateTypeDef variable
			uint8_t buff[SERVER_BUFF_LEN];
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
					LCD_ErrLog("Socket server - recv bytes count invalid ");
					char buff2[10];
					LCD_UsrLog(itoa(received_bytes, buff2, 10));
					LCD_UsrLog("\n");
				} else {
					/*
					// Get the coordinates from the buffer
					int x;
					int y;
					memcpy(&x, &buff[0], sizeof(int));
					memcpy(&y, &buff[sizeof(int)], sizeof(int));

					// Print a debug message
					char buff2[10];
					LCD_UsrLog("Socket server - ");
					LCD_UsrLog("x=");
					LCD_UsrLog(itoa(x, buff2, 10));
					LCD_UsrLog(" y=");
					LCD_UsrLog(itoa(y, buff2, 10));
					LCD_UsrLog("\n");
					*/
					// Print a debug message
					if (ts_data.touchDetected) {
						/*
						char buff2[10];
						LCD_UsrLog("Socket server - ");
						LCD_UsrLog("x=");
						LCD_UsrLog(itoa(ts_data.touchX[0], buff2, 10));
						LCD_UsrLog(" y=");
						LCD_UsrLog(itoa(ts_data.touchY[0], buff2, 10));
						LCD_UsrLog("\n");
						*/
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
		osDelay(10);
	}
}

int connect_to_server(int *client_sock, uint16_t server_port, char *server_ip)
{
	// Creating client socket
	(*client_sock) = socket(PF_INET, SOCK_STREAM, IPPROTO_IP);
	if (*client_sock < 0) {
		LCD_ErrLog("Socket client - can't create socket\n");
		return -1;
	}

	// Creating server address
	struct sockaddr_in addr_in;
	addr_in.sin_family = AF_INET;
	addr_in.sin_port = htons(server_port);
	addr_in.sin_addr.s_addr = inet_addr(server_ip);

	// Connecting the client socket to the server
	int connect_retval = connect(*client_sock, (struct sockaddr *)&addr_in, sizeof(addr_in));
	if (connect_retval < 0) {
		LCD_ErrLog("Socket client - can't connect to server\n");
		return -1;
	}
	else {
		LCD_UsrLog("Socket client - connected to server\n");
		return 0;
	}
}


int send_coordinates(int *socket, TS_StateTypeDef *ts_data_ptr)
{
	/*
	// Get coordinate data
	int x;
	int y;
	x = ts_data_ptr->touchX[0];
	y = ts_data_ptr->touchY[0];

	// Put data into a byte buffer
	uint8_t buff[CLIENT_BUFF_LEN];
	memcpy(&buff[0], &x, sizeof(x));
	memcpy(&buff[sizeof(x)], &y, sizeof(y));

	// Send the message to the server
	int sent_bytes = send(*socket, buff, CLIENT_BUFF_LEN, 0);

	*/

	int sent_bytes = send(*socket, ts_data_ptr, CLIENT_BUFF_LEN, 0);

	if (sent_bytes < 0)
		LCD_ErrLog("Socket client - can't send ts data\n");

	return sent_bytes;
}


void socket_client_thread(void *argument)
{
	LCD_UsrLog("Socket client - startup...\n");
	LCD_UsrLog("Socket client - waiting for IP address...\n");
	// Wait for an IP address
	while (!is_ip_ok())
		osDelay(10);

	// Try to connect to server in an infinite loop
	while (1) {
		int connected = 0;
		int client_socket;

		if (connect_to_server(&client_socket, SERVER_PORT, "169.254.0.1") == 0)
			connected = 1;

		while (connected) {
			// Get touch data
			TS_StateTypeDef ts_data;
			BSP_TS_GetState(&ts_data);
			send_coordinates(&client_socket, &ts_data);
			osDelay(10);
		}

		closesocket(client_socket);
	}
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
