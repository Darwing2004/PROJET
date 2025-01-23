#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Etudiant
{
    char nom[50];
    char prenom[50];
    int age;
    float moyenne;
    struct Etudiant *suivant; // Pointeur vers l'étudiant suivant
} Etudiant;

typedef struct Listechainnee
{
    Etudiant *premier;
    Etudiant *dernier;
} Listechainnee;

Listechainnee *initialisation_liste()
{
    Listechainnee *liste = malloc(sizeof(*liste));
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }
    liste->premier = NULL;
    liste->dernier = NULL;

    return liste;
}

void Ajouter_nom(Etudiant *Etudiant)
{
    if (Etudiant == NULL) // Vérifie si la structure Etudiant existe
    {
        printf("ERREUR: Le pointeur profil est null, il n'y a pas de structure Etudiant\n");
        exit(EXIT_FAILURE);
    }
    printf("Entrez le nom de l'etudiant :");
    scanf("%49s", Etudiant->nom);
}

void Ajouter_prenom(Etudiant *Etudiant)
{
    if (Etudiant == NULL) // Vérifie si la structure Etudiant existe
    {
        printf("ERREUR: Le pointeur profil est null, il n'y a pas de structure Etudiant\n");
        exit(EXIT_FAILURE);
    }

    printf("Entrez le prenom de l'etudiant :");
    scanf("%49s", Etudiant->prenom);
}

void Ajouter_age(Etudiant *Etudiant)
{
    if (Etudiant == NULL) // Vérifie si la structure Etudiant existe
    {
        printf("ERREUR: Le pointeur profil est null, il n'y a pas de structure Etudiant\n");
        exit(EXIT_FAILURE);
    }

    printf("Entrez l'age de l'etudiant :");
    scanf("%d", &Etudiant->age);
}

void Ajouter_moyenne(Etudiant *Etudiant)
{
    if (Etudiant == NULL) // Vérifie si la structure Etudiant existe
    {
        printf("ERREUR: Le pointeur profil est null, il n'y a pas de structure Etudiant\n");
        exit(EXIT_FAILURE);
    }

    printf("Entrez la moyenne de l'etudiant : ");
    scanf("%f", &Etudiant->moyenne);
}

void Liberer_memory(Listechainnee *liste)
{
    if (liste == NULL)
        return;

    Etudiant *temp = liste->premier;
    while (temp != NULL)
    {
        Etudiant *a_supprimer = temp;
        temp = temp->suivant;
        free(a_supprimer);
    }

    free(liste);
}

void Ajouter_etudiant(Listechainnee *liste)
{
    Etudiant *nouveau = malloc(sizeof(*nouveau));
    if (liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }

    nouveau->suivant = NULL;

    // On appelle les fonction afin d'ajouter les caractéristique de l'étudiant

    Ajouter_nom(nouveau);
    Ajouter_prenom(nouveau);
    Ajouter_age(nouveau);
    Ajouter_moyenne(nouveau);

    // On place le nouveau étudiant à la fin de la liste
    if (liste->premier == NULL)
    {
        liste->premier = nouveau;
    }
    else
    {
        Etudiant *temp = liste->premier;
        while (temp->suivant != NULL)
        {
            temp = temp->suivant;
        }

        temp->suivant = nouveau;
    }
}

void Afficher_étudiant(Listechainnee *liste)
{
    // On teste d'abord si la liste n'est pas vide
    if (liste == NULL || liste->premier == NULL)
    {
        printf("La liste est vide");
        return;
    }

    // On crée une liste temporaire pour la travérer et un compteur pour l'affichage
    Etudiant *temp = liste->premier;
    int compteur_e = 1;

    while (temp != NULL)
    {
        printf("**ETUDIANT %d**\n", compteur_e);
        printf("nom : %s\n", temp->nom);
        printf("prenom : %s\n", temp->prenom);
        printf("age : %d\n", temp->age);
        printf("Moyenne : %.2f\n", temp->moyenne);
        printf("\n");

        temp = temp->suivant;
        
    }
}

void Meilleure_étudiant(Listechainnee *liste)
{
    if (liste == NULL || liste->premier == NULL)
    {
        printf("la liste est vide");
        return;
    }

    float best_moy = 0;
    Etudiant *temp = liste->premier;

    while (temp != NULL)
    {
        if (best_moy < temp->moyenne)
        {
            best_moy = temp->moyenne;
        }

        temp = temp->suivant;
    }

    temp = liste->premier;

    while (temp != NULL)
    {
        if (best_moy == temp->moyenne)
        {
            printf("L'Etudiant avec la meilleure moyenne est : \n");
            printf("nom : %s\n", temp->nom);
            printf("prenom : %s\n", temp->prenom);
            printf("age : %d\n", temp->age);
            printf("Moyenne : %.2f\n", temp->moyenne);
        }

        temp = temp->suivant;
    }
}

void Menue_principale(Listechainnee *liste)
{
    int choix = 0;

    do
    {
        printf("*******MEILLEUR ETUDIANT*******\n");
        printf("1. Ajouter un etudiant\n");
        printf("2. Afficher les etudiant\n");
        printf("3. Meilleur etudiant\n");
        printf("4. Quitter\n");
        printf("Votre choix : ");

        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            Ajouter_etudiant(liste);
            break;
        case 2:
            Afficher_étudiant(liste);
            break;
        case 3:
            Meilleure_étudiant(liste);
            break;
        case 4:
            break;
        default:
            printf("CHOIX INVALIDE : reessayer");
        }
    } while (choix != 4);
}

int main()
{
    Listechainnee *liste = initialisation_liste();
    Menue_principale(liste);

    // Libération de la mémoire allouée
    Liberer_memory(liste);
    liste = NULL;

    return 0;
}