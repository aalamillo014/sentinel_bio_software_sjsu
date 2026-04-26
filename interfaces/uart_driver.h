#ifndef UART_DRIVER_H
#define UART_DRIVER_H

int UART_Init(const char *port_name, int baud_rate);
int UART_Read(char *buffer, int max_length);
int UART_Write(const char *data);

#endif
