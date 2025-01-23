#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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

    fourmiliere->nombresOccupants = taille_initiale;
    for (int i = 0; i < taille_initiale; i++)
    {
        if (i == 0)
        {
            fourmiliere->fourmis[i].age = 10; // La reine commence à un âge adulte
            strcpy(fourmiliere->fourmis[i].role, "REINE");
            fourmiliere->fourmis[i].nen = 100;
            fourmiliere->fourmis[i].role_specifique.reine.nb_oeufs = 0;
            fourmiliere->fourmis[i].consommation_nourriture = 10;
            fourmiliere->fourmis[i].sante = 100;
        }
        else if (i > 0 && i < 4)
        {
            fourmiliere->fourmis[i].age = 5;
            strcpy(fourmiliere->fourmis[i].role, "GARDE_ROYAL");
            fourmiliere->fourmis[i].nen = 1000;
            fourmiliere->fourmis[i].consommation_nourriture = 8;
            fourmiliere->fourmis[i].sante = 100;
        }

        else if (i > 3 && i < 7)
        {
            fourmiliere->fourmis[i].age = 5; // Les mâles commencent à 5 jours
            strcpy(fourmiliere->fourmis[i].role, "MALE");
            fourmiliere->fourmis[i].nen = 80;
            fourmiliere->fourmis[i].consommation_nourriture = 5;
            fourmiliere->fourmis[i].sante = 100;
        }
        else if (i > 6 && i < 9)
        {
            fourmiliere->fourmis[i].age = 5; // Les soldats aussi commencent à 5 jours
            strcpy(fourmiliere->fourmis[i].role, "SOLDAT");
            fourmiliere->fourmis[i].nen = 70;
            fourmiliere->fourmis[i].role_specifique.soldat.puissanceCombat = fourmiliere->fourmis->nen;
            fourmiliere->fourmis[i].consommation_nourriture = 5;
            fourmiliere->fourmis[i].sante = 100;
        }
        else if (i > 8 && i < 11)
        {
            fourmiliere->fourmis[i].age = 5; // Les exploratrices commencent à 5 jours
            strcpy(fourmiliere->fourmis[i].role, "EXPLORATRICE");
            fourmiliere->fourmis[i].nen = 90;
            fourmiliere->fourmis[i].consommation_nourriture = 3;
            fourmiliere->fourmis[i].role_specifique.exploratrice.endurance = 100;
            fourmiliere->fourmis[i].sante = 100;
        }
        else
        {
            fourmiliere->fourmis[i].age = 5; // Les ouvrières commencent aussi à 5 jours
            strcpy(fourmiliere->fourmis[i].role, "OUVRIERE");
            fourmiliere->fourmis[i].nen = 50;
            fourmiliere->fourmis[i].role_specifique.ouvriere.nourritureCollect = 0;
            fourmiliere->fourmis[i].consommation_nourriture = 2;
            fourmiliere->fourmis[i].sante = 100;
        }
    }
    // Distribution de l'ID pour chaque fourmis
    for (int i = 0; i < fourmiliere->nombresOccupants + 1; i++)
    {
        fourmiliere->fourmis[i].id = i + 1;
    }

    // Initialisation du stock de nourriture:
    fourmiliere->ressources.stockNourriture = 0;
    fourmiliere->ressources.stockMateriel = 0;
    fourmiliere->ressources.objectif = 0;
}

void initialisation_ressource(Ressources *ressources)
{
    if (ressources == NULL)
    {
        printf("Ressource non alouées");
        return;
    }

    ressources->objectif = 0;
    ressources->Consommation = 0;
    ressources->stockMateriel = 0;
    ressources->stockNourriture = 0;
    strcpy(ressources->categories, "");
    ressources->sante_boost = 0;
    ressources->portions = 0;
}

void creerChamp(ChampAgricole *champ, Fourmiliere *fourmiliere)
{
    champ->productionParJour = nombre_ouvriere(fourmiliere)* 10;
    champ->capaciteMax = 150;
    champ->nourritureStockee = 0;
}

void initialisation(Fourmiliere *fourmiliere, Ressources *ressources, ChampAgricole *champs)
{
    init_fourmiliere(fourmiliere, TAILLE_INITIAL);
    initialisation_ressource(ressources);
    creerChamp(champs, fourmiliere);
}