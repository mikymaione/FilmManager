#include "TCPFilm.h"
#include "../../NET/TCPStrutture.h"
#include <sys/socket.h>

int TCP_Film_Salva(const int IDConnessione, Film f)
{
    int r = -1;
    Pacchetto p = Pacchetto_Null();
    p.Comando = TCP_Richiesta_Film_Salva;

    if (send(IDConnessione, &p, sizeof (Pacchetto), 0) > -1)
        if (send(IDConnessione, &f, sizeof (Film), 0) > -1)
            recv(IDConnessione, &r, sizeof (int), 0);

    return r;
}

Film TCP_Film_ByID(const int IDConnessione, const char id[LID])
{
    Pacchetto p = Pacchetto_Null();
    Film f = Film_Null();

    p.Comando = TCP_Richiesta_Film_ByID;
    cp(id, p.ID1, LID);

    if (send(IDConnessione, &p, sizeof (Pacchetto), 0) > -1)
        recv(IDConnessione, &f, sizeof (Film), 0);

    return f;
}

int TCP_Film_RicercaTutti(const int IDConnessione, Film films[LMAXArray])
{
    int i;
    int tot = 0;
    Pacchetto p = Pacchetto_Null();
    p.Comando = TCP_Richiesta_Film_RicercaTutti;

    if (send(IDConnessione, &p, sizeof (Pacchetto), 0) < 0)
    {
        return -1;
    }
    else
    {
        p = Pacchetto_Null();

        if (recv(IDConnessione, &p, sizeof (Pacchetto), 0) < 0)
            return -1;

        tot = p.valore1;

        for (i = 0; i < tot; i++)
            if (recv(IDConnessione, &films[i], sizeof (Film), 0) < 0)
                return -1;
    }

    return tot;
}