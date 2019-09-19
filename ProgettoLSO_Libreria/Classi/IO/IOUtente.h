/*
 * File:   IOUtente.h
 * Author: michele
 *
 * Created on 15 ottobre 2014, 10.11
 */

#ifndef IOUTENTE_H
#define	IOUTENTE_H


#include "../Constanti.h"
#include "../DB/Utente.h"

int Utente_Salva(Utente f);
int Utente_RicercaTutti(Utente elementi[LMAXArray]);
Utente Utente_ByID(const char id[LID]);
Utente Utente_ByLogin(const char Nickname[LUser], const char Psw[LNome]);

#endif	/* IOUTENTE_H */

