#include "TCPUtente.h"
#include "../../NET/TCPStrutture.h"
#include <sys/socket.h>

int TCP_Utente_Salva(const int IDConnessione, Utente f)
{
    int r = -1;
    Pacchetto p = Pacchetto_Null();
    p.Comando = TCP_Richiesta_Utente_Salva;

    if (send(IDConnessione, &p, sizeof (Pacchetto), 0) > -1)
        if (send(IDConnessione, &f, sizeof (Utente), 0) > -1)
            recv(IDConnessione, &r, sizeof (int), 0);

    return r;
}

Utente TCP_Utente_ByLogin(const int IDConnessione, const char Nickname[LUser], const char Psw[LNome])
{
    Pacchetto p = Pacchetto_Null();
    Utente f = Utente_Null();

    p.Comando = TCP_Richiesta_Utente_ByLogin;
    cp(Nickname, p.ID1, LUser);
    cp(Psw, p.ID2, LNome);

    if (send(IDConnessione, &p, sizeof (Pacchetto), 0) > -1)
        recv(IDConnessione, &f, sizeof (Utente), 0);

    return f;
}

Utente TCP_Utente_ByID(const int IDConnessione, const char id[LID])
{
    Pacchetto p = Pacchetto_Null();
    Utente f = Utente_Null();

    p.Comando = TCP_Richiesta_Utente_ByID;
    cp(id, p.ID1, LID);

    if (send(IDConnessione, &p, sizeof (Pacchetto), 0) > -1)
        recv(IDConnessione, &f, sizeof (Utente), 0);

    return f;
}

int TCP_Utente_RicercaTutti(const int IDConnessione, Utente elementi[LMAXArray])
{
    int i;
    int tot = 0;
    Pacchetto p = Pacchetto_Null();
    p.Comando = TCP_Richiesta_Utente_RicercaTutti;

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
            if (recv(IDConnessione, &elementi[i], sizeof (Utente), 0) < 0)
                return -1;
    }

    return tot;
}
