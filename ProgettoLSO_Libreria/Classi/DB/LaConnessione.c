#include "LaConnessione.h"
#include "../FN/GB.h"
#include "../Constanti.h"

LaConnessione LaConnessione_New(const char Server[LMAXFiles], const int Porta)
{
    LaConnessione f = {
        .Setted = 0,
        .Porta = Porta
    };

    cp(Server, f.Server, LMAXFiles);

    return f;
}

LaConnessione LaConnessione_Null()
{
    LaConnessione f = {
        .Setted = -1,
        .Porta = -1,
        .Server = ""
    };

    return f;
}