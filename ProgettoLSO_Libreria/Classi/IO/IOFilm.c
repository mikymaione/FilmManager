#include "IOFilm.h"
#include <stdio.h>

int Film_Inserisci(Film f)
{
    f.Setted = 1;
    GUID(f.IDFilm);
    OrarioCorrente(f.AUDIT_UPD_DATA);
    OrarioCorrente(f.AUDIT_INS_DATA);
    UtenteConnesso(f.AUDIT_INS_USER);
    UtenteConnesso(f.AUDIT_UPD_USER);

    FILE * db = fopen(PathDB(Classe_Film, f.IDFilm), "wb");

    if (db == NULL)
        return 0;

    fwrite(&f, sizeof (Film), 1, db);

    fclose(db);

    return 1;
}

int Film_Aggiorna(Film f)
{
    f.Setted = 1;
    OrarioCorrente(f.AUDIT_UPD_DATA);
    UtenteConnesso(f.AUDIT_UPD_USER);

    FILE * db = fopen(PathDB(Classe_Film, f.IDFilm), "wb");

    if (db == NULL)
        return 0;

    fwrite(&f, sizeof (Film), 1, db);

    fclose(db);

    return 1;
}

int Film_Salva(Film f)
{
    if (f.IDFilm[0] == '-' && f.IDFilm[1] == '1')
        return Film_Inserisci(f);
    else
        return Film_Aggiorna(f);
}

int Film_RicercaTutti(Film films[LMAXArray])
{
    int x, y, z, r;
    char ids[LMAXFiles][LMAXArray];

    r = GetFiles(Classe_Film, ids);
    z = -1;

    for (y = 0; y < r; y++)
    {
        char j[LMAXFiles];

        for (x = 0; x < LMAXFiles; x++)
            j[x] = ids[x][y];

        Film f = Film_ByID(j);

        if (f.Setted > 0)
            films[z += 1] = f;
    }

    return z + 1;
}

Film Film_ByID(const char id[LID])
{
    Film f = Film_Null();
    FILE * db = fopen(PathDB(Classe_Film, id), "rb");

    if (db != NULL)
    {
        fread(&f, sizeof (Film), 1, db);
        fclose(db);
    }

    if (f.Setted == 1)
        if (f.IDFilm[0] == '-' && f.IDFilm[1] == '1')
            f.Setted = 0;

    return f;
}
