#include "lib.h"

int main()
{
    estados_t estado = NOCHE;
    estados_t (*fms[2])(void) = {f_luzapagada1,f_luzprenida1};
    init_mcu();
    while (1)
    {
        estado = (*fms[estado]);
    }
    return 0;
}
