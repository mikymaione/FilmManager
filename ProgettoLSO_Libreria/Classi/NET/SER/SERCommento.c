#include "SERFilm.h"
#include "../../NET/TCPStrutture.h"
#include "../../IO/IOCommento.h"
#include <sys/socket.h>

int SER_Commento_Salva(const int IDConnessione)
{
    Commento f = Commento_Null();

    if (recv(IDConnessione, &f, sizeof (Commento), 0) < 0)
        return -1;

    int r = Commento_Salva(f);

    return send(IDConnessione, &r, sizeof (int), 0);
}

int SER_Commento_Count(const int IDConnessione, const char IDFilm[LID])
{
    int f = Commento_Count(IDFilm);

    return send(IDConnessione, &f, sizeof (int), 0);
}

int SER_Commento_RicercaTutti(const int IDConnessione, const char IDFilm[LID])
{
    int i;
    Pacchetto p = Pacchetto_Null();
    Commento commenti[LMAXArray];
    int tot = Commento_RicercaTutti(IDFilm, commenti);

    p.Comando = TCP_Richiesta_Commento_RicercaTutti_Tot;
    p.valore1 = tot;

    if (send(IDConnessione, &p, sizeof (Pacchetto), 0) > -1)
        for (i = 0; i < tot; i++)
            send(IDConnessione, &commenti[i], sizeof (Commento), 0);

    return tot;
}

int SER_Commento_ByID(const int IDConnessione, const char FilmID[LID], const char ID[LID])
{
    Commento f = Commento_ByID(FilmID, ID);

    return send(IDConnessione, &f, sizeof (Commento), 0);
}