/*
 * File:   TCPCommento.h
 * Author: michele
 *
 * Created on 11 ottobre 2014, 10.39
 */

#ifndef TCPCOMMENTO_H
#define	TCPCOMMENTO_H

#include "../../Constanti.h"
#include "../../DB/Commento.h"

int TCP_Commento_Salva(const int IDConnessione, Commento f);
int TCP_Commento_Count(const int IDConnessione, const char IDFilm[LID]);
int TCP_Commento_RicercaTutti(const int IDConnessione, const char IDFilm[LID], Commento commenti[LMAXArray]);
Commento TCP_Commento_ByID(const int IDConnessione, const char FilmID[LID], const char ID[LID]);

#endif	/* TCPCOMMENTO_H */

