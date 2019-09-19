#include "SERFilm.h"
#include "../../NET/TCPStrutture.h"
#include "../../IO/IOFilm.h"
#include <sys/socket.h>

int SEF_Film_Salva(const int IDConnessione)
{
    Film f = Film_Null();

    if (recv(IDConnessione, &f, sizeof (Film), 0) < 0)
        return -1;

    int r = Film_Salva(f);

    return send(IDConnessione, &r, sizeof (int), 0);
}

int SER_Film_ByID(const int IDConnessione, const char id[LID])
{
    Film f = Film_ByID(id);

    return send(IDConnessione, &f, sizeof (Film), 0);
}

int SER_Film_RicercaTutti(const int IDConnessione)
{
    int i;
    Pacchetto p = Pacchetto_Null();
    Film films[LMAXArray];
    int tot = Film_RicercaTutti(films);

    p.Comando = TCP_Richiesta_Film_RicercaTutti_TOT;
    p.valore1 = tot;

    if (send(IDConnessione, &p, sizeof (Pacchetto), 0) > -1)
        for (i = 0; i < tot; i++)
            send(IDConnessione, &films[i], sizeof (Film), 0);

    return tot;
}