#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "definition_fourmis.h"

Tache *cree_tache(const char *nom)
{
    Tache *tache = (Tache *)malloc(sizeof(Tache));
    if (tache != NULL)
    {
        strcpy(tache->nom, nom);
        tache->valide = false;
        tache->sousTaches = NULL;
        tache->nbsousTaches = 0;
    }

    return tache;
}

void ajouterSousTache(Tache *tache, Tache *sousTache)
{
    Tache *temp = (Tache *)realloc(tache->sousTaches, sizeof(Tache) * (tache->nbsousTaches + 1));
    
    if (temp != NULL)
    {
        tache->sousTaches = temp;
        tache->sousTaches[tache->nbsousTaches] = *sousTache;
        tache->nbsousTaches++;
    }
}

void validerTache(Tache *tache, Ressources *besoin)
{
    if (tache != NULL)
    {
        if (strcmp(tache->nom, "Chasser") == 0 && besoin->stockNourriture > 0)
        {
            tache->valide = true;
            printf("Tache '%s' valide !!!\n", tache->nom);
        }

        else if (strcmp(tache->nom, "Consommer nourriture") == 0 && besoin->Consommation == besoin->objectif)
        {
            tache->valide = true;
            printf("Tache '%s' valide !!\n", tache->nom);
        }

        else
        {
            tache->valide = false;
            printf("Tache '%s' non valide !\n", tache->nom);
        }
    }
}

void afficheTache(Tache *tache, int niveau)
{
    if (tache != NULL)
    {
        for (int i = 0; i < niveau; i++)
        {
            printf("  ");
        }
        printf("Tache: %s\n", tache->nom);
        for (int i = 0; i < tache->nbsousTaches; i++)
        {
            afficheTache(&(tache->sousTaches[i]), niveau + 1);
        }
    }
}

void libererTache(Tache *tache)
{
    if (tache != NULL)
    {
        free(tache->sousTaches);
        free(tache);
    }
}

void gererStock(Ressources *ressources)
{
    // Créer les tâches
    Tache *gestionStock = cree_tache("Gestion des stocks");

    // Sous-tâches pour gérer les stocks
    Tache *ChasserTache = cree_tache("Chasser");
    Tache *consommationNourriture = cree_tache("Consommer nourriture");

    // Ajouter des sous-tâches à la tâche principale
    ajouterSousTache(gestionStock, ChasserTache);
    ajouterSousTache(gestionStock, consommationNourriture);

    
    // Afficher l'arbre des tâches après validation
    printf("\nArbre des taches pour la gestion des stocks :\n");

    // Valider certaines tâches
    validerTache(ChasserTache, ressources);
    validerTache(consommationNourriture, ressources);

    free(gestionStock->sousTaches);
    free(gestionStock);
    free(ChasserTache);
    free(consommationNourriture);
}