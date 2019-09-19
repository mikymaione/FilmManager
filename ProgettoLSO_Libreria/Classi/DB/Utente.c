#include "Utente.h"
#include "../FN/GB.h"
#include "../Constanti.h"

Utente Utente_Null()
{
    Utente f = {
        .Setted = -1,
        .Cognome = "",
        .DataNascita = "",
        .IDUtente = "",
        .Indirizzo = "",
        .Nickname = "",
        .Nome = "",
        .Psw = "",
        .AUDIT_UPD_DATA = "",
        .AUDIT_INS_DATA = "",
        .AUDIT_INS_USER = "",
        .AUDIT_UPD_USER = ""
    };

    return f;
}

Utente Utente_New(
        char Nickname[LUser],
        char Nome[LNome],
        char Cognome[LNome],
        char Psw[LNome],
        char Indirizzo[LNote],
        char DataNascita[LDataSmall]
        )
{
    Utente f = {
        .Setted = 0,
        .Cognome = "",
        .DataNascita = "",
        .IDUtente = "-1",
        .Indirizzo = "",
        .Nickname = "",
        .Nome = "",
        .Psw = "",
        .AUDIT_UPD_DATA = "",
        .AUDIT_INS_DATA = "",
        .AUDIT_INS_USER = "",
        .AUDIT_UPD_USER = ""
    };

    OrarioCorrente(f.AUDIT_UPD_DATA);
    OrarioCorrente(f.AUDIT_INS_DATA);
    UtenteConnesso(f.AUDIT_INS_USER);
    UtenteConnesso(f.AUDIT_UPD_USER);

    cp(Nickname, f.Nickname, LUser);
    cp(Nome, f.Nome, LNome);
    cp(Cognome, f.Cognome, LNome);
    cp(Psw, f.Psw, LNome);
    cp(Indirizzo, f.Indirizzo, LNote);
    cp(DataNascita, f.DataNascita, LDataSmall);

    return f;
}