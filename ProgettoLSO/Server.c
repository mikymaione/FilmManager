/*
 * File:   Server.c
 * Author: michele
 *
 * Created on 28 giugno 2014, 12.24
 * Programma Server
 */

#include <stdio.h>
#include "NET/TCPServer.h"

int errore_porta()
{
    printf("Passare la porta del server come argomento [tra 49152 e 65535]\n");

    return -1;
}

int main(int argc, char * argv[])
{
    printf("FM_Server - Maione Miky\n");

    int porta = 50000; //default

    if (argc >= 2)
        porta = atoi(argv[1]);

    if (porta >= 49152 && porta <= 65535)
    {
        int IDConnessioneInAscolto = -1;
        printf("Creazione server su porta %i\n", porta);
        printf("%s\n", TCP_Crea(porta, &IDConnessioneInAscolto));

        if (IDConnessioneInAscolto >= 0)
        {
            printf("Server connesso! ID: %i\n", IDConnessioneInAscolto);
            printf("Server in ascolto su porta %i\n", porta);
            printf("%s\n", TCP_Ascolta(IDConnessioneInAscolto));
        }
    }
    else
    {
        return errore_porta();
    }

    return 1;
}