#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "definition_fourmis.h"

void produireNourriture(ChampAgricole *champ)
{
    if (champ->nourritureStockee + champ->productionParJour <= champ->capaciteMax)
    {
        champ->nourritureStockee += champ->productionParJour;
    }

    printf("- Production du champs : %d. Stock actuel du champs : %d. Objectif : %d.\n", champ->productionParJour, champ->nourritureStockee, champ->capaciteMax);
    sleep(1);
}

void recolterNourriture(ChampAgricole *champ, Ressources *ressources)
{
    ressources->stockNourriture += champ->nourritureStockee;
    printf("Recolte %d unite de nourriture du champ. Stock total : %d\n", champ->nourritureStockee, ressources->stockNourriture);
    sleep(1);
    champ->nourritureStockee = 0;
}

void simulation_agricole(ChampAgricole *champs, Ressources *besoin)
{
    printf("\nChamps des ouvrieres :\n");
    sleep(1);
    produireNourriture(champs);

    if (champs->nourritureStockee >= champs->capaciteMax)
    {
        printf("- Il est temps de récolte !!\n");
        sleep(1);
        recolterNourriture(champs, besoin);

        if (champs->nourritureStockee + besoin->stockNourriture == besoin->objectif)
        {
            printf("- Recolte d'urgence pour nourrire tout le monde !\n");
            sleep(1);
            recolterNourriture(champs, besoin);
            printf("- Objectif atteint grace a la recolte : %d unites de nourriture ont ete collectees et stockees pour un objectif de %d !\n", besoin->stockNourriture, besoin->objectif);
            sleep(1);
        }
    }
    else
    {
        printf("- Il n'est pas encore temps de recolter...\n");
    }
}

void simulation_champs_details(ChampAgricole *champs, Fourmiliere *fourmiliere, Ressources *besoin, int temps)
{
    printf("\nChamps des ouvrieres :\n");
    sleep(1);
    creerChamp(champs, fourmiliere);

    for (int i = 0; i < temps; i++)
    {
        printf("**** JOURS %d ****\n", i + 1);
        sleep(1);
        produireNourriture(champs);

        if (champs->nourritureStockee >= champs->capaciteMax)
        {
            printf("- Il est temps de récolte !!\n");
            sleep(1);
            recolterNourriture(champs, besoin);
            printf("Resultat : %d de nourritures produites pour la fourmiliere !!\n", champs->nourritureStockee);
            sleep(1);
        }
        else
        {
            printf("- Il n'est pas encore temps de recolter...\n");
            sleep(1);
        }
    }
}
