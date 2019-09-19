/*
 * File:   Film_Ricerca.cpp
 * Author: michele
 *
 * Created on 3 settembre 2014, 19.42
 */

#define NCol 6

#include "Film_Ricerca.h"
#include "Film_Dettaglio.h"
#include "Commenti_Ricerca.h"
#include "TableMacro.h"
#include "ConversionFN.h"
#include "GlobalVar.h"

extern "C"
{
#include "DB/Commento.h"
#include "DB/Film.h"
#include "NET/CLI/TCPCommento.h"
#include "NET/CLI/TCPFilm.h"
#include "Constanti.h"
}

void Film_Ricerca::Cerca()
{
    Film films[LMAXArray];
    QString NomiColonne[] = {QString("ID"), QString("Titolo"), QString("Autore"), QString("Anno"), QString("Valutazione"), QString("Commenti")};
    int r = TCP_Film_RicercaTutti(MyConnessione.IDConnessione, films);
    QStandardItemModel * model = NewModel(NCol, r, NomiColonne);

    for (int j = 0; j < r; j++)
        if (films[j].Setted > 0)
        {
            char * IDFilm = (char *) calloc(LID, sizeof (char));
            char Titolo[LDescrizione];
            char Autore[LNome];

            copia(films[j].Titolo, Titolo, LDescrizione);
            copia(films[j].Autore, Autore, LNome);
            copia(films[j].IDFilm, IDFilm, LID);

            QString Riga[] = {
                QString(IDFilm),
                QString(Titolo),
                QString(Autore),
                QString::number(films[j].Data, 10),
                QString::number(0, 10),
                QString::number(TCP_Commento_Count(MyConnessione.IDConnessione, IDFilm), 10)
            };

            AddRow(model, j, NCol, Riga);
        }

    widget.tabella->setModel(model);
    widget.tabella->resizeColumnsToContents();
}

Film_Ricerca::Film_Ricerca()
{
    widget.setupUi(this);
    Cerca();
}

void Film_Ricerca::Modifica(bool Nuovo)
{
    Film f = Film_Null();
    Film_Dettaglio * d1 = new Film_Dettaglio();

    if (!Nuovo)
    {
        char IDFilm[LID];
        char Titolo[LDescrizione];
        char Autore[LNome];
        char Descrizione[LNote];

        ToC(GetSelectedID(widget.tabella), IDFilm, LID);
        f = TCP_Film_ByID(MyConnessione.IDConnessione, IDFilm);

        if (f.Setted < 1)
            return;

        copia(f.Titolo, Titolo, LDescrizione);
        copia(f.Autore, Autore, LNome);
        copia(f.Descrizione, Descrizione, LNote);

        d1->widget.eAnno->setValue(f.Data);
        d1->widget.eAutore->setText(QString(Autore));
        d1->widget.eTitolo->setText(QString(Titolo));
        d1->widget.eDescrizione->setPlainText(QString(Descrizione));
    }

    if (d1->exec() == 1)
    {
        int Data = d1->widget.eAnno->value();

        if (Nuovo)
        {
            char Titolo[LDescrizione];
            char Autore[LNome];
            char Descrizione[LNote];

            ToC(d1->widget.eAutore->text(), Autore, LNome);
            ToC(d1->widget.eTitolo->text(), Titolo, LDescrizione);
            ToC(d1->widget.eDescrizione->toPlainText(), Descrizione, LNote);

            f = Film_New(Titolo, Autore, Descrizione, Data);
        }
        else
        {
            ToC(d1->widget.eAutore->text(), f.Autore, LNome);
            ToC(d1->widget.eTitolo->text(), f.Titolo, LDescrizione);
            ToC(d1->widget.eDescrizione->toPlainText(), f.Descrizione, LNote);

            f.Data = Data;
        }

        TCP_Film_Salva(MyConnessione.IDConnessione, f);
        Cerca();
    }
}

void Film_Ricerca::bNuovo_Clicked()
{
    Modifica(true);
}

void Film_Ricerca::bModifica_Clicked()
{
    Modifica(false);
}

void Film_Ricerca::bElimina_Clicked()
{

}

void Film_Ricerca::bCommenta_Clicked()
{
    char IDFilm[LID];
    ToC(GetSelectedID(widget.tabella), IDFilm, LID);

    Commenti_Ricerca * d1 = new Commenti_Ricerca(IDFilm);

    d1->SettaTitolo(GetColumnValue(widget.tabella, 1));
    d1->exec();
    Cerca();
}

void Film_Ricerca::bValuta_Clicked()
{

}