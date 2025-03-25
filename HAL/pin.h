#ifndef __PIN_H
#define __PIN_H

#include "stm8s_gpio.h"

typedef struct
{
    GPIO_TypeDef* port;
    GPIO_Pin_TypeDef pin;
} pin_t;

static inline void pin_set(pin_t * pin)
{
    GPIO_WriteHigh(pin->port, pin->pin);
}

static inline void pin_reset(pin_t * pin)
{
    GPIO_WriteLow(pin->port, pin->pin);
}

static inline void pin_toggle(pin_t * pin)
{
    GPIO_WriteReverse(pin->port, pin->pin);
}
 
static inline BitStatus pin_read(pin_t * pin)
{
    return GPIO_ReadInputPin(pin->port, pin->pin);
}

#endif