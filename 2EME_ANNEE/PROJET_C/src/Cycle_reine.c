#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "definition_fourmis.h"

// Ajoute de nouveaux enfants en pondant des œufs
void pondre_oeufs(Fourmiliere *fourmiliere, int jours)
{
    int nouveaux_enfants = 0;
    const char *season = Saison(jours);
    if (VerifiersaisonEte(season) || VerifiersaisonPrintemps(season))
    {
        nouveaux_enfants = fourmiliere->fourmis->role_specifique.reine.nb_oeufs = rand() % 15 + 1;
    }

    if (VerifiersaisonHiver(season) || VerifiersaisonAutomne(season))
    {
        nouveaux_enfants = fourmiliere->fourmis->role_specifique.reine.nb_oeufs = rand() % 5 + 1;
    }

    fourmiliere->nombresOccupants += nouveaux_enfants;
    fourmiliere->fourmis = (FourmiChimere *)realloc(fourmiliere->fourmis, fourmiliere->nombresOccupants * sizeof(FourmiChimere));

    for (int i = fourmiliere->nombresOccupants - nouveaux_enfants; i < fourmiliere->nombresOccupants; i++)
    {
        fourmiliere->fourmis[i].age = 0;
        fourmiliere->fourmis[i].nen = rand() % 100 + 1;
        fourmiliere->fourmis[i].sante = 100;
        strcpy(fourmiliere->fourmis[i].role, "OEUF");
    }

    printf("Il y a eu %d oeufs de pondu, il y a donc maintenant %d fourmis.\n", nouveaux_enfants, fourmiliere->nombresOccupants);
}

// Augmente l'âge des fourmis et met à jour leur rôle si nécessaire
void vieillir_fourmis(Fourmiliere *fourmiliere)
{
    for (int i = 0; i < fourmiliere->nombresOccupants; i++)
    {
        fourmiliere->fourmis[i].age++;

        if (fourmiliere->fourmis[i].age >= 6 && fourmiliere->fourmis[i].age < 40)
        {
            if (strcmp(fourmiliere->fourmis[i].role, "OEUF") == 0)
            {
                attribuer_role(&fourmiliere->fourmis[i]);
            }
        }
    }
}

// Affiche les caractéristiques de toutes les fourmis de la fourmilière
void afficher_fourmis(Fourmiliere *fourmiliere)
{
    for (int i = 0; i < fourmiliere->nombresOccupants; i++)
    {
        printf("- FOURMI %d: Age: %d, Nen: %d, Role: %s",
               i + 1,
               fourmiliere->fourmis[i].age,
               fourmiliere->fourmis[i].nen,
               fourmiliere->fourmis[i].role);

        printf("\n");
    }
}

void simualtion_cycle_reine(Fourmiliere *fourmiliere, int jours)
{
    int intervalles_ponte = 7;
    printf("- Nombre de fourmis : %d\n", fourmiliere->nombresOccupants);

    if (((jours + 1) % intervalles_ponte) == 0)
    {
        pondre_oeufs(fourmiliere, 80);
        printf("- La reine a pondu des oeufs ! \n");
    }
    else{
        printf("- La Reine n'a pas pondu d'oeufs...\n");
    }
    vieillir_fourmis(fourmiliere);
    // afficher_fourmis(&fourmiliere);
    printf("\n");
    sleep(1);
}

void simulation_cycle_reine_details(Fourmiliere *fourmiliere)
{
    int intervalles_ponte = 7;
    int temps = 0;
    int jours;
    char choix_saison[20];
    printf("Durant combien de jours voulez-vous simuler ? :");
    scanf("%d", &temps);

    printf("Durant quelles saisons voulez-vous simuler ?(Hiver, Printemps, Ete, Automne) :");
    scanf("%49s", choix_saison);

    const char *saison = choix_saison;
    jours = saison_en_jour(choix_saison);

    printf("Nous sommes donc en %s au jours %d de l'annee\n", saison, jours);

    printf("Commencons donc la simulation ! Veuillez patienter...\n");
    sleep(3);
    system("cls");

    for (int i = 0; i < temps; i++)
    {
        printf(" JOURS %d \n", i + 1);
        printf("Saison : %s\n", saison);
        printf("Nombre de fourmis : %d\n", fourmiliere->nombresOccupants);
        sleep(1);
        if (((i + 1) % intervalles_ponte) == 0)
        {
            pondre_oeufs(fourmiliere, jours);
        }
        else
        {
            printf("La reine n'a pas pondu d'oeufs...\n");
        }
        vieillir_fourmis(fourmiliere);
        printf("\n");
        sleep(1);
    }
}
