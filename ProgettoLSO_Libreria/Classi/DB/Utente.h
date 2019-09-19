#ifndef UTENTE_H
#define UTENTE_H

#include "../Constanti.h"

typedef struct utente
{
    int Setted;
    char IDUtente[LID];

    char Nickname[LUser];
    char Psw[LNome];

    char Nome[LNome];
    char Cognome[LNome];

    char Indirizzo[LNote];
    char DataNascita[LDataSmall]; //yyyymmdd

    //Audit
    char AUDIT_INS_USER[LUser]; /* Utente che ha inserito il record.	*/
    char AUDIT_UPD_USER[LUser];
    char AUDIT_INS_DATA[LData]; //yyyymmddhhmmss
    char AUDIT_UPD_DATA[LData]; //yyyymmddhhmmss
} Utente;

Utente Utente_Null();
Utente Utente_New(
        char Nickname[LUser],
        char Nome[LNome],
        char Cognome[LNome],
        char Psw[LNome],
        char Indirizzo[LNote],
        char DataNascita[LDataSmall]
        );

#endif