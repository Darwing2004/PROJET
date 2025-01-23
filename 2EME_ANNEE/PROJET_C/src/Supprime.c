#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include "definition_fourmis.h"

void supprimerFourmi(Fourmiliere *fourmiliere)
{

    // On récupere d'abord l'indice de la fourmis dans le tableau des fourmis
    int indexFourmisSupp = -1;
    for (int i = 0; i < fourmiliere->nombresOccupants; i++)
    {
        if (fourmiliere->fourmis[i].sante == 0)
        {
            indexFourmisSupp = i;
            break;
        }
    }

    if (indexFourmisSupp == -1)
    {
        printf("Aucune fourmi est morte aujourd'hui (ouf...)\n");
        return;
    }

    for (int i = indexFourmisSupp; i < fourmiliere->nombresOccupants; i++)
    {
        fourmiliere->fourmis[i] = fourmiliere->fourmis[i + 1];
    }

    fourmiliere->nombresOccupants--;

    FourmiChimere *nouveauTableau = realloc(fourmiliere->fourmis, fourmiliere->nombresOccupants * sizeof(FourmiChimere));
    if (nouveauTableau == NULL && fourmiliere->nombresOccupants > 0)
    {
        printf("ERREUR : Echec de la réallocation mémoire.\n");
        return;
    }

    fourmiliere->fourmis = nouveauTableau;

    printf("Une fourmi est morte (Role %s)\n", fourmiliere->fourmis[indexFourmisSupp].role);
}

void simuler_supprimer_fourmis(Fourmiliere *fourmiliere)
{
    int nbr_mort = 0;
    printf("- Verification de l'etat des fourmis...\n");
    while (1)
    {
        int fourmisMorte = 0;

        for (int i = 0; i < fourmiliere->nombresOccupants; i++)
        {
            if (fourmiliere->fourmis[i].sante == 0)
            {
                supprimerFourmi(fourmiliere);
                fourmisMorte = 1;
                nbr_mort++;
                break;
            }
        }

        if (fourmisMorte == 0)
        {
            break;
        }
    }

    if (nbr_mort == 0)
    {
        printf("- Aucune fourmis est morte !! (Oufff...)\n");
    }
}
