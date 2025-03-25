
#include "stm8s.h"
#include "pin.h"
#include "dfplayer.h"
#include "uart.h"

pin_t df_pwren_pin = {GPIOD, GPIO_PIN_4};
pin_t df_busy_pin  = {GPIOD, GPIO_PIN_3};
//pin_t isr_pin      = {GPIOB, GPIO_PIN_4};

void main(void)
{
 
  GPIO_Init (df_pwren_pin.port, df_pwren_pin.pin, GPIO_MODE_OUT_PP_LOW_SLOW);
  //GPIO_Init (isr_pin.port, isr_pin.pin, GPIO_MODE_OUT_PP_LOW_SLOW);
  UART1_Init((uint32_t)9600, UART1_WORDLENGTH_8D, UART1_STOPBITS_1, UART1_PARITY_NO, UART1_SYNCMODE_CLOCK_DISABLE, UART1_MODE_TXRX_ENABLE);

  dfplayer_init();
  while (1)
  {
    pin_set(&df_pwren_pin);
    pin_reset(&df_pwren_pin);
    asm("NOP");
  }
}

#ifdef USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param file: pointer to the source file name
  * @param line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif