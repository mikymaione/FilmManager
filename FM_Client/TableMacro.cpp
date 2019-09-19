#include "TableMacro.h"

QStandardItemModel * NewModel(int Colonne, int Righe, QString NomiColonne[])
{
    QStandardItemModel * model = new QStandardItemModel(Righe, Colonne, 0);

    for (int y = 0; y < Colonne; y++)
        model->setHorizontalHeaderItem(y, new QStandardItem(NomiColonne[y]));

    return model;
}

void AddRow(QStandardItemModel * model, int RigaAttuale, int Colonne, QString Riga[])
{
    for (int y = 0; y < Colonne; y++)
        model->setItem(RigaAttuale, y, new QStandardItem(Riga[y]));
}

int GetSelectedRowIndex(QTableView * tabella)
{
    return tabella->selectionModel()->currentIndex().row();
}

QString GetColumnValue(QTableView * tabella, const int indice_colonna)
{
    return tabella->model()->data(tabella->model()->index(GetSelectedRowIndex(tabella), indice_colonna), Qt::DisplayRole).toString();
}

QString GetSelectedID(QTableView * tabella)
{
    return GetColumnValue(tabella, 0);
}

