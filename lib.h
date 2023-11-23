#ifndef LIB
#define LIB
#include <stdio.h>
#include "avr_api.h"

typedef enum {
    DIA = 1;
    NOCHE = 0;
    MOVIMIENTO = 1;
    SINMOVIMIENTO = 0;
}estados_t;

estados_t f_luzprenida1(void);
estados_t f_luzapagada1(void); 

estados_t f_luzprenida2(void);
estados_t f_luzapagada2(void); 

void init_mcu(void);

int lectura_ldr(void);

/** int lectura_hcsr501 (void); **/

#define LDR avr_ADC_canal0 

#define RELE1_PORT avr_GPIO_C
#define RELE1_PIN avr_GPIO_PIN_1
#define RELE1 avr_GPIOC_OUT_1 

#define HCSR501_PORT avr_GPIO_C
#define HCSR501_PIN avr_GPIO_PIN_0
#define HCSR501 avr_GPIOC_IN_0

#define RELE2_PORT avr_GPIO_C
#define RELE2_PIN avr_GPIO_PIN_2
#define RELE2 avr_GPIOC_OUT_2

#define INTENSIDADLUZ_SET 512;

#endif
