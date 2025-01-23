#include <stdio.h>
#include <stdlib.h>

typedef struct Livre
{
    char titre[100];
    char auteur[100];
    int annee;
    char ISBN[20]; // Code ISBN unique
    struct Livre *suivant;
} Livre;

typedef struct Listechainnee
{
    Livre *premier;
    Livre *dernier;
} Listechainnee;

Listechainnee *initialisation()
{
    Listechainnee *liste = malloc(sizeof(*liste)); 
    if (liste == NULL)
    {
        printf("ERREUR");
        exit(EXIT_FAILURE);
    }

    liste->premier = NULL;
    liste->dernier = NULL;

    return liste;
}

void Ajouter_titre(Livre *Livre)
{
    if(Livre == NULL)
    {
        printf("ERREUR : La structure n'existe pas");
        exit(EXIT_FAILURE);
    }

    printf("Entrez le titre du livre : ");
    scanf("%99s", Livre->titre);
}

void Ajouter_auteur(Livre *Livre)
{
    if(Livre == NULL)
    {
        printf("ERREUR : La structure n'existe pas");
        exit(EXIT_FAILURE);
    }

    printf("Entrez l'auteur du livre : ");
    scanf("%99s", Livre->auteur);
}

void Ajouter_annee(Livre *Livre)
{
    if(Livre == NULL)
    {
        printf("ERREUR : La structure n'existe pas");
        exit(EXIT_FAILURE);
    }

    printf("Entrez l'annee du livre : ");
    scanf("%99s", Livre->annee);
}

void Ajouter_ISBN(Livre *Livre)
{
    if(Livre == NULL)
    {
        printf("ERREUR : La structure n'existe pas");
        exit(EXIT_FAILURE);
    }

    printf("Entrez l'ISBN du livre");
    scanf("%19s", Livre->ISBN);
}


void Ajouter_livre(Listechainnee *liste)
{
    Livre *nouveau = malloc(sizeof(*nouveau));

    if(liste == NULL || nouveau == NULL)
    {
        printf("ERREUR");
        exit(EXIT_FAILURE);
    }
    
    nouveau->suivant = NULL;

    Ajouter_titre(nouveau);
    Ajouter_auteur(nouveau);
    Ajouter_annee(nouveau);
    Ajouter_ISBN(nouveau);

    if(liste->premier == NULL)
    {
        liste->premier = nouveau
    }
    else
    {
        Livre *temp = liste->premier;
        while(temp->suivant != NULL)
        {       
            temp = temp->suivant;
        }

        temp->suivant = nouveau;
    }   
}

void afficher_livre(Listechainnee *liste)
{
    if(liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Livre *temp = liste->premier;
    int compteur = 1;

    while(temp != NULL)
    {
        printf("****** LIVRE %S ******\n", compteur++);
        printf("Titre : %s", temp->titre);
        printf("")
    }
}