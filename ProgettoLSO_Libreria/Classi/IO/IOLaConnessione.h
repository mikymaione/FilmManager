/*
 * File:   IOLaConnessione.h
 * Author: michele
 *
 * Created on 11 ottobre 2014, 11.43
 */

#ifndef IOLACONNESSIONE_H
#define	IOLACONNESSIONE_H

#include "../Constanti.h"
#include "../DB/LaConnessione.h"

int LaConnessione_Salva(LaConnessione f);
LaConnessione LaConnessione_Carica();

#endif	/* IOLACONNESSIONE_H */

