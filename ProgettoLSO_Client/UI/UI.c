#include <stdio.h>
#include "DB/Film.h"

char StampaMenu()
{
    printf("Progetto LSO - Sistema votazione film\n");
    printf("Menu:\n");
    printf(" 0- Esci\n");
    printf(" 1- Lista film\n");
    printf(" 2- Inserisci film\n");

    printf("\nCosa vuoi fare? ");

    char scelta = getchar();

    printf("\n");

    if (scelta == '0')
    {
        printf("Arrivederci!\n");
    }
    else if (scelta == '1')
    {
        printf("Lista film:\n");
        Film_StampaTutti(0);
    }
    else if (scelta == '2')
    {
        printf("Nuovo film:\n");

        Film f = Film_New(
                "The Matrix",
                "Lana e Andy Wachowski",
                "Il programmatore di computer Thomas Anderson vive segretamente come hacker, sotto lo pseudonimo di 'Neo'. Un giorno gli compaiono sul monitor alcune criptiche frasi riguardo a un indefinito 'Matrix'. Desideroso di scoprire cosa sia, dopo aver avuto un incontro con alcuni agenti, viene condotto dal misterioso Morpheus, il quale gli offre la possibilità di conoscere la verità riguardo Matrix. Neo accetta. Dopo aver ingerito una pillola rossa, si sveglia bruscamente nudo in un alloggiamento riempito di liquido, con il corpo collegato a tubicini e cavi elettrici, i quali portano a una torre dove sono posti altri 'baccelli' identici a quello in cui è lui.",
                "1999"
                );

        printf("%s", "Salvataggio in corso ... ");

        int r = Film_Salva(f);

        printf("%i", r);
    }

    return scelta;
}