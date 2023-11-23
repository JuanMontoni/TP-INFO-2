#include "lib.h"

void init_mcu(void){
    AdcInitStructure_AVR ldr;
    ldr.mode = avr_ADC_MODE_Single_Conversion;
    ldr.prescaler = avr_ADC_Prescaler_64;
    ldr.reference = avr_ADC_REF_Internal;
    ldr.channel = LDR ;
    ldr.resolution = avr_ADC_RES_10Bit; 
    init_adc(ldr);   

    GpioInitStructure_AVR rele1;
    rele1.port = RELE1_PORT;
    rele1.pines = RELE1_PIN;
    rele1.modo = avr_GPIO_mode_Output;
    init_gpio(rele1);

    GpioInitStructure_AVR hcsr501;
    hcsr501.port = HCSR501_PORT;
    hcsr501.pin = HCSR501_PIN;
    hcsr501.modo = avr_GPIO_mode_Input;
    init_gpio(hcsr501);

    GpioInitStructure_AVR rele2;
    rele2.port = RELE2_PORT;
    rele2.pines = RELE2_PIN;
    rele2.modo = avr_GPIO_mode_Output;
    init_gpio(rele2);
}

int lectura_ldr(void){
    return (int)leer_ADC(LDR);
}


estados_t f_luzprenida1(void)
{
    int intensidadluz;
    intensidadluz = lectura_ldr();
    RELE1 = 1;
    if(intensidadluz >= INTENSIDADLUZ_SET){
        RELE1 = 0;
        return DIA;
    }
    else{    
       return NOCHE;
    }
        
}


estados_t f_luzapagada1(void)
{
    int intensidadluz;
    intensidadluz = lectura_ldr();
    RELE1 = 0;
    if(intensidadluz <= INTENSIDADLUZ_SET){
        RELE1 = 1;
        return NOCHE;
    }
    else{      
        return DIA;
    }
}


estados_t f_luzprenida1(void)
{
    RELE2 = 1;
    if (avr_GPIOC_PIN_0 = 0){
        RELE2 = 0;
        return SINMOVIMIENTO;
    }
    else{
        return MOVIMIENTO;
    }
}


estados_t f_luzapagada1(void)
{
    RELE2 = 0;
    if(avr_GPIOC_PIN_0 = 1){
        RELE2 = 1;
        return MOVIMIENTO;
    }
    else{
        return SINMOVIMIENTO;
    }
}
