#include "stm8s_uart1.h"


void uart_send_buf(const uint8_t * data, uint8_t len) 
{
    for(uint8_t i = 0; i < len; i++) 
    {
        while(UART1_GetFlagStatus(UART1_FLAG_TXE)!=SET);
        UART1_SendData8(data[i]);   
    }
    while(UART1_GetFlagStatus(UART1_FLAG_TC)!=SET);
}

uint8_t uart_receive() 
{
    while(UART1_GetFlagStatus(UART1_FLAG_RXNE)!=SET);
    return UART1_ReceiveData8();
}
