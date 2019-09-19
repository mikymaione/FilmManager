#include "../Constanti.h"
#include "TCPStrutture.h"

char * TCP_ConnettiAlServer(const int portno, const char * host, int * IDConnessione);
void TCP_DisconnettiDalServer(const int IDConnessione);