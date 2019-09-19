/*
 * File:   IOCommento.h
 * Author: michele
 *
 * Created on 11 ottobre 2014, 10.39
 */

#ifndef IOCOMMENTO_H
#define	IOCOMMENTO_H

#include "../Constanti.h"
#include "../DB/Commento.h"

int Commento_Salva(Commento f);
int Commento_Count(const char IDFilm[LID]);
int Commento_RicercaTutti(const char IDFilm[LID], Commento commenti[LMAXArray]);
Commento Commento_ByID(const char IDFilm[LID], const char id[LID]);

#endif	/* IOCOMMENTO_H */

