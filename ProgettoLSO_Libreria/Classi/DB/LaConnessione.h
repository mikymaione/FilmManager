/*
 * File:   LaConnessione.h
 * Author: michele
 *
 * Created on 11 ottobre 2014, 11.43
 */

#ifndef LACONNESSIONE_H
#define	LACONNESSIONE_H

#include "../Constanti.h"

typedef struct laConnessione
{
    int Setted;
    int Porta;
    int IDConnessione;
    char Server[LMAXFiles];
} LaConnessione;


LaConnessione LaConnessione_New(const char Server[LMAXFiles], const int Porta);
LaConnessione LaConnessione_Null();

#endif	/* LACONNESSIONE_H */

