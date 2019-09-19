/*
 * File:   Utente_Login.cpp
 * Author: michele
 *
 * Created on 15 ottobre 2014, 9.40
 */

#include <stdio.h>
#include "Utente_Login.h"
#include "Utente_Dettaglio.h"
#include "ConversionFN.h"
#include "GlobalVar.h"

extern "C"
{
#include "NET/CLI/TCPUtente.h"
#include "DB/Utente.h"
#include "Constanti.h"
}

Utente_Login::Utente_Login()
{
    widget.setupUi(this);
}

void Utente_Login::bNuovoUtenteClicked()
{
    Utente_Dettaglio * d1 = new Utente_Dettaglio();

    if (d1->exec() == 1)
    {
        char Nickname[LUser];
        char Psw[LNome];

        char Nome[LNome];
        char Cognome[LNome];

        char Indirizzo[LNote];
        char DataNascita[LDataSmall]; // = (char *) calloc(LDataSmall, sizeof (char));

        ToC(d1->widget.eNickName->text(), Nickname, LUser);
        ToC(d1->widget.ePsw->text(), Psw, LNome);
        ToC(d1->widget.eNome->text(), Nome, LNome);
        ToC(d1->widget.eCognome->text(), Cognome, LNome);
        ToC(d1->widget.eIndirizzo->text(), Indirizzo, LNote);

        //QDate n = d1->widget.eDataNascita->date();
        //sprintf(DataNascita, "%i%02i%02i", n.year(), n.month(), n.day());

        Utente f = Utente_New(Nickname, Nome, Cognome, Psw, Indirizzo, DataNascita);
        TCP_Utente_Salva(MyConnessione.IDConnessione, f);
    }
}