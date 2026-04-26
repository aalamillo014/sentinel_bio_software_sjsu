#include "uart_driver.h"
#include <stdio.h>
#include <string.h>

int UART_Init(const char *port_name, int baud_rate) {
    // Placeholder for real UART initialization
    printf("UART initialized on %s at %d baud\n", port_name, baud_rate);
    return 0;
}

int UART_Read(char *buffer, int max_length) {
    // Placeholder for simulated Iridium command input
    const char *simulated_command = "CMD:SET_BEACON:1800";

    if ((int)strlen(simulated_command) >= max_length) {
        return -1;
    }

    strcpy(buffer, simulated_command);
    return strlen(buffer);
}

int UART_Write(const char *data) {
    // Placeholder for radio transmission over UART
    printf("UART TX: %s\n", data);
    return strlen(data);
}
