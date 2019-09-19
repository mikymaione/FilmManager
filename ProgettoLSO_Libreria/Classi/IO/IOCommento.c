#include "IOCommento.h"
#include <stdio.h>

int Commento_Inserisci(Commento f)
{
    f.Setted = 1;
    GUID(f.IDCommento);
    OrarioCorrente(f.AUDIT_UPD_DATA);
    OrarioCorrente(f.AUDIT_INS_DATA);
    UtenteConnesso(f.AUDIT_INS_USER);
    UtenteConnesso(f.AUDIT_UPD_USER);

    FILE * db = fopen(PathDB2(Classe_Commento, f.IDCommento, f.IDFilm), "wb");

    if (db == NULL)
        return 0;

    fwrite(&f, sizeof (Commento), 1, db);

    fclose(db);

    return 1;
}

int Commento_Aggiorna(Commento f)
{
    f.Setted = 1;
    OrarioCorrente(f.AUDIT_UPD_DATA);
    UtenteConnesso(f.AUDIT_UPD_USER);

    FILE * db = fopen(PathDB2(Classe_Commento, f.IDCommento, f.IDFilm), "wb");

    if (db == NULL)
        return 0;

    fwrite(&f, sizeof (Commento), 1, db);

    fclose(db);

    return 1;
}

int Commento_Salva(Commento f)
{
    if (f.IDCommento[0] == '-' && f.IDCommento[1] == '1')
        return Commento_Inserisci(f);
    else
        return Commento_Aggiorna(f);
}

int Commento_Count(const char IDFilm[LID])
{
    return GetFilesCount2(Classe_Commento, IDFilm);
}

int Commento_RicercaTutti(const char IDFilm[LID], Commento commenti[LMAXArray])
{
    int x, y, z, r;
    char ids[LMAXFiles][LMAXArray];

    r = GetFiles2(Classe_Commento, ids, IDFilm);
    z = -1;

    for (y = 0; y < r; y++)
    {
        char j[LMAXFiles];

        for (x = 0; x < LMAXFiles; x++)
            j[x] = ids[x][y];

        Commento f = Commento_ByID(IDFilm, j);

        if (f.Setted > 0)
            commenti[z += 1] = f;
    }

    return z + 1;
}

Commento Commento_ByID(const char IDFilm[LID], const char id[LID])
{
    Commento f = Commento_Null();
    FILE * db = fopen(PathDB2(Classe_Commento, id, IDFilm), "rb");

    if (db != NULL)
    {
        fread(&f, sizeof (Commento), 1, db);
        fclose(db);
    }

    if (f.Setted == 1)
        if (f.IDCommento[0] == '-' && f.IDCommento[1] == '1')
            f.Setted = 0;

    return f;
}
