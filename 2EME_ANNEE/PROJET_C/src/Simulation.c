#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include "definition_fourmis.h"
const char *Saison(int jour)
{ // Fonction simulant le cycle de saison en fonction du jour de l'an

    jour = (jour % 365 == 0) ? 365 : jour % 365;

    if (jour >= 1 && jour <= 79)
    {
        return "Hiver";
    }

    if (jour >= 80 && jour <= 172)
    {
        return "Printemps";
    }

    if (jour >= 173 && jour <= 266)
    {
        return "Ete";
    }

    if (jour >= 267 && jour <= 356)
    {
        return "Automne";
    }
    if (jour >= 356 && jour <= 365)
    {
        return "Hiver";
    }
}

bool VerifiersaisonHiver(const char *season)
{ // Fonctions booléenne verifiant les saisons pour le cycle de vie des fourmis

    if (strcmp(season, "Hiver") == 0)
    {
        return true;
    }
    return false;
}

bool VerifiersaisonPrintemps(const char *season)
{

    if (strcmp(season, "Printemps") == 0)
    {
        return true;
    }
    return false;
}

bool VerifiersaisonEte(const char *season)
{

    if (strcmp(season, "Ete") == 0)
    {
        return true;
    }
    return false;
}

bool VerifiersaisonAutomne(const char *season)
{

    if (strcmp(season, "Automne") == 0)
    {
        return true;
    }
    return false;
}

int saison_en_jour(const char *season)
{
    if (strcmp(season, "Hiver") == 0)
    {
        return 1;
    }

    if (strcmp(season, "Printemps") == 0)
    {
        return 80;
    }

    if (strcmp(season, "Ete") == 0)
    {
        return 173;
    }

    if (strcmp(season, "Automne") == 0)
    {
        return 267;
    }
}

int nombre_ouvriere(Fourmiliere *fourmiliere)
{
    int nbr_ouvriere = 0;
    for (int i = 0; i < fourmiliere->nombresOccupants; i++)
    {

        if (strcmp(fourmiliere->fourmis[i].role, "OUVRIERE") == 0)
        {
            nbr_ouvriere++;
        }
    }
    return nbr_ouvriere;
}

int nombre_exploratrice(Fourmiliere *fourmiliere)
{
    int nbr_exploratrice = 0;
    for (int i = 0; i < fourmiliere->nombresOccupants; i++)
    {

        if (strcmp(fourmiliere->fourmis[i].role, "EXPLORATRICE") == 0)
        {
            nbr_exploratrice++;
        }
    }
    return nbr_exploratrice;
}

int nombre_soldat(Fourmiliere *fourmiliere)
{
    int nbr_soldat = 0;
    for (int i = 0; i < fourmiliere->nombresOccupants; i++)
    {
        if (strcmp(fourmiliere->fourmis[i].role, "SOLDAT") == 0)
        {
            nbr_soldat++;
        }
    }
    return nbr_soldat;
}

int nombre_male(Fourmiliere *fourmiliere)
{
    int nbr_male = 0;
    for (int i = 0; i < fourmiliere->nombresOccupants; i++)
    {
        if (strcmp(fourmiliere->fourmis[i].role, "MALE") == 0)
        {
            nbr_male++;
        }
    }
    return nbr_male;
}

int nombre_garde_royal(Fourmiliere *fourmiliere)
{
    int nbr_garde = 0;
    for (int i = 0; i < fourmiliere->nombresOccupants; i++)
    {
        if (strcmp(fourmiliere->fourmis[i].role, "GARDE_ROYAL") == 0)
        {
            nbr_garde++;
        }
    }

    return nbr_garde;
}

int nombre_reine(Fourmiliere *fourmiliere)
{
    int nbr_reine = 0;
    for (int i = 0; i < fourmiliere->nombresOccupants; i++)
    {
        if (strcmp(fourmiliere->fourmis[i].role, "REINE") == 0)
        {
            nbr_reine++;
        }
    }

    return nbr_reine;
}

void simulation(Fourmiliere *fourmiliere, Ressources *besoin, Evenement *event, ChampAgricole *champs)
{
    int temps;
    int jours;
    char choix_saison[50];

    system("cls");
    printf("SIMULATION\n");
    printf("Combien de jours voulez vous simuler la fourmiliere ? :");
    scanf("%d", &temps);

    printf("Durant quels saisons voulez-vous commence ? (Hiver, Automne, Printemps, Ete) : ");
    scanf("%49s", choix_saison);

    const char *saison = choix_saison;
    jours = saison_en_jour(choix_saison);

    printf("Nous sommes donc en %s au jours %d de l'annee\n", saison, jours);

    printf("Commencons donc la simulation ! Veuillez patienter...\n");
    sleep(3);
    system("cls");

    for (int i = 0; i < temps; i++)
    {
        printf(" ***** JOURS %d *****\n", i + 1);
        usleep(500000);
        printf("**** FOURMILIERE ****\n");
        usleep(500000);
        printf("- Nombre de fourmis : %d\n", fourmiliere->nombresOccupants);
        usleep(500000);
        printf("- Reine : %d\n", nombre_reine(fourmiliere));
        usleep(500000);
        printf("- Garde Royal : %d\n", nombre_garde_royal(fourmiliere));
        usleep(500000);
        printf("- Male : %d\n", nombre_male(fourmiliere));
        usleep(500000);
        printf("- Ouvriere : %d\n", nombre_ouvriere(fourmiliere));
        usleep(500000);
        printf("- Exploratrice : %d\n", nombre_exploratrice(fourmiliere));
        usleep(500000);
        printf("- Soldat : %d\n", nombre_soldat(fourmiliere));
        usleep(500000);
        printf("\n");
        printf("**** CYCLE DE LA REINE ****\n");
        simualtion_cycle_reine(fourmiliere, i);
        usleep(500000);
        printf("\n");
        printf("**** GESTION DES STOCKS ****\n");
        usleep(500000);
        simulation_chasse(fourmiliere, besoin, event, jours);
        usleep(500000);
        simulation_agricole(champs, besoin);
        usleep(500000);
        printf("\n");
        printf("**** CONSOMATION DE LA NOURRITURE ****\n");
        usleep(500000);
        simulerConsommation(besoin, fourmiliere);
        printf("\n");
        printf("**** ETAT DE LA FOURMILIERE ****\n");
        simuler_supprimer_fourmis(fourmiliere);
        gererStock(besoin);
        sleep(2);
        printf("\n\n");
    }
}
