#include "lib.h"

int main()
{
    estados_t estado = NOCHE;
    estados_t estado2 = SINMOVIMIENTO;
    init_mcu();
    while(1)
    {
        switch (estado)
        {
        case NOCHE:
            estado = f_luzprenida1();
            break;
        case DIA:
            estado = f_luzapagada1();
            break;
        }
        switch (estado2)
        {
        case MOVIMIENTO:
            estado2 = f_luzprenida2();
            break;
        case SINMOVIMIENTO;
            estado2 = f_luzapagada2();
            break;
        }
    }
    return 0;
}

