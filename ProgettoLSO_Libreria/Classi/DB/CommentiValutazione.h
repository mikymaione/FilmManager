#ifndef COMMENTIVALUTAZIONE_H
#define COMMENTIVALUTAZIONE_H

#include "../Constanti.h"

typedef struct commentiValutazione
{
    int Setted;
    char IDCommentiValutazione[LID];
    char IDCommento[LID];
    char IDUtente[LID];
    int voto;

    //Audit
    char AUDIT_INS_USER[LUser]; /* Utente che ha inserito il record.	*/
    char AUDIT_UPD_USER[LUser];
    char AUDIT_INS_DATA[LData]; //yyyymmddhhmmss
    char AUDIT_UPD_DATA[LData]; //yyyymmddhhmmss
} CommentiValutazione;

#endif