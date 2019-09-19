#ifndef IOFILM_H
#define IOFILM_H

#include "../Constanti.h"
#include "../DB/Film.h"

int Film_Salva(Film f);
int Film_RicercaTutti(Film films[LMAXArray]);
Film Film_ByID(const char id[LID]);

#endif