#include "Commento.h"
#include "../FN/GB.h"
#include "../Constanti.h"

Commento Commento_New(char IDFilm[LID], char Testo[])
{
    Commento f = {
        .Setted = 0,
        .IDCommento = "-1"
    };

    OrarioCorrente(f.AUDIT_UPD_DATA);
    OrarioCorrente(f.AUDIT_INS_DATA);
    UtenteConnesso(f.AUDIT_INS_USER);
    UtenteConnesso(f.AUDIT_UPD_USER);

    cp(Testo, f.Testo, LNote);
    cp(IDFilm, f.IDFilm, LID);

    return f;
}

Commento Commento_Null()
{
    Commento f = {
        .Setted = -1,
        .IDCommento = "-1",
        .IDFilm = "-1",
        .Testo = "",
        .AUDIT_UPD_DATA = "",
        .AUDIT_INS_DATA = "",
        .AUDIT_INS_USER = "",
        .AUDIT_UPD_USER = ""
    };

    return f;
}