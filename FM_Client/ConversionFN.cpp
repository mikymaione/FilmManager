#include "ConversionFN.h"

void ToC(QString da, char a[], int lunghezza)
{
    for (int i = 0; i < lunghezza; i++)
        a[i] = da[i].toLatin1();
}

void ToS(char da[], QString a, int lunghezza)
{
    for (int i = 0; i < lunghezza; i++)
        a[i] = da[i];
}

void copia(char da[], char * a, int len)
{
    int i;
    for (i = 0; i < len; i++)
        a[i] = da[i];
}