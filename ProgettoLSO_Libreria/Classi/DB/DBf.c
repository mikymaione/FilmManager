#include <linux/limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include "../Constanti.h"

char * PathDBFolder2(int classe, const char id1[LID])
{
    char * dire = malloc(PATH_MAX);
    char * coma = malloc(PATH_MAX);
    char * clZ = malloc(PATH_MAX);

    if (classe == Classe_LaConnessione)
        sprintf(clZ, "%s", "LaConnessione");
    else if (classe == Classe_Film)
        sprintf(clZ, "%s", "Film");
    else if (classe == Classe_Commento)
        sprintf(clZ, "%s%.*s%s", "Film/", LID, id1, "/Commento");
    else if (classe == Classe_FilmValutazione)
        sprintf(clZ, "%s", "FilmValutazione");
    else if (classe == Classe_Utente)
        sprintf(clZ, "%s", "Utente");
    else if (classe == Classe_CommentiValutazione)
        sprintf(clZ, "%s", "CommentiValutazione");
    else
        sprintf(clZ, "%s", "NULL");

    sprintf(dire, "%s%s%s", PATHDB, clZ, "/");
    sprintf(coma, "%s%s%s", "mkdir ", dire, " -p");

    system(coma);

    return dire;
}

char * PathDBFolder(int classe)
{
    return PathDBFolder2(classe, "");
}

char * PathDB2(int classe, const char id[LID], const char id1[LID])
{
    int i;
    char * file = malloc(PATH_MAX);
    char * dire = PathDBFolder2(classe, id1);
    char id2[LID];

    for (i = 0; i < LID; i++)
        id2[i] = id[i];

    sprintf(file, "%s%.*s%s", dire, LID, id2, ".db");

    return file;
}

char * PathDB(int classe, const char id[LID])
{
    return PathDB2(classe, id, "");
}

char * RemoveExt(char * mystr)
{
    char * retstr;

    if (mystr == NULL)
        return NULL;

    if ((retstr = malloc(strlen(mystr) + 1)) == NULL)
        return NULL;

    strcpy(retstr, mystr);
    char * lastdot = strrchr(retstr, '.');

    if (lastdot != NULL)
        * lastdot = '\0';

    return retstr;
}

int GetFilesCount2(int classe, const char id1[LID])
{
    int y;
    DIR * d = opendir(PathDBFolder2(classe, id1));

    if (d)
    {
        char * k;
        struct dirent * dir;
        y = -1;

        while ((dir = readdir(d)) != NULL)
            if (dir->d_type == DT_REG)
                if (dir->d_name[0] != '.')
                    y++;

        closedir(d);
    }

    return (y + 1);
}

int GetFiles2(int classe, char files[LMAXFiles][LMAXArray], const char id1[LID])
{
    int x, y;
    DIR * d = opendir(PathDBFolder2(classe, id1));

    for (x = 0; x < LMAXFiles; x++)
        for (y = 0; y < LMAXArray; y++)
            files[x][y] = -1;

    if (d)
    {
        char * k;
        struct dirent * dir;
        y = -1;

        while ((dir = readdir(d)) != NULL)
            if (dir->d_type == DT_REG)
                if (dir->d_name[0] != '.')
                {
                    y++;
                    k = RemoveExt(dir->d_name);

                    for (x = 0; x < LMAXFiles; x++)
                        files[x][y] = k[x];
                }

        closedir(d);
    }

    return (y + 1);
}

int GetFiles(int classe, char files[LMAXFiles][LMAXArray])
{
    return GetFiles2(classe, files, "");
}