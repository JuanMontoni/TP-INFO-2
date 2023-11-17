#include "lib.h"

int main()
{
    estados_t estado = NOCHE;
    init_mcu();
    while(1)
    {
        switch (estado)
        {
        case NOCHE:
            estado = f_luzprenida();
            break;
        case DIA:
            estado = f_luzapagada();
            break;
        }
    }
    return 0;
}
