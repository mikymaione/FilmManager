#include "Film.h"
#include "../FN/GB.h"
#include "../Constanti.h"

Film Film_New(const char Titolo[LDescrizione], const char Autore[LNome], const char Descrizione[LNote], const int Data)
{
    Film f = {
        .Setted = 0,
        .IDFilm = "-1",
        .Data = Data
    };

    OrarioCorrente(f.AUDIT_UPD_DATA);
    OrarioCorrente(f.AUDIT_INS_DATA);
    UtenteConnesso(f.AUDIT_INS_USER);
    UtenteConnesso(f.AUDIT_UPD_USER);

    cp(Titolo, f.Titolo, LDescrizione);
    cp(Autore, f.Autore, LNome);
    cp(Descrizione, f.Descrizione, LNote);

    return f;
}

Film Film_Null()
{
    Film f = {
        .Setted = -1,
        .IDFilm = "-1",
        .Titolo = "",
        .Autore = "",
        .Descrizione = "",
        .Data = 1900,
        .AUDIT_UPD_DATA = "",
        .AUDIT_INS_DATA = "",
        .AUDIT_INS_USER = "",
        .AUDIT_UPD_USER = ""
    };

    return f;
}