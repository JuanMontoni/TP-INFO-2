#include "lib.h"

int main()
{
    estados_t estado = APAGAR;
    init_mcu();
    while(1)
    {
        switch (estado)
        {
        case APAGAR:
            estado = f_iluminar();
            break;
        case PRENDER:
            estado = f_iluminar();
            break;
        }
    }
    return 0;
}
