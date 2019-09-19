
#include "TCPStrutture.h"

char * Errore(const char * testo, int errno)
{
    char * r = (char *) calloc(300, sizeof (char));

    sprintf(r, "%s %i\n", testo, errno);

    return r;
}

Pacchetto Pacchetto_Null()
{
    Pacchetto f = {
        .Comando = TCP_ComandoNonSettato,
        .ID1 = "",
        .ID2 = "",
        .ID3 = ""
    };

    return f;
}