#ifndef __SW_SPI_H
#define __SW_SPI_H

#include "pin.h"

void spi_init(void);
u8 spi_transfer_byte(uint8_t data);


#endif

