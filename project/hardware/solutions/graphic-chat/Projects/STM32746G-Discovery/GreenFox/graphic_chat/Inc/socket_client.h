/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SOCKET_CLIENT_H
#define __SOCKET_CLIENT_H

/* Includes ------------------------------------------------------------------*/
#include "stm32746g_discovery_ts.h"
#include "socket_server.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
#define CLIENT_BUFF_LEN				SERVER_BUFF_LEN
#define CLIENT_SEND_INTERVAL		10
#define CLIENT_RECONNECT_INTERVAL	1000
#define CLIENT_SERVER_IP			"10.27.6.66"

/* Exported functions ------------------------------------------------------- */
void socket_client_thread(void const *argument);

#endif /* __SOCKET_CLIENT_H */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
