#include "SERUtente.h"
#include "../../NET/TCPStrutture.h"
#include "../../IO/IOUtente.h"
#include <sys/socket.h>

int SEF_Utente_Salva(const int IDConnessione)
{
    Utente f = Utente_Null();

    if (recv(IDConnessione, &f, sizeof (Utente), 0) < 0)
        return -1;

    int r = Utente_Salva(f);

    return send(IDConnessione, &r, sizeof (int), 0);
}

int SER_Utente_ByID(const int IDConnessione, const char id[LID])
{
    Utente f = Utente_ByID(id);

    return send(IDConnessione, &f, sizeof (Utente), 0);
}

int SER_Utente_ByLogin(const int IDConnessione, const char Nickname[LUser], const char Psw[LNome])
{
    Utente f = Utente_ByLogin(Nickname, Psw);

    return send(IDConnessione, &f, sizeof (Utente), 0);
}

int SER_Utente_RicercaTutti(const int IDConnessione)
{
    int i;
    Pacchetto p = Pacchetto_Null();
    Utente elementi[LMAXArray];
    int tot = Utente_RicercaTutti(elementi);

    p.Comando = TCP_Richiesta_Utente_RicercaTutti_TOT;
    p.valore1 = tot;

    if (send(IDConnessione, &p, sizeof (Pacchetto), 0) > -1)
        for (i = 0; i < tot; i++)
            send(IDConnessione, &elementi[i], sizeof (Utente), 0);

    return tot;
}