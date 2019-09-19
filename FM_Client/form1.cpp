/*
 * File:   form1.cpp
 * Author: michele
 *
 * Created on 3 settembre 2014, 18.27
 */
#include "form1.h"
#include "Film_Ricerca.h"
#include "Utente_Login.h"
#include "Connessione.h"
#include "ConversionFN.h"
#include "GlobalVar.h"

extern "C"
{
#include "FN/Util.h"
#include "DB/LaConnessione.h"
#include "IO/IOLaConnessione.h"
#include "NET/TCPClient.h"
#include "NET/CLI/TCPUtente.h"
#include "DB/Utente.h"
#include "Constanti.h"
}

bool form1::Connetti()
{
    MyConnessione = LaConnessione_Carica();

    if (MyConnessione.Setted == 1)
    {
        char Server[LMAXFiles];
        copia(MyConnessione.Server, Server, LMAXFiles);

        char * resu = TCP_ConnettiAlServer(MyConnessione.Porta, Server, &MyConnessione.IDConnessione);
        widget.eConnessione->setText(QString(resu));

        return (MyConnessione.IDConnessione > 0);
    }

    return false;
}

bool form1::Login()
{
    if (MyConnessione.Setted == 1 && MyConnessione.IDConnessione > 0)
    {
        Utente_Login * l1 = new Utente_Login();

        if (l1->exec() == 1)
        {
            char Nickname[LUser];
            char Psw[LNome];

            ToC(l1->widget.eUtente->text(), Nickname, LUser);
            ToC(l1->widget.ePsw->text(), Psw, LNome);

            Utente u = TCP_Utente_ByLogin(MyConnessione.IDConnessione, Nickname, Psw);

            if (u.Setted == 1)
                widget.eUtente->setText(QString(Nickname));
            else
                widget.eConnessione->setText(QString("Credenziali non valide!"));
        }
    }
    else
    {
        widget.eConnessione->setText(QString("Non sei connesso al server!"));
    }
}

void form1::closeEvent(QCloseEvent * event)
{
    TCP_DisconnettiDalServer(MyConnessione.IDConnessione);
}

form1::form1()
{
    widget.setupUi(this);
}

void form1::FilmClicked()
{
    Film_Ricerca * l1 = new Film_Ricerca();
    l1->exec();
}

void form1::LoginClicked()
{
    Login();
}

void form1::ConnessioneClicked()
{
    Connessione * d1 = new Connessione();
    char Server[LMAXFiles];

    copia(MyConnessione.Server, Server, LMAXFiles);

    d1->widget.eServer->setText(QString(Server));
    d1->widget.ePorta->setValue(MyConnessione.Porta);

    if (d1->exec() == 1)
    {
        LaConnessione f = LaConnessione_Null();

        ToC(d1->widget.eServer->text(), f.Server, LMAXFiles);
        f.Porta = d1->widget.ePorta->value();

        LaConnessione_Salva(f);

        Connetti();
    }
}

void form1::ConnettiClicked()
{
    Connetti();
}