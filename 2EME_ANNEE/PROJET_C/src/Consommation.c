#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include "definition_fourmis.h"

// Fonction pour la simulation de la consommation de nourriture
void simulerConsommation(Ressources *besoin, Fourmiliere *fourmiliere)
{
    besoin->Consommation = 0;
    if (besoin == NULL)
    {
        printf("ERREUR : Resources non initialisee.\n");
        return;
    }

    if (fourmiliere == NULL)
    {
        printf("ERREUR : Fourmiliere non initialisees.");
        return;
    }

    if(besoin->stockNourriture == 0)
    {
        printf("Il n'y a pas de nourriture...\n");
        return;
    }

    int conso = 0;
    int j = 0;
    for (int i = 0; i < fourmiliere->nombresOccupants; i++)
    {
        if (strcmp(fourmiliere->fourmis[i].role, "REINE") == 0)
        {
            conso = 10;
        }
        else if (strcmp(fourmiliere->fourmis[i].role, "GARDE_ROYAL") == 0)
        {
            conso = 8;
        }
        else if(strcmp(fourmiliere->fourmis[i].role, "MALE") == 0)
        {   
            conso = 5;
        }
        else if (strcmp(fourmiliere->fourmis[i].role, "SOLDAT") == 0)
        {
            conso = 5;
        }
        else if (strcmp(fourmiliere->fourmis[i].role, "OUVRIERE") == 0)
        {
            conso = 2;
        }
        else if (strcmp(fourmiliere->fourmis[i].role, "EXPLORATRICE") == 0)
        {
            conso = 3;
        }
        else
        {
            conso = 0;
        }

        if (besoin->stockNourriture >= conso)
        {
            besoin->stockNourriture -= conso;
            besoin->Consommation += conso;

            printf("- La fourmi %d (Role : %s) a consomme %d unites de nourriture.\n", j++, fourmiliere->fourmis[i].role, conso);
            usleep(500000);
        }
        else
        {
            printf("- Pas assez de nourriture pour la fourmi  (Role : %s).\n", fourmiliere->fourmis[i].role);
            fourmiliere->fourmis[i].sante -= 20;
            printf("  - La sante de la fourmis est de %d\n", fourmiliere->fourmis[i].sante);
            usleep(500000);
        }
    }

    printf("Consommation totale de la fourmiliere : %d unites. Stock: %d\n", besoin->Consommation, besoin->stockNourriture);
}


