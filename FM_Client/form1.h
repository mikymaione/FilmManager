/*
 * File:   form1.h
 * Author: michele
 *
 * Created on 3 settembre 2014, 18.27
 */

#ifndef _FORM1_H
#define	_FORM1_H

#include "ui_form1.h"

class form1 : public QMainWindow
{
    Q_OBJECT

public:
    form1();

protected:
    void closeEvent(QCloseEvent * event);

private:
    Ui::form1 widget;
    bool Connetti();
    bool Login();

public slots:
    void FilmClicked();
    void ConnessioneClicked();
    void ConnettiClicked();
    void LoginClicked();

};

#endif	/* _FORM1_H */
