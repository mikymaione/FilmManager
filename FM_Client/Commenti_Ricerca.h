/*
 * File:   Commenti_Ricerca.h
 * Author: michele
 *
 * Created on 5 ottobre 2014, 18.40
 */

#ifndef _COMMENTI_RICERCA_H
#define	_COMMENTI_RICERCA_H

#include "ui_Commenti_Ricerca.h"

class Commenti_Ricerca : public QDialog
{
    Q_OBJECT

public:
    Commenti_Ricerca(char IDFilm_[]);
    void SettaTitolo(const QString titolo);

private:
    Ui::Commenti_Ricerca widget;
    void Cerca();
    void Modifica(bool Nuovo);

public slots:
    void bNuovo_Clicked();
    void bModifica_Clicked();
    void bElimina_Clicked();

};

#endif	/* _COMMENTI_RICERCA_H */
