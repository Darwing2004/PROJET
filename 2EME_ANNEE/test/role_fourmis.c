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

// Attribuer un rôle à une fourmi en fonction de sa nen et de son âge
void attribuer_role(FourmiChimere *fourmi)
{
    if (fourmi->role != ENFANT)
    {
        return;
    }

    if (fourmi->age >= 5)
    {
        if (fourmi->nen <= 60)
        {
            fourmi->role = OUVRIERE;
            fourmi->role_specifique.ouvriere.capacite = 1;
            fourmi->consommation_nourriture = 2;
        }
        else if (fourmi->nen > 60 && fourmi->nen <= 80)
        {
            fourmi->role = SOLDAT;
            fourmi->role_specifique.soldat.puissanceCombat = fourmi->nen;
            fourmi->consommation_nourriture = 5;
        }
        else
        {
            fourmi->role = EXPLORATRICE;
            fourmi->consommation_nourriture = 3;
            fourmi->role_specifique.exploratrice.endurance = 100;
        }
    }
}

void simuler_cycle(Fourmiliere *fourmiliere, int nbr_cycle)
{
    if (fourmiliere == NULL)
    {
        printf("ERREUR : Il n'y a pas de fourmiliere\n");
        exit(1);
    }
    printf("COombien de cycle voulez-vous simuler ? :");
    scanf("%d", &nbr_cycle);

    for (int i = 0; i < nbr_cycle; i++)
    {
        printf("*****************************\n");
        printf("********** CYCLE %d **********\n", i + 1);
        printf("*****************************\n");
        pondre_oeufs(fourmiliere);
        vieillir_fourmis(fourmiliere);

        for (int i = 0; i < fourmiliere->taille; i++)
        {
            if (fourmiliere->fourmis[i].role == ENFANT)
            {
                attribuer_role(&fourmiliere->fourmis[i]);
            }
        }

        afficher_fourmis(fourmiliere);
    }
}

// Augmente l'âge des fourmis et met à jour leur rôle si nécessaire
void vieillir_fourmis(Fourmiliere *fourmiliere)
{
    for (int i = 0; i < fourmiliere->taille; i++)
    {
        fourmiliere->fourmis[i].age++;

        if (fourmiliere->fourmis[i].age >= 6 && fourmiliere->fourmis[i].age < 40)
        {
            if (fourmiliere->fourmis[i].role == ENFANT)
            {
                attribuer_role(&fourmiliere->fourmis[i]);
            }
        }
        else if (fourmiliere->fourmis[i].age >= 40)
        {
            fourmiliere->fourmis[i].role = VIEILLE;
        }
    }
}

// Ajoute de nouveaux enfants en pondant des œufs
void pondre_oeufs(Fourmiliere *fourmiliere)
{
    int nouveaux_enfants = fourmiliere->fourmis->role_specifique.reine.nb_oeufs;

    fourmiliere->taille += nouveaux_enfants;
    fourmiliere->fourmis = (FourmiChimere *)realloc(fourmiliere->fourmis, fourmiliere->taille * sizeof(FourmiChimere));

    for (int i = fourmiliere->taille - nouveaux_enfants; i < fourmiliere->taille; i++)
    {
        fourmiliere->fourmis[i].age = 0;
        fourmiliere->fourmis[i].nen = rand() % 100 + 1;
        fourmiliere->fourmis[i].role = ENFANT;
    }
}

// Affiche les caractéristiques de toutes les fourmis de la fourmilière
void afficher_fourmis(Fourmiliere *fourmiliere)
{

    printf("Liste des fourmis :\n");
    for (int i = 0; i < fourmiliere->taille; i++)
    {
        printf("***** FOURMI %d *****\n", i + 1);
        printf("Age: %d, Nen: %d, ", fourmiliere->fourmis[i].age, fourmiliere->fourmis[i].nen);

        switch (fourmiliere->fourmis[i].role)
        {
        case REINE:
            printf("Role: Reine, Nombre d'oeufs pondus: %d\n", fourmiliere->fourmis[i].role_specifique.reine.nb_oeufs);
            break;
        case OUVRIERE:
            printf("Role: Ouvriere, Nourriture collectee: %d\n", fourmiliere->fourmis[i].role_specifique.ouvriere.nourritureCollect);
            break;
        case SOLDAT:
            printf("Role: Soldat, Puissance de combat: %d\n", fourmiliere->fourmis[i].role_specifique.soldat.puissanceCombat);
            break;
        case EXPLORATRICE:
            printf("Role: Exploratrice\n");
            break;
        case ENFANT:
            printf("Role: Enfant\n");
            break;
        case MALE:
            printf("Role: Male\n");
            break;
        case VIEILLE:
            printf("Role: Vieille\n");
            break;
        }
    }
}
