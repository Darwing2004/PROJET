#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "definition_fourmis.h"

//Fonction pour ajouter de la nourriture
void ajouterNourriture(Ressources *ressources, int quantite) // Ajout de la nourriture
{

    if (quantite <= 0)
    {
        printf("Mince t'as fais une erreur bete. la quantite a ajouter doit être positive !\n");
        return;
    }

    ressources->stockNourriture += quantite;
    printf("Ajoute %d unites de nourriture. Le stock actuel est %d.\n", quantite, ressources->stockNourriture);
}

bool consommerNourriture(Ressources *ressources, int quantite) // Consomation nourriture
{
    if (quantite <= 0)
    {
        printf("Mince t'as fais une erreur bete. La quantite a consommer doit être positive.\n");
        return false;
    }

    if (quantite > ressources->stockNourriture)
    {
        printf("Mince Pas assez de nourriture dans le stock.\n");
        return false;
    }

    ressources->stockNourriture -= quantite;
    ressources->Consommation += quantite;

    printf("Consomme %d unites de nourriture. Stock restant : %d.\n", quantite, ressources->stockNourriture);
    return true;
}

// Fonction pour la simulation de la consommation de la nourriture par les fourmis
void simulerConsommation(Ressources *ressources, FourmiChimere *fourmis, int nombreDeFourmis) // Simulation conso
{
    for (int i = 0; i < nombreDeFourmis; i++)
    {
        int conso = 0;

        if (strcmp(fourmis[i].role, "Reine") == 0)
        {
            conso = 10;
        }
        else if (strcmp(fourmis[i].role, "Garde Royale") == 0)
        {
            conso = 8;
        }
        else if (strcmp(fourmis[i].role, "Soldat") == 0)
        {
            conso = 5;
        }
        else if (strcmp(fourmis[i].role, "Ouvriere") == 0)
        {
            conso = 2;
        }
        else if (strcmp(fourmis[i].role, "Exploratrice") == 0)
        {
            conso = 3;
        }

        if (ressources->stockNourriture >= conso)
        {
            ressources->stockNourriture -= conso;
            ressources->Consommation += conso;

            printf("La fourmi %s (Role : %s) a consomme %d unites de nourriture.\n", fourmis[i].nom, fourmis[i].role, conso);
        }

        else
        {
            printf("Pas assez de nourriture pour la fourmi %s (Role : %s).\n", fourmis[i].nom, fourmis[i].role);
        }
    }
}

struct Fourmiliere creerColonie(int nombreSalles, int nombreReines) // Creer 1 Colonies
{
    struct Fourmiliere colonie;

    colonie.gestionRessources.stockNourriture = 100 * nombreReines;
    colonie.gestionRessources.stockMateriel = 50;
    colonie.gestionRessources.Consommation = 0;

    colonie.salleCount = nombreSalles;
    colonie.salles = (struct Salle *)malloc(sizeof(struct Salle) * nombreSalles);

    for (int i = 0; i < nombreSalles; i++)
    {
        colonie.salles[i].id = i + 1;
        strcpy(colonie.salles[i].type, "salle générique");
        colonie.salles[i].capacité = 20;
        colonie.salles[i].fourmisOccupantes = 0;
    }

    return colonie;
}

struct GestionColonies creerGestionColonies(int nombreColonies, int nombreSalles, int nombreReines) // Creer Plusieurs
{
    struct GestionColonies gestion;

    gestion.nombreColonies = nombreColonies;
    gestion.colonies = (struct Fourmiliere *)malloc(sizeof(struct Fourmiliere) * nombreColonies);

    for (int i = 0; i < nombreColonies; i++)
    {
        gestion.colonies[i] = creerColonie(nombreSalles, nombreReines);
    }
    return gestion;
}

void afficherGestionColonies(struct GestionColonies *gestion)
{
    printf("gestion %d colonies :\n", gestion->nombreColonies);

    for (int i = 0; i < gestion->nombreColonies; i++)
    {
        printf("Colonie %d :\n", i + 1);
        printf("- nourriture : %d\n", gestion->colonies[i].gestionRessources.stockNourriture);
        printf("- materiel : %d\n", gestion->colonies[i].gestionRessources.stockMateriel);
        printf("- nombre de salles : %d\n", gestion->colonies[i].salleCount);
    }
}

void creerChamp(struct ChampAgricole *champ, int id, int production, int capacite)
{
    champ->id = id;
    champ->productionParJour = production;
    champ->capaciteMax = capacite;
    champ->nourritureStockee = 0;
}

void produireNourriture(struct ChampAgricole *champ)
{
    if (champ->nourritureStockee + champ->productionParJour <= champ->capaciteMax)
    {
        champ->nourritureStockee += champ->capaciteMax;
    }
    else
    {
        champ->nourritureStockee = champ->capaciteMax;
    }

    printf("Champ %d a produit %d unites de nourriture. stock actuel : %d\n", champ->id, champ->productionParJour, champ->nourritureStockee);
}

void recolterNourriture(struct ChampAgricole *champ, struct Ressources *ressources)
{
    ressources->stockNourriture += champ->nourritureStockee;
    printf("Recolte %d unite de nourriture du champ %d. Stock total : %d\n", champ->nourritureStockee, champ->id, ressources->stockNourriture);
    champ->nourritureStockee = 0;
}

void demarrerProjet(struct ProjetConstruction *projet, const char *type, int materielNecessaire)
{
    strcpy(projet->type, type);
    projet->materielNecessaire = materielNecessaire;
    projet->progression = 0;
    printf("Pojet de type %s démaré. Materiaux necessaire : %d. \n", projet->type, projet->materielNecessaire);
}

bool avancerProjet(struct ProjetConstruction *projet, struct Ressources *ressources)
{
    if (projet->progression >= projet->materielNecessaire)
    {
        printf("Le projet %s est deja termine\n", projet->type);
        return false;
    }

    if (ressources->stockMateriel > 0)
    {
        int materielUtilise = ressources->stockMateriel >= 10 ? 10 : ressources->stockMateriel;
        projet->progression += materielUtilise;
        ressources->stockMateriel -= materielUtilise;

        printf("Projet %s avance de %d unite. Progression : %d/%d.\n", projet->type, materielUtilise, projet->progression, projet->materielNecessaire);

        if (projet->progression >= projet->materielNecessaire)
        {
            printf("Le projet '%s' est maintenant terminé !\n", projet->type);
        }
        return true;
    }

    else
    {
        printf("Pas assez de matériaux disponibles pour avancer le projet '%s'.\n", projet->type);
        return false;
    }
}

void afficherProjet(struct ProjetConstruction *projet)
{
    printf("Projet '%s' - Progression : %d/%d.\n",
           projet->type, projet->progression, projet->materielNecessaire);
}
