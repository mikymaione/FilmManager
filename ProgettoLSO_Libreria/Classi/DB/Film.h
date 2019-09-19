#ifndef FILM_H
#define FILM_H

#include "../Constanti.h"

typedef struct film
{
    int Setted;
    char IDFilm[LID];

    char Titolo[LDescrizione];
    char Autore[LNome];
    char Descrizione[LNote];
    int Data;

    //Audit
    char AUDIT_INS_USER[LUser]; /* Utente che ha inserito il record.	*/
    char AUDIT_UPD_USER[LUser];
    char AUDIT_INS_DATA[LData]; //yyyymmddhhmmss
    char AUDIT_UPD_DATA[LData]; //yyyymmddhhmmss
} Film;

Film Film_New(const char Titolo[LDescrizione], const char Autore[LNome], const char Descrizione[LNote], const int Data);
Film Film_Null();

#endif