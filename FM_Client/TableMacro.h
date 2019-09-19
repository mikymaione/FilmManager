#include <QStandardItemModel>
#include <QTableView>

QStandardItemModel * NewModel(int Colonne, int Righe, QString NomiColonne[]);
void AddRow(QStandardItemModel * model, int RigaAttuale, int Colonne, QString Riga[]);
int GetSelectedRowIndex(QTableView * tabella);
QString GetColumnValue(QTableView * tabella, const int indice_colonna);
QString GetSelectedID(QTableView * tabella);