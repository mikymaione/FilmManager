/*
 * File:   SERCommento.h
 * Author: michele
 *
 * Created on 11 ottobre 2014, 10.40
 */

#ifndef SERCOMMENTO_H
#define	SERCOMMENTO_H

#include "../../Constanti.h"
#include "../../DB/Commento.h"

int SER_Commento_Salva(const int IDConnessione);
int SER_Commento_Count(const int IDConnessione, const char IDFilm[LID]);
int SER_Commento_RicercaTutti(const int IDConnessione, const char IDFilm[LID]);
int SER_Commento_ByID(const int IDConnessione, const char FilmID[LID], const char ID[LID]);

#endif	/* SERCOMMENTO_H */

