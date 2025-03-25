#ifndef UART_H
#define UART_H

#include "stm8s.h"

void uart_send_buf(const uint8_t * data, uint8_t len);
uint8_t uart_receive();

#endif