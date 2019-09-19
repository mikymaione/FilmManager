/*
 * File:   Utente_Login.h
 * Author: michele
 *
 * Created on 15 ottobre 2014, 9.40
 */

#ifndef _UTENTE_LOGIN_H
#define	_UTENTE_LOGIN_H

#include "ui_Utente_Login.h"

class Utente_Login : public QDialog
{
    Q_OBJECT

public:
    Ui::Utente_Login widget;
    Utente_Login();

public slots:
    void bNuovoUtenteClicked();

};

#endif	/* _UTENTE_LOGIN_H */
