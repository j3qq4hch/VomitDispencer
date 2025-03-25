#include "spi.h"

static  pin_t spi_clk  = {GPIOB, GPIO_Pin_7};
static  pin_t spi_mosi = {GPIOB, GPIO_Pin_4};
static  pin_t spi_miso = {GPIOB, GPIO_Pin_5};

void spi_init(void) 
{
    GPIO_Init(spi_clk.port,  spi_clk.pin,  GPIO_Mode_Out_PP_High_Fast );
    GPIO_Init(spi_mosi.port, spi_mosi.pin, GPIO_Mode_Out_PP_Low_Fast );
    GPIO_Init(spi_miso.port, spi_miso.pin, GPIO_Mode_In_PU_No_IT );
}

uint8_t spi_transfer_byte(uint8_t data) 
{    
    uint8_t received_data = 0;
    for (uint8_t i = 0; i < 8; i++) 
    {        
        pin_reset(&spi_clk);    
        if (data & 0x80) 
        {
            pin_set(&spi_mosi);
        } 
        else 
        {
            pin_reset(&spi_mosi);
        }
        data <<= 1;
        
        pin_set(&spi_clk);    
        
        received_data <<= 1;     
        if (pin_read(&spi_miso))
        {
            received_data |= 0x01;
        }
    }    
      return received_data;
}


