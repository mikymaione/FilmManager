/*
 * File:   main.cpp
 * Author: michele
 *
 * Created on 3 settembre 2014, 18.24
 */

#include <QApplication>
#include "form1.h"

int main(int argc, char * argv[])
{
    QApplication app(argc, argv);
    app.setApplicationName("Film Manager - [MAIONE MIKY]");
    app.setOrganizationName("[MAIONE MIKY]");

    form1 * f1 = new form1();
    f1->showMaximized();

    return app.exec();
}
