#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "definition_fourmis.h"

void afficher_menu()
{
    printf("************************************************************************************\n");
    printf("******************************** PROJET KIMERA ANTS ********************************\n");
    printf("************************************************************************************\n");
    printf("\nBIENVENUE DANS LE MONDE DU CELEBRE ANIME HUNTERXHUNTER !!!!\n");
    printf("Ce jeu vous propose de simuler une fourmiliere de fourmis chimere du monde d'HxH.\n");
    printf("Vous devez choisir une action dans le menu ci-dessus pour commencer a jouer.\n");
    printf("========================\n");
    printf("\n***** MENU PRINCIPAL *****\n");
    printf("[1] LANCER LA SIMULATION DE LA FOURMILIERE\n");
    printf("[2] AFFICHER FOURMILIERE\n");
    printf("[3] SIMULATION DE LA CHASSE\n");
    printf("[4] CONSOMMATION NOURRITURE\n");
    printf("[5] CYCLE DE LA REINE\n");
    printf("[6] SIMULATION CHAMMPS DES OUVRIERE\n");
    printf("[7] Quitter\n");
    printf("========================\n");
    printf("Votre choix : ");
}

int main()
{
    srand(time(NULL)); // Initialiser la génération de nombres aléatoires

    Fourmiliere fourmiliere;
    Ressources ressources;
    Evenement event;
    ChampAgricole champs;

    initialisation(&fourmiliere, &ressources, &champs);

    int choix;

    do
    {
        afficher_menu();
        scanf("%d", &choix);
        switch (choix)
        {
        case 1:
            simulation(&fourmiliere, &ressources, &event, &champs);
            break;
        case 2:
            afficher_fourmis(&fourmiliere);
            break;
        case 3:
            simulation_collect_nourriture_details(&fourmiliere, &ressources, &event);
            break;
        case 4:
            simulerConsommation(&ressources, &fourmiliere);
            break;
        case 5:
            simulation_cycle_reine_details(&fourmiliere);
            break;
        case 6:
            int temps;
            printf("Combien de temps voulez-vous simuler ? :");
            scanf("%d", &temps);
            simulation_champs_details(&champs, &fourmiliere, &ressources, temps);
            break;
        case 7:
            printf("Au revoir !! (Bisou <3)\n");
            exit(0);
            break;
        default:
            printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != 7);

    // Libérer la mémoire allouée pour la fourmilière
    free(fourmiliere.fourmis);

    return 0;
}
