#ifndef SERFILM_H
#define SERFILM_H

#include "../../Constanti.h"
#include "../../DB/Film.h"

int SEF_Film_Salva(const int IDConnessione);
int SER_Film_ByID(const int IDConnessione, const char id[LID]);
int SER_Film_RicercaTutti(const int IDConnessione);

#endif