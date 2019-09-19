#include "../Constanti.h"

typedef struct pacchetto
{
    int Comando;

    int valore1;
    int valore2;

    char ID1[LID];
    char ID2[LID];
    char ID3[LID];
} Pacchetto;

Pacchetto Pacchetto_Null();
char * Errore(const char * testo, int errno);