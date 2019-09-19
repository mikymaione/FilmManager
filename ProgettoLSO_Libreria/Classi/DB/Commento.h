#ifndef COMMENTO_H
#define COMMENTO_H

#include "../Constanti.h"

typedef struct commento
{
    int Setted;
    char IDCommento[LID];
    char IDFilm[LID];

    char Testo[LNote];

    //Audit
    char AUDIT_INS_USER[LUser]; /* Utente che ha inserito il record.	*/
    char AUDIT_UPD_USER[LUser];
    char AUDIT_INS_DATA[LData]; //yyyymmddhhmmss
    char AUDIT_UPD_DATA[LData]; //yyyymmddhhmmss
} Commento;

Commento Commento_New(char IDFilm[LID], char Testo[LNote]);
Commento Commento_Null();

#endif