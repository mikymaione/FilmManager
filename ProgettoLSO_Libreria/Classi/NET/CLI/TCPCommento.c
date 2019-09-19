#include "TCPCommento.h"
#include "../../NET/TCPStrutture.h"
#include <sys/socket.h>

int TCP_Commento_Salva(const int IDConnessione, Commento f)
{
    int r = -1;
    Pacchetto p = Pacchetto_Null();
    p.Comando = TCP_Richiesta_Commento_Salva;

    if (send(IDConnessione, &p, sizeof (Pacchetto), 0) > -1)
        if (send(IDConnessione, &f, sizeof (Commento), 0) > -1)
            recv(IDConnessione, &r, sizeof (int), 0);

    return r;
}

int TCP_Commento_Count(const int IDConnessione, const char IDFilm[LID])
{
    int r = -1;
    Pacchetto p = Pacchetto_Null();
    p.Comando = TCP_Richiesta_Commento_Count;
    cp(IDFilm, p.ID1, LID);

    if (send(IDConnessione, &p, sizeof (Pacchetto), 0) > -1)
        recv(IDConnessione, &r, sizeof (int), 0);

    return r;
}

int TCP_Commento_RicercaTutti(const int IDConnessione, const char IDFilm[LID], Commento commenti[LMAXArray])
{
    int i;
    int tot = 0;
    Pacchetto p = Pacchetto_Null();

    p.Comando = TCP_Richiesta_Commento_RicercaTutti;
    cp(IDFilm, p.ID1, LID);

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
            if (recv(IDConnessione, &commenti[i], sizeof (Commento), 0) < 0)
                return -1;
    }

    return tot;
}

Commento TCP_Commento_ByID(const int IDConnessione, const char FilmID[LID], const char ID[LID])
{
    Pacchetto p = Pacchetto_Null();
    Commento f = Commento_Null();

    p.Comando = TCP_Richiesta_Commento_ByID;
    cp(FilmID, p.ID1, LID);
    cp(ID, p.ID2, LID);

    if (send(IDConnessione, &p, sizeof (Pacchetto), 0) > -1)
        recv(IDConnessione, &f, sizeof (Commento), 0);

    return f;
}

