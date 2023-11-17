#ifndef LIB
#define LIB
#include <stdio.h>
#include "avr_api.h"

typedef enum {
    DIA = 1;
    NOCHE = 0;
}estados_t;

estados_t f_luzprenida(void);
estados_t f_luzapagada(void); 

void init_mcu(void);

int lectura_ldr(void);

#define LDR avr_ADC_canal0 

#define RELE_PORT avr_GPIO_C
#define RELE_PIN avr_GPIO_PIN_1
#define RELE avr_GPIOC_OUT_1 

#define INTENSIDADLUZ_SET 512;

#endif