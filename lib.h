#ifndef LIB
#define LIB
#include <stdio.h>
#include "avr_api.h"

typedef enum {
    PRENDER = 1,
    APAGAR = 0
}estados_t;

estados_t f_iluminar(void);
/** estados_t f_noiluminar(void); **/

void init_mcu(void);

int lectura_ldr(void);

#define LDR avr_ADC_canal0 

#define RELE_PORT avr_GPIO_C
#define RELE_PIN avr_GPIO_PIN_1
#define RELE avr_GPIOC_OUT_1 

#define INTENSIDADLUZ_SET 512;

#endif