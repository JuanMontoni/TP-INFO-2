#include "lib.h"

int main()
{
    estados_t estado = DIA;
    estados_t estado2 = SINMOVIMIENTO; 
    estados_t (*fms[2])(void) = {f_luzapagada1,f_luzprenida1};
    estados_t (*fms2[2])(void) = {f_luzapagada2,f_luzprenida2};
    init_mcu();
    while (1)
    {
        estado = (*fms[estado]);
        estado2 = (*fms2[estado2]);
    }
    return 0;
}
