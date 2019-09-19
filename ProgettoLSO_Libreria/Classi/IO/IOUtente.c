#include "IOUtente.h"
#include <stdio.h>

int Utente_Inserisci(Utente f)
{
    f.Setted = 1;
    GUID(f.IDUtente);
    OrarioCorrente(f.AUDIT_UPD_DATA);
    OrarioCorrente(f.AUDIT_INS_DATA);
    UtenteConnesso(f.AUDIT_INS_USER);
    UtenteConnesso(f.AUDIT_UPD_USER);

    FILE * db = fopen(PathDB(Classe_Utente, f.IDUtente), "wb");

    if (db == NULL)
        return 0;

    fwrite(&f, sizeof (Utente), 1, db);

    fclose(db);

    return 1;
}

int Utente_Aggiorna(Utente f)
{
    f.Setted = 1;
    OrarioCorrente(f.AUDIT_UPD_DATA);
    UtenteConnesso(f.AUDIT_UPD_USER);

    FILE * db = fopen(PathDB(Classe_Utente, f.IDUtente), "wb");

    if (db == NULL)
        return 0;

    fwrite(&f, sizeof (Utente), 1, db);

    fclose(db);

    return 1;
}

int Utente_Salva(Utente f)
{
    if (f.IDUtente[0] == '-' && f.IDUtente[1] == '1')
        return Utente_Inserisci(f);
    else
        return Utente_Aggiorna(f);
}

int Utente_RicercaTutti(Utente elementi[LMAXArray])
{
    int x, y, z, r;
    char ids[LMAXFiles][LMAXArray];

    r = GetFiles(Classe_Utente, ids);
    z = -1;

    for (y = 0; y < r; y++)
    {
        char j[LMAXFiles];

        for (x = 0; x < LMAXFiles; x++)
            j[x] = ids[x][y];

        Utente f = Utente_ByID(j);

        if (f.Setted > 0)
            elementi[z += 1] = f;
    }

    return z + 1;
}

Utente Utente_ByID(const char id[LID])
{
    Utente f = Utente_Null();
    FILE * db = fopen(PathDB(Classe_Utente, id), "rb");

    if (db != NULL)
    {
        fread(&f, sizeof (Utente), 1, db);
        fclose(db);
    }

    if (f.Setted == 1)
        if (f.IDUtente[0] == '-' && f.IDUtente[1] == '1')
            f.Setted = 0;

    return f;
}

Utente Utente_ByLogin(const char Nickname[LUser], const char Psw[LNome])
{
    Utente elementi[LMAXArray];
    int r = Utente_RicercaTutti(elementi);
    int i;

    if (r > 0)
        for (i = 0; i < r; i++)
            if (elementi[i].Setted == 1)
                if (strcmp(elementi[i].Nickname, Nickname) == 0 && strcmp(elementi[i].Psw, Psw) == 0)
                    return elementi[i];

    return Utente_Null();
}