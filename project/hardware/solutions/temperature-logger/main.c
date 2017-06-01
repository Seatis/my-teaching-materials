#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "rs232/rs232.h"
#include "printer.h"
#include "parser.h"
#include "file.h"

int main()
{
	int logging_is_running = 0;
	comEnumerate();
	print_startup_message();

	while (1) {
		if (kbhit()) {
			char key = getch();
			switch (key) {
			case 'h':
				print_startup_message();
				break;
			case 'l':
				print_port_list();
				break;
			case 'p':
				get_port_name();
				break;
			case 'w':
				get_write_file_name();
				break;
			case 'o':
				open_port();
				break;
			case 's':
				if (logging_is_running) {
					logging_is_running = 0;
					printf("Logging stopped\n");
				} else {
					logging_is_running = 1;
					printf("Logging started\n");
				}
				break;
			case 'c':
				close_port();
				break;
			case 'r':
				get_read_file_name();
				break;
			case 'a':
				get_average();
				break;
			default:
				break;
			}

			// Exit
			if (key == 'e')
				break;
		}

		// Logger
		if (logging_is_running) {
			if (log_data() != 0) {
				printf("Logging error.\n");
				printf("Logging stopped\n");
				logging_is_running = 0;
			}
		}
	}

	comTerminate();
	return 0;
}
