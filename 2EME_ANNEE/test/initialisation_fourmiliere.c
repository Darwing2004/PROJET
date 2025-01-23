#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "definition_fourmis.h"

// Initialisation de la fourmilière avec les fourmis de base (3 mâles et 1 reine)
void init_fourmiliere(Fourmiliere *fourmiliere, int taille_initiale)
{
    fourmiliere->fourmis = (FourmiChimere *)malloc(taille_initiale * sizeof(FourmiChimere));
    if (fourmiliere->fourmis == NULL)
    {
        printf("ERREUR : erreur d'allocation memoire pour les fourmis.\n");
        exit(1);
    }

    fourmiliere->taille = taille_initiale;
    for (int i = 0; i < taille_initiale; i++)
    {
        if (i == 0)
        {
            fourmiliere->fourmis[i].age = 10; // La reine commence à un âge adulte
            fourmiliere->fourmis[i].role = REINE;
            fourmiliere->fourmis[i].nen = 100;
            fourmiliere->fourmis[i].role_specifique.reine.nb_oeufs = rand() % 5 + 1;
            fourmiliere->fourmis[i].consommation_nourriture = 10;
        }
        else if (i > 0 && i < 4)
        {
            fourmiliere->fourmis[i].age = 5; // Les mâles commencent à 5 jours
            fourmiliere->fourmis[i].role = MALE;
            fourmiliere->fourmis[i].nen = 80;
            fourmiliere->fourmis[i].consommation_nourriture = 5;
        }

        else if (i > 3 && i < 6)
        {
            fourmiliere->fourmis[i].age = 5; // Les ouvrières commencent aussi à 5 jours
            fourmiliere->fourmis[i].role = OUVRIERE;
            fourmiliere->fourmis[i].nen = 50;
            fourmiliere->fourmis[i].role_specifique.ouvriere.nourritureCollect = 1;
            fourmiliere->fourmis[i].consommation_nourriture = 2;
        }
        else if (i > 5 && i < 8)
        {
            fourmiliere->fourmis[i].age = 5; // Les soldats aussi commencent à 5 jours
            fourmiliere->fourmis[i].role = SOLDAT;
            fourmiliere->fourmis[i].nen = 70;
            fourmiliere->fourmis[i].role_specifique.soldat.puissanceCombat = fourmiliere->fourmis->nen;
            fourmiliere->fourmis[i].consommation_nourriture = 5;
        }
        else if (i > 7 && i < 11)
        {
            fourmiliere->fourmis[i].age = 5; // Les exploratrices commencent à 5 jours
            fourmiliere->fourmis[i].role = EXPLORATRICE;
            fourmiliere->fourmis[i].nen = 90;
            fourmiliere->fourmis[i].consommation_nourriture = 3;
        }
        else
        {
            fourmiliere->fourmis[i].age = 5;
            fourmiliere->fourmis[i].role = GARDE_ROYAL;
            fourmiliere->fourmis[i].nen = 1000;
            fourmiliere->fourmis[i].consommation_nourriture = 8;
        }
    }

    // Initialisation du stock de nourriture:
    fourmiliere->ressources.stockNourriture = 0;
    fourmiliere->ressources.stockMateriel = 0;
    fourmiliere->ressources.objectif = 0;
}