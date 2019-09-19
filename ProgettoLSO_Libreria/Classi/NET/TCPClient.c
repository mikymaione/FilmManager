#include "TCPClient.h"
#include <string.h>
#include <netinet/in.h>
#include <netdb.h>

void TCP_DisconnettiDalServer(const int IDConnessione)
{
    Pacchetto p = Pacchetto_Null();
    p.Comando = TCP_ComandoEsci;

    send(IDConnessione, &p, sizeof (Pacchetto), 0);
    close(IDConnessione);
}

char * TCP_ConnettiAlServer(const int portno, const char * host, int * IDConnessione)
{
    *IDConnessione = socket(AF_INET, SOCK_STREAM, 0);

    if (*IDConnessione < 0)
        return Errore("TCPClient: Errore apertura socket", *IDConnessione);

    struct hostent * server = gethostbyname(host);

    if (server == NULL)
        return Errore("TCPClient: Errore nessun host trovato", 0);

    struct sockaddr_in indirizzo_server;
    bzero((char *) &indirizzo_server, sizeof (indirizzo_server));
    indirizzo_server.sin_family = AF_INET;

    bcopy((char *) server->h_addr, (char *) &indirizzo_server.sin_addr.s_addr, server->h_length);
    indirizzo_server.sin_port = htons(portno);

    int n = connect(*IDConnessione, (struct sockaddr *) &indirizzo_server, sizeof (indirizzo_server));
    if (n < 0)
    {
        *IDConnessione = -1;
        return Errore("TCPClient: Errore connessione", n);
    }

    return Errore("TCPClient: Connesso a", *IDConnessione);
}