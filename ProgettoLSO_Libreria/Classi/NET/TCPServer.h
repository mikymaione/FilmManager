/*
 * File:   TCPServer.c
 * Author: michele
 *
 * Created on 09 ottobre 2014, 16.24
 */
#include "../Constanti.h"
#include "TCPStrutture.h"

char * TCP_Ascolta(const int IDConnessioneInAscolto);
char * TCP_Crea(const int portno, int * IDConnessioneInAscolto_);