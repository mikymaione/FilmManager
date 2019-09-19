/*
 * File:   SERUtente.h
 * Author: michele
 *
 * Created on 15 ottobre 2014, 10.24
 */

#ifndef SERUTENTE_H
#define	SERUTENTE_H

#include "../../Constanti.h"
#include "../../DB/Utente.h"

int SEF_Utente_Salva(const int IDConnessione);
int SER_Utente_ByID(const int IDConnessione, const char id[LID]);
int SER_Utente_ByLogin(const int IDConnessione, const char Nickname[LUser], const char Psw[LNome]);
int SER_Utente_RicercaTutti(const int IDConnessione);

#endif	/* SERUTENTE_H */

