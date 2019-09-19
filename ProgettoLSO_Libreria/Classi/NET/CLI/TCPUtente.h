/*
 * File:   TCPUtente.h
 * Author: michele
 *
 * Created on 15 ottobre 2014, 10.24
 */

#ifndef TCPUTENTE_H
#define	TCPUTENTE_H

#include "../../Constanti.h"
#include "../../DB/Utente.h"

int TCP_Utente_Salva(const int IDConnessione, Utente f);
Utente TCP_Utente_ByID(const int IDConnessione, const char id[LID]);
Utente TCP_Utente_ByLogin(const int IDConnessione, const char Nickname[LUser], const char Psw[LNome]);
int TCP_Utente_RicercaTutti(const int IDConnessione, Utente elementi[LMAXArray]);

#endif	/* TCPUTENTE_H */

