#ifndef TCPFILM_H
#define TCPFILM_H

#include "../../Constanti.h"
#include "../../DB/Film.h"

int TCP_Film_Salva(const int IDConnessione, Film f);
Film TCP_Film_ByID(const int IDConnessione, const char id[LID]);
int TCP_Film_RicercaTutti(const int IDConnessione, Film films[LMAXArray]);

#endif