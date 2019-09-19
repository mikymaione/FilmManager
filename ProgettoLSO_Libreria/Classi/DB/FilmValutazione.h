#ifndef FILMVALUTAZIONE_H
#define FILMVALUTAZIONE_H

#include "../Constanti.h"

typedef struct filmValutazione
{
    int Setted;
    char IDFilmValutazione[LID];
    char IDFilm[LID];
    char IDUtente[LID];
    int voto;

    //Audit
    char AUDIT_INS_USER[LUser]; /* Utente che ha inserito il record.	*/
    char AUDIT_UPD_USER[LUser];
    char AUDIT_INS_DATA[LData]; //yyyymmddhhmmss
    char AUDIT_UPD_DATA[LData]; //yyyymmddhhmmss
} FilmValutazione;

#endif