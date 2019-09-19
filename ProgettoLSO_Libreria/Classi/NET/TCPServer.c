/*
 * File:   TCPServer.c
 * Author: michele
 *
 * Created on 09 ottobre 2014, 16.24
 */
#include "TCPServer.h"
#include "../DB/Film.h"
#include "../DB/Commento.h"
#include "SER/SERCommento.h"
#include "SER/SERFilm.h"
#include <string.h>
#include <netinet/in.h>
#include <netdb.h>
#include <signal.h>
#include <stdio.h>
#include <time.h>
#include <linux/limits.h>
#include <stdlib.h>

int IDConnessioneInAscolto_ = -1;
int InEsecuzione = 1;
FILE * FLog; //log condiviso

char * OrarioCorrenteC()
{
    char * r = calloc(LDataFormatted, sizeof (char));
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    //12/12/2014 12:45:22
    sprintf(r, "%02i/%02i/%i %02i:%02i:%02i", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);

    return r;
}

void Chiudi()
{
    close(IDConnessioneInAscolto_);
    fprintf(FLog, "%s: Chiusa %i\n", OrarioCorrenteC(), IDConnessioneInAscolto_);
    InEsecuzione = 0;

    printf("\nTCPServer: Bye!\n");
}

void termination_handler(int sig)
{
    Chiudi();
    exit(sig);
}

int ApriLog()
{
    char * dire = malloc(PATH_MAX);
    char * coma = malloc(PATH_MAX);
    sprintf(dire, "%s%s", PATHDB, "LOG/");
    sprintf(coma, "%s%s%s", "mkdir ", dire, " -p");
    sprintf(dire, "%s%s", dire, "FM_Server.txt");

    system(coma);

    if ((FLog = fopen(dire, "a")) == NULL)
        return 0;
    else
        return 1;
}

char * TCP_Crea(const int portno, int * IDConnessioneInAscolto)
{
    * IDConnessioneInAscolto = socket(AF_INET, SOCK_STREAM, 0);
    if (*IDConnessioneInAscolto < 0)
        return Errore("TCPServer: Errore apertura socket", *IDConnessioneInAscolto);

    struct sockaddr_in serv_addr;
    bzero((char *) &serv_addr, sizeof (serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    int bi = bind(*IDConnessioneInAscolto, (struct sockaddr *) &serv_addr, sizeof (serv_addr));
    if (bi < 0)
        return Errore("TCPServer: Errore creazione porta", bi);

    return "TCPServer: Creato!";
}

char * TCP_Opera(const int IDNuovaConnessione)
{
    int n = 1;
    char * resu;

    while (n > -1)
    {
        Pacchetto pacchet = Pacchetto_Null();
        n = recv(IDNuovaConnessione, &pacchet, sizeof (Pacchetto), 0);

        if (n < 0)
        {
            resu = Errore("TCPServer: Errore lettura socket", n);
            break;
        }

        fprintf(FLog, "%s: Domanda [%i] ricevuta da %i\n", OrarioCorrenteC(), pacchet.Comando, IDNuovaConnessione);

        if (pacchet.Comando == TCP_ComandoEsci)
            n = TCP_ComandoEsci;
        else if (pacchet.Comando == TCP_ComandoNonSettato)
        {
            resu = Errore("TCPServer: Comando non settato", 0);
            break;
        }

        else if (pacchet.Comando == TCP_Richiesta_Film_ByID)
            n = SER_Film_ByID(IDNuovaConnessione, pacchet.ID1);
        else if (pacchet.Comando == TCP_Richiesta_Film_RicercaTutti)
            n = SER_Film_RicercaTutti(IDNuovaConnessione);
        else if (pacchet.Comando == TCP_Richiesta_Film_Salva)
            n = SEF_Film_Salva(IDNuovaConnessione);

        else if (pacchet.Comando == TCP_Richiesta_Commento_ByID)
            n = SER_Commento_ByID(IDNuovaConnessione, pacchet.ID1, pacchet.ID2);
        else if (pacchet.Comando == TCP_Richiesta_Commento_Count)
            n = SER_Commento_Count(IDNuovaConnessione, pacchet.ID1);
        else if (pacchet.Comando == TCP_Richiesta_Commento_RicercaTutti)
            n = SER_Commento_RicercaTutti(IDNuovaConnessione, pacchet.ID1);
        else if (pacchet.Comando == TCP_Richiesta_Commento_Salva)
            n = SER_Commento_Salva(IDNuovaConnessione);

        else if (pacchet.Comando == TCP_Richiesta_Utente_ByLogin)
            n = SER_Utente_ByLogin(IDNuovaConnessione, pacchet.ID1, pacchet.ID2);
        else if (pacchet.Comando == TCP_Richiesta_Utente_ByID)
            n = SER_Utente_ByID(IDNuovaConnessione, pacchet.ID1);
        else if (pacchet.Comando == TCP_Richiesta_Utente_RicercaTutti)
            n = SER_Utente_RicercaTutti(IDNuovaConnessione);
        else if (pacchet.Comando == TCP_Richiesta_Utente_Salva)
            n = SEF_Utente_Salva(IDNuovaConnessione);

        if (n < 0 && n != TCP_ComandoEsci)
        {
            resu = Errore("TCPServer: Errore scrittura socket", n);
            break;
        }
        else if (n == TCP_ComandoEsci)
            fprintf(FLog, "%s: Il client %i si è disconnesso\n", OrarioCorrenteC(), IDNuovaConnessione);

        fprintf(FLog, "%s: Risposta [%i] inviata a %i\n", OrarioCorrenteC(), n, IDNuovaConnessione);

        fflush(FLog);
    }

    return resu;
}

void SettaSignalHandler()
{
    (void) signal(SIGINT, termination_handler);
}

char * TCP_Ascolta(const int IDConnessioneInAscolto)
{
    pid_t miopid = 0;
    struct sockaddr_in cli_addr;
    socklen_t clilen = sizeof (cli_addr);

    if (ApriLog() == 0)
        return Errore("TCPServer: Errore creazione file di log", 0);

    fprintf(FLog, "Avvio...\n");

    IDConnessioneInAscolto_ = IDConnessioneInAscolto;
    SettaSignalHandler();

    listen(IDConnessioneInAscolto, TCP_MAX_CLIENT);

    fprintf(FLog, "%s: In ascolto su %i\n", OrarioCorrenteC(), IDConnessioneInAscolto);
    fflush(FLog);

    while (InEsecuzione == 1)
    {
        int IDNuovaConnessione = accept(IDConnessioneInAscolto, (struct sockaddr *) &cli_addr, &clilen);
        if (IDNuovaConnessione < 0)
            return Errore("TCPServer: Errore apertura socket con client", IDNuovaConnessione);

        fprintf(FLog, "%s: Connesso a %i\n", OrarioCorrenteC(), IDNuovaConnessione);
        fflush(FLog);

        if ((miopid = fork()) == 0) //processo nasce
        {
            close(IDConnessioneInAscolto);

            return TCP_Opera(IDNuovaConnessione); //processo muore
        }
    }

    Chiudi();

    return "\nTCPServer: Bye!";
}