#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include "definition_fourmis.h"

// On calcule la nourriture que l'on doit trouver pour que chaque fourmis puissent manger
void objectif_nourriture(Fourmiliere *fourmiliere, Ressources *besoin)
{
    besoin->objectif = 0;
    for (int i = 0; i < fourmiliere->nombresOccupants; i++)
    {
        besoin->objectif += fourmiliere->fourmis[i].consommation_nourriture;
    }

    printf("- Stock present dans la fourmiliere : %d\n", besoin->stockNourriture); // On calcule la nourriture qu'on doit ramener pour atteindre l'objectif
    usleep(500000);
    printf("- Objectif : %d unite(s) de nourriture pour %d fourmis !\n", besoin->objectif, fourmiliere->nombresOccupants);
    usleep(500000);
}

// Les fourmis exploratrices cherchent et trouvent des sources
void explorer_source(Fourmiliere *fourmiliere)
{
    // Facteur chance qui sera modifier en fonction des evements et des température
    fourmiliere->decouvertes = 0; // Réinitialisation des découvertes
    for (int i = 0; i < fourmiliere->nombresOccupants; i++)
    {
        if (strcmp(fourmiliere->fourmis[i].role, "EXPLORATRICE") == 0 && fourmiliere->fourmis[i].role_specifique.exploratrice.decouvertes > 0)
        {
            // Une fourmi exploratrice trouve 1 sources de nourriture
            fourmiliere->fourmis[i].role_specifique.exploratrice.decouvertes = 1;
            // On rajoute la découverte au nombre de découverte totale
            fourmiliere->decouvertes += fourmiliere->fourmis[i].role_specifique.exploratrice.decouvertes;

            // On diminue de 20 l'endurance de la fourmis exploratrice:
            fourmiliere->fourmis[i].role_specifique.exploratrice.endurance = fourmiliere->fourmis[i].role_specifique.exploratrice.endurance - 20;
        }
    }
    printf("- %d sources de nourritures decouverte par les fourmis exploratrice (BRAVO !!!) !\n", fourmiliere->decouvertes);
    usleep(500000);
}

int ChercherNourriture(Fourmiliere *fourmiliere, Source_nourriture **source, Evenement *event, int jours)
{
    *source = malloc(sizeof(Source_nourriture) * fourmiliere->decouvertes);
    const char *season = Saison(jours);

    if (event == NULL)
    {
        printf("Erreur : event n'est pas alloué.\n");
        exit(1);
    }

    if (VerifiersaisonAutomne(season) || VerifiersaisonPrintemps(season))
    {
        event->impactNourriture = 150;
    }

    if (VerifiersaisonHiver(season))
    {
        event->impactNourriture = 65;
    }

    if (VerifiersaisonEte(season))
    {
        event->impactNourriture = 100;
    }

    for (int i = 0; i < fourmiliere->decouvertes; i++)
    {
        (*source)[i].quantite_nourriture = rand() % event->impactNourriture + 1;
    }
    if (*source == NULL)
    {
        printf("ERREUR : l'allocation n'a pas reussi\n");
        exit(1);
    }

    int nourrituretotal = 0;
    for (int i = 0; i < fourmiliere->decouvertes; i++)
    {
        nourrituretotal += (*source)[i].quantite_nourriture;
    }

    printf("- Total nourriture trouvee : %d\n", nourrituretotal);
    usleep(500000);
    return nourrituretotal;
}

// Les fourmis ouvrières partent récupérer la nourriture.
void collect_nourriture(Source_nourriture *source, Fourmiliere *fourmiliere)
{
    int collecteTotale = 0;

    while (source->quantite_nourriture > 0)
    {
        int nourritureCollectee = 0;

        for (int i = 0; i < fourmiliere->nombresOccupants; i++)
        {
            if (strcmp(fourmiliere->fourmis[i].role, "OUVRIERE") == 0 &&
                fourmiliere->fourmis[i].role_specifique.ouvriere.nourritureCollect < fourmiliere->fourmis[i].role_specifique.ouvriere.capacite)
            {
                // Une unité de nourriture collectée
                fourmiliere->fourmis[i].role_specifique.ouvriere.nourritureCollect++;
                source->quantite_nourriture--;
                nourritureCollectee++;

                // Arrêter si la source est vide
                if (source->quantite_nourriture == 0)
                    break;
            }
        }

        collecteTotale += nourritureCollectee;

        // Si aucune fourmi n'a collecté, on quitte la boucle pour éviter un boucle infinie
        if (nourritureCollectee == 0)
        {
            printf("Aucune collecte supplementaire possible. Source restante : %d\n", source->quantite_nourriture);
            break;
        }
    }
}

void deposer_nourriture(Fourmiliere *fourmiliere, Ressources *besoin)
{
    for (int i = 0; i < fourmiliere->nombresOccupants; i++)
    {
        if (strcmp(fourmiliere->fourmis[i].role, "OUVRIERE") == 0)
        {
            besoin->stockNourriture += fourmiliere->fourmis[i].role_specifique.ouvriere.nourritureCollect;
            fourmiliere->fourmis[i].role_specifique.ouvriere.nourritureCollect = 0;
        }
    }
}

void simulation_collect_nourriture_details(Fourmiliere *fourmiliere, Ressources *besoin, Evenement *event)
{
    printf("\n***************************************************************************\n");
    printf("******************** SIMULATION COLLECTE DE NOURRITURE ********************\n");
    printf("***************************************************************************\n\n");
    // ETAPE 0 : On definit durant quelle saisons les fourmis chassent :
    int jours;
    char choix_saison[50];

    printf("Durant quels saisons voulez-vous commence ? (Hiver, Automne, Printemps, Ete) : ");
    scanf("%49s", choix_saison);

    const char *saison = choix_saison;
    jours = saison_en_jour(choix_saison);
    // ETAPE 1 : On définit l'objectif en comptant la nourriture que chacune des fourmis mange
    printf("********** OBJECTIF NOURRITURE **********\n");
    objectif_nourriture(fourmiliere, besoin);
    printf("\n");

    // Etape 2 : On commence par explorer et trouver des sources de nourritures
    printf("********** EXPLORATION **********\n");
    explorer_source(fourmiliere);
    printf("\n");

    // On vérifie si les fourmis exploratrices ont trouvé des sources de nourriture.
    if (fourmiliere->decouvertes == 0)
    {
        printf("Aucune source de nourriture a ete trouve !\n");
        return;
    }

    // Etape 3 : On génère des sources de nourriture
    printf("********** GESTION SOURCE DE NOURRITURE **********\n");
    Source_nourriture *source = NULL; // Déclaration du pointeur
    int totalnourriture = ChercherNourriture(fourmiliere, &source, event, jours);

    if (totalnourriture < besoin->objectif)
    {
        printf("Il n'y a pas assez de nourriture pour alimenter toute la fourmiliere (Dommage...) !\n");
    }

    // Etape 4 : On collecte et stocke la nourriture dans la fourmilière jusqu'à atteindre l'objectif demandé
    printf("********** COLLECTE DE LA NOURRITURE **********\n");
    for (int i = 0; i < fourmiliere->decouvertes; i++)
    {
        if (source[i].quantite_nourriture > 0)
        {
            printf("****** SOURCE %d ******\n", i + 1);
            collect_nourriture(&source[i], fourmiliere);
            deposer_nourriture(fourmiliere, besoin);
            printf("\n");
        }
    }

    printf("\n");

    if (besoin->stockNourriture > besoin->objectif)
    {
        printf("- Objectif atteint : %d unites de nourriture ont ete collectees et stockees pour un objectif de %d !\n", besoin->stockNourriture, besoin->objectif);
    }
    else
    {
        printf("- Objectif non atteint : %d unites de nourriture ont ete collectees et stockees pour un objectif de %d !\n", besoin->stockNourriture, besoin->objectif);
    }

    free(source); // Libération de la mémoire allouée
    source = NULL;
}

// Fonction utiliser dans la fonction simulation
void simulation_chasse(Fourmiliere *fourmiliere, Ressources *besoin, Evenement *event, int jours)
{
    printf("Collecte de nourriture :\n");
    objectif_nourriture(fourmiliere, besoin);
    explorer_source(fourmiliere);
    Source_nourriture *source = NULL; // Déclaration du pointeur
    int totalnourriture = ChercherNourriture(fourmiliere, &source, event, jours);
    for (int i = 0; i < fourmiliere->decouvertes; i++)
    {
        if (source[i].quantite_nourriture > 0)
        {
            collect_nourriture(&source[i], fourmiliere);
            deposer_nourriture(fourmiliere, besoin);
        }
    }

    if (besoin->stockNourriture >= besoin->objectif)
    {
        printf("- Objectif atteint : %d unites de nourriture ont ete collectees et stockees pour un objectif de %d !\n", besoin->stockNourriture, besoin->objectif);
        usleep(500000);
    }
    else
    {
        printf("- Objectif non atteint : %d unites de nourriture ont ete collectees et stockees pour un objectif de %d !\n", besoin->stockNourriture, besoin->objectif);
        usleep(500000);
    }
}