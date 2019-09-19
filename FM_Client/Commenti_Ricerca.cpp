/*
 * File:   Commenti_Ricerca.cpp
 * Author: michele
 *
 * Created on 5 ottobre 2014, 18.40
 */

#define NCol 4

#include "Commenti_Dettaglio.h"
#include "Commenti_Ricerca.h"
#include "TableMacro.h"
#include "ConversionFN.h"
#include "GlobalVar.h"

extern "C"
{
#include "NET/CLI/TCPCommento.h"
#include "DB/Commento.h"
#include "FN/Util.h"
#include "Constanti.h"
}

char IDFilm[LID];

void Commenti_Ricerca::SettaTitolo(const QString titolo)
{
    this->setWindowTitle(QString("Commenti - ").append(titolo));
}

void Commenti_Ricerca::Cerca()
{
    Commento records[LMAXArray];
    QString NomiColonne[] = {QString("ID"), QString("Autore"), QString("Data"), QString("Testo")};
    int r = TCP_Commento_RicercaTutti(MyConnessione.IDConnessione, IDFilm, records);
    QStandardItemModel * model = NewModel(NCol, r, NomiColonne);

    for (int j = 0; j < r; j++)
        if (records[j].Setted > 0)
        {
            char * IDCommento = (char *) calloc(LID, sizeof (char));
            char Testo[LNote];
            char AUDIT_INS_DATA[LData];
            char AUDIT_INS_DATA_Formatted[LDataFormatted];
            char AUDIT_INS_USER[LUser];

            copia(records[j].IDCommento, IDCommento, LID);
            copia(records[j].Testo, Testo, LNote);
            copia(records[j].AUDIT_INS_DATA, AUDIT_INS_DATA, LData);
            copia(records[j].AUDIT_INS_USER, AUDIT_INS_USER, LUser);

            FormattaData(AUDIT_INS_DATA, AUDIT_INS_DATA_Formatted);

            QString Riga[] = {QString(IDCommento), QString(AUDIT_INS_USER), QString(AUDIT_INS_DATA_Formatted).left(LDataFormatted), QString(Testo)};
            AddRow(model, j, NCol, Riga);
        }

    widget.tabella->setModel(model);
    widget.tabella->resizeColumnsToContents();
}

Commenti_Ricerca::Commenti_Ricerca(char IDFilm_[LID])
{
    widget.setupUi(this);

    copia(IDFilm_, IDFilm, LID);
    Cerca();
}

void Commenti_Ricerca::Modifica(bool Nuovo)
{
    Commento f = Commento_Null();
    Commenti_Dettaglio * d1 = new Commenti_Dettaglio();

    if (!Nuovo)
    {
        char IDCommento[LID];
        char Testo[LNote];

        ToC(GetSelectedID(widget.tabella), IDCommento, LID);

        f = TCP_Commento_ByID(MyConnessione.IDConnessione, IDFilm, IDCommento);

        if (f.Setted < 1)
            return;

        copia(f.Testo, Testo, LNote);

        d1->widget.eTesto->setPlainText(QString(Testo));
    }

    if (d1->exec() == 1)
    {
        if (Nuovo)
        {
            char Testo[LNote];

            ToC(d1->widget.eTesto->toPlainText(), Testo, LNote);

            f = Commento_New(IDFilm, Testo);
        }
        else
        {
            ToC(d1->widget.eTesto->toPlainText(), f.Testo, LNote);
        }

        copia(IDFilm, f.IDFilm, LID);

        TCP_Commento_Salva(MyConnessione.IDConnessione, f);
        Cerca();
    }
}

void Commenti_Ricerca::bNuovo_Clicked()
{
    Modifica(true);
}

void Commenti_Ricerca::bModifica_Clicked()
{
    Modifica(false);
}

void Commenti_Ricerca::bElimina_Clicked()
{

}