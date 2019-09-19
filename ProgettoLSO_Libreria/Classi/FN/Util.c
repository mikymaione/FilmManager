#include <time.h>
#include <stdio.h>
#include "Util.h"

void UtenteConnesso(char u[LUser])
{
    char j[] = "Maione Michele";

    cp(j, u, LUser);
}

void FormattaData(char data_14[LData], char out_testo_19[LDataFormatted])
{
    //char data[LData];

    //in
    //0123 45 67 89 01 23
    //yyyy MM dd hh mm ss

    //out
    //0123456789012345678
    //dd/MM/yyyy hh:mm:ss

    int x = -1;
    out_testo_19[x += 1] = data_14[6]; // d   0
    out_testo_19[x += 1] = data_14[7]; // d   1
    out_testo_19[x += 1] = '/'; // separatore 2
    out_testo_19[x += 1] = data_14[4]; // M   3
    out_testo_19[x += 1] = data_14[5]; // M   4
    out_testo_19[x += 1] = '/'; // separatore 5
    out_testo_19[x += 1] = data_14[0]; // Y   6
    out_testo_19[x += 1] = data_14[1]; // Y   7
    out_testo_19[x += 1] = data_14[2]; // Y   8
    out_testo_19[x += 1] = data_14[3]; // Y   9
    out_testo_19[x += 1] = ' '; // separatore10
    out_testo_19[x += 1] = data_14[8]; // h  11
    out_testo_19[x += 1] = data_14[9]; // h  12
    out_testo_19[x += 1] = ':'; // separatore13
    out_testo_19[x += 1] = data_14[10]; // m 14
    out_testo_19[x += 1] = data_14[11]; // m 15
    out_testo_19[x += 1] = ':'; // separatore16
    out_testo_19[x += 1] = data_14[12]; // s 17
    out_testo_19[x += 1] = data_14[13]; // s 18
}

void GUID(char c[LID])
{
    //4cfadbd2-2161-4356-bfef-b4bc33024979
    FILE * f = fopen("/proc/sys/kernel/random/uuid", "r");

    if (f != NULL)
    {
        int x = 0;

        while (!feof(f))
        {
            c[x] = getc(f);
            x++;

            if (x > LID - 2)
                break;
        }

        fclose(f);
    }

    return c;
}

void OrarioCorrente(char o[LData])
{
    int i;
    char * r = calloc(LData, sizeof (char));
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    sprintf(r, "%i%02i%02i%02i%02i%02i", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

    for (i = 0; i < LData; i++)
        o[i] = r[i];
}