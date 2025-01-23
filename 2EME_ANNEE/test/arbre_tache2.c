#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nom_tache[50];
    int fourmis_necessaire;
    int fourmis_assigne;
    struct Arbre_tache *enfant;
    struct Arbre_tache *frere;
} Arbre_tache;

Arbre_tache *creation_noeud_tache(const char *name, int antsNeeded)
{
    Arbre_tache *Nv_noeud = (Arbre_tache *)malloc(sizeof(Arbre_tache));
    if (Nv_noeud == NULL)
    {
        printf("ERREUR : allocation memoire echoue !\n");
        exit(1);
    }
    strcpy(Nv_noeud->nom_tache, name);
    Nv_noeud->fourmis_necessaire = antsNeeded;
    Nv_noeud->fourmis_assigne = 0;
    Nv_noeud->enfant = NULL;
    Nv_noeud->frere = NULL;

    return Nv_noeud;
}

void ajouter_sous_tache(Arbre_tache *parent, Arbre_tache *child)
{
    if (parent->enfant == NULL)
    {
        parent->enfant = child; // Correction cruciale : assigner l'enfant au parent
    }
    else
    {
        Arbre_tache *frere_courant = parent->enfant;
        while (frere_courant->frere != NULL)
        {
            frere_courant = frere_courant->frere;
        }
        frere_courant->frere = child;
    }
}

void afficher_tache(Arbre_tache *noeud, int profondeur)
{
    if (noeud == NULL)
    {
        return;
    }

    for (int i = 0; i < profondeur; i++)
    {
        printf("  "); // Ajout d'espaces pour l'indentation
    }
    printf("- %s (Fourmi dont on a besoin: %d, Fourmi assigné: %d)\n", noeud->nom_tache, noeud->fourmis_necessaire, noeud->fourmis_assigne);

    afficher_tache(noeud->enfant, profondeur + 1); // Afficher les enfants avec une profondeur accrue
    afficher_tache(noeud->frere, profondeur);     // Afficher les frères avec la même profondeur
}

int main()
{
    Arbre_tache *racine = creation_noeud_tache("Collecte de nourriture", 5);

    Arbre_tache *sous_tache1 = creation_noeud_tache("Trouver une source de nourriture", 3);
    Arbre_tache *sous_tache2 = creation_noeud_tache("Transporter la nourriture au nid", 3);

    ajouter_sous_tache(racine, sous_tache1);
    ajouter_sous_tache(racine, sous_tache2);

    printf("Arbre de taches :\n");
    afficher_tache(racine, 0);

    // Libération de la mémoire (important pour éviter les fuites de mémoire)
    free(sous_tache2); //Libérer en ordre inverse de la création
    free(sous_tache1);
    free(racine);

    return 0;
}