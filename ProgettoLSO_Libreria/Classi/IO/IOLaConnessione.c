#include "IOLaConnessione.h"
#include <stdio.h>

int LaConnessione_Salva(LaConnessione f)
{
    f.Setted = 1;

    FILE * db = fopen(PathDB(Classe_LaConnessione, "Connessione"), "wb");

    if (db == NULL)
        return 0;

    fwrite(&f, sizeof (LaConnessione), 1, db);

    fclose(db);

    return 1;
}

LaConnessione LaConnessione_Carica()
{
    LaConnessione f = LaConnessione_Null();
    FILE * db = fopen(PathDB(Classe_LaConnessione, "Connessione"), "rb");

    if (db != NULL)
    {
        fread(&f, sizeof (LaConnessione), 1, db);
        fclose(db);
    }

    f.IDConnessione = -1; //reset

    return f;
}