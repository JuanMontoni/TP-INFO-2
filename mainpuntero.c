#include "lib.h"

int main()
{
    estados_t estado = NOCHE;
    estados_t (*fms[2])(viod) = {f_luzapagada,f_luzprenida};
    init_mcu();
    while (1)
    {
        estado = (*fms[estado]);
    }
    return 0;
}
