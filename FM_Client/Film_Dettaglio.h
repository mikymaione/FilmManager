/*
 * File:   Film_Dettaglio.h
 * Author: michele
 *
 * Created on 3 settembre 2014, 18.32
 */

#ifndef _FILM_DETTAGLIO_H
#define	_FILM_DETTAGLIO_H

#include "ui_Film_Dettaglio.h"

class Film_Dettaglio : public QDialog
{
    Q_OBJECT

public:
    Ui::Film_Dettaglio widget;
    Film_Dettaglio();

};

#endif	/* _FILM_DETTAGLIO_H */
