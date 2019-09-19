/*
 * File:   Film_Ricerca.h
 * Author: michele
 *
 * Created on 3 settembre 2014, 19.42
 */

#ifndef _FILM_RICERCA_H
#define	_FILM_RICERCA_H

#include "ui_Film_Ricerca.h"

class Film_Ricerca : public QDialog
{
    Q_OBJECT
public:
    Film_Ricerca();

private:
    Ui::Film_Ricerca widget;
    void Cerca();
    void Modifica(bool Nuovo);

public slots:
    void bNuovo_Clicked();
    void bModifica_Clicked();
    void bElimina_Clicked();
    void bCommenta_Clicked();
    void bValuta_Clicked();

};

#endif	/* _FILM_RICERCA_H */
