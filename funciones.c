#include "lib.h"

void init_mcu(void){
    AdcInitStructure_AVR ldr;
    ldr.mode = avr_ADC_MODE_Single_Conversion;
    ldr.prescaler = avr_ADC_Prescaler_64;
    ldr.reference = avr_ADC_REF_Internal;
    ldr.channel = LDR ;
    ldr.resolution = avr_ADC_RES_10Bit; 
    init_adc(ldr);   

    GpioInitStructure_AVR rele;
    rele.port = RELE_PORT;
    rele.pines = RELE_PIN;
    rele.modo = avr_GPIO_mode_Output;
    init_gpio(rele);
}

int lectura_ldr(void){
    return (int)leer_ADC(LDR);
}

estados_t f_iluminar(void)
{
    int intensidadluz;
    intensidadluz = lectura_ldr();
    if(intensidadluz >= INTENSIDADLUZ_SET){
        RELE = 0;
        return APAGAR
    }
    else{ 
       RELE = 1;
       return PRENDER;
    }
        
}

