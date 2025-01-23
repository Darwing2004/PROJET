#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// On définit la structure Profil
typedef struct Profil
{
    char nom[50];
    char prenom[50];
    unsigned int age;
    char **liste_ami;
    struct Profil *suivant;
    unsigned int nbr_amis;
} Profil;

// On definit la liste
typedef struct ListeChainee
{
    Profil *premier;
    Profil *dernier;
} ListeChainee;

// On initialise la liste
ListeChainee *initialisation_liste()
{
    ListeChainee *liste = malloc(sizeof(*liste));
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }
    liste->premier = NULL;
    liste->dernier = NULL;
    return liste;
}

// Fonction qui ajoute un nom
void Ajouter_Nom(Profil *Profil)
{
    // On vérifie le pointeur profil est null
    if (Profil == NULL)
    {
        printf("ERREUR : le profil est NULL\n");
        return;
    }

    printf("Nom de l'utilisateur ? : ");
    scanf("%49s", Profil->nom);
}

void Ajouter_Prenom(Profil *Profil)
{
    // On verifie si le pointeur profil est null
    if (Profil == NULL)
    {
        printf("ERREUR : le profil est NULL\n");
        return;
    }

    printf("Prenom de l'utilisateur ? : ");
    scanf("%49s", Profil->prenom);
}

void Ajouter_Age(Profil *Profil)
{
    // On verifie si le pointeur profil est null
    if (Profil == NULL)
    {
        printf("ERREUR : le profil est NULL\n");
        return;
    }

    printf("Age de l'utilisateur ? : ");
    scanf("%d", &Profil->age);
}

unsigned int NombreTotalAmis(Profil *profil) {
    // Cas de base : Si le profil est NULL (fin de la liste), retourne 0
    if (profil == NULL) {
        return 0;
    }

    // Cas récursif : Ajoute le nombre d'amis du profil actuel
    // au nombre total d'amis des profils restants
    return profil->nbr_amis + NombreTotalAmis(profil->suivant);
}


void Liste_ami(Profil *Profil)
{
    if (Profil == NULL)
    {
        printf("ERREUR : le profil est NULL\n");
        return;
    }

    printf("Combien d'amis ? : ");
    scanf("%u", &Profil->nbr_amis);

    // On vérifie si le nombre d'amis n'est pas nul
    if (Profil->nbr_amis == 0)
    {
        Profil->liste_ami = NULL;
        return;
    }

    // Allocation du tableau de pointeur pour les amis
    Profil->liste_ami = malloc(Profil->nbr_amis * sizeof(char *));
    if (Profil->liste_ami == NULL)
    {
        return;
    }

    // Ajout des amis
    for (int i = 0; i < Profil->nbr_amis; i++)
    {
        char amis[50];
        printf("Entrez l'ID de ton pote %u : ", i + 1);
        scanf("%49s", amis);

        // Allocation de mémoire pour stocker l'ID de ton pote
        Profil->liste_ami[i] = malloc((strlen(amis) + 1) * sizeof(char));
        if (Profil->liste_ami[i] == NULL)
        {
            printf("ERREUR d'allocation pour le poto %d\n", i + 1);

            for (int j = 0; j < i; j++)
            {
                free(Profil->liste_ami[j]);
            }
            free(Profil->liste_ami);
            exit(EXIT_FAILURE);
        }

        strcpy(Profil->liste_ami[i], amis);
    }
}

void Liberer_amis(Profil *Profil)
{
    if (Profil == NULL || Profil->liste_ami == NULL)
        return;

    for (int i = 0; i < Profil->nbr_amis; i++)
    {
        free(Profil->liste_ami[i]);
    }
    free(Profil->liste_ami);
}

// Fonction qui permet de créer une liste chainée de profils
void Ajouter_Profil(ListeChainee *liste)
{
    // Nettoyage de la console
    system("cls");

    printf("***********************************************\n");
    printf("***************AJOUT D'UN PROFIL***************\n");
    printf("***********************************************\n");

    // Allocation du nouveau profil
    Profil *nouveau = malloc(sizeof(*nouveau));
    if (liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }

    nouveau->suivant = NULL;

    // Ajout d'un nom
    Ajouter_Nom(nouveau);

    // Ajout d'un prenom
    Ajouter_Prenom(nouveau);

    // Ajout de l'age
    Ajouter_Age(nouveau);

    // Liste d'amis
    Liste_ami(nouveau);

    if (liste->premier == NULL)
    {
        liste->premier = nouveau;
    }
    else
    {
        Profil *temp = liste->premier;
        while (temp->suivant != NULL)
        {
            temp = temp->suivant;
        }
        temp->suivant = nouveau;
    }
}

void Afficher_Profil(ListeChainee *liste)
{
    printf("****************LISTE DES PROFILS****************\n");
    int compt = 1;
    if (liste == NULL || liste->premier == NULL)
    {
        printf("La liste est vide. \n");
        return;
    }

    Profil *temp = liste->premier;
    while (temp != NULL)
    {
        printf("*********Profil %d*********\n", compt++);
        printf("Nom : %s\n", temp->nom);
        printf("Prenom : %s\n", temp->prenom);
        printf("Age = %d\n", temp->age);

        if (temp->nbr_amis == 0)
        {
            printf("Pas d'amis\n");
        }
        else
        {
            printf("Liste d'amis : \n");
            for (int i = 0; i < temp->nbr_amis; i++)
            {
                printf("  ID : %s\n", temp->liste_ami[i]);
            }
        }

        temp = temp->suivant;
        printf("\n");
    }
}

void freeMemoryList(ListeChainee *liste)
{
    if (liste == NULL)
    {
        return;
    }

    Profil *temp = liste->premier;
    while (temp != NULL)
    {
        Profil *aSupprimer = temp;
        temp = temp->suivant;

        Liberer_amis(aSupprimer);
        free(aSupprimer);
    }

    free(liste);
}

void Supprimer_Profil(ListeChainee *liste)
{
    Afficher_Profil(liste);

    if (liste == NULL || liste->premier == NULL)
    {
        printf("ERREUR : la liste est vide ou le profil est NULL\n");
        return;
    }

    char nom[50];
    char prenom[50];

    printf("Veuillez entrez le nom du profil a supprimer : ");
    scanf("%49s", nom);
    printf("Veuillez entrez le prenom du profil a supprimer : ");
    scanf("%49s", prenom);

    Profil *temp = liste->premier;
    Profil *precedent = NULL;

    while (temp != NULL)
    {
        if (strcmp(temp->nom, nom) == 0 && strcmp(temp->prenom, prenom) == 00)
        {
            if (precedent == NULL)
            {
                liste->premier = temp->suivant;
                if (temp == liste->dernier)
                {
                    liste->dernier = NULL;
                }
            }
            else
            {
                precedent->suivant = temp->suivant;
                if (temp == liste->dernier)
                {
                    liste->dernier = precedent;
                }
            }

            Liberer_amis(temp);
            free(temp);
            printf("Le profil '%s %s' a ete supprimee.\n", nom, prenom);
            return;
        }

        precedent = temp;
        temp = temp->suivant;
    }

    printf("Le profil '%s %s' n'a pas ete trouve dans la liste\n", nom, prenom);
}

void Recherche_Profil(ListeChainee *liste)
{
    if (liste == NULL || liste->premier == NULL)
    {
        printf("ERREUR : la liste est vide ou le profil est NULL\n");
        return;
    }

    char nom[50];
    char prenom[50];

    printf("Veuillez entrez le nom du profil a recherche : ");
    scanf("%49s", nom);
    printf("Veuillez entrez le prenom du profil a rechercher : ");
    scanf("%49s", prenom);

    Profil *temp = liste->premier;

    while (temp != NULL)
    {
        if (strcmp(temp->nom, nom) == 0 && strcmp(temp->prenom, prenom) == 0)
        {
            printf("*********PROFIL TROUVE*********\n");
            printf("Nom : %s\n", temp->nom);
            printf("Prenom : %s\n", temp->prenom);
            printf("Age = %d\n", temp->age);
            printf("Liste d'amis : \n");
            for (int i = 0; i < temp->nbr_amis; i++)
            {
                printf("  ID : %s\n", temp->liste_ami[i]);
            }
            return;
        }
        temp = temp->suivant;
    }
    printf("Le profil '%s %s' n'a pas ete trouve dans la liste\n", nom, prenom);
}

void CalculerNombreTotalAmis(ListeChainee *liste) {
    if (liste == NULL || liste->premier == NULL) {
        printf("La liste est vide.\n");
        return;
    }

    unsigned int totalAmis = NombreTotalAmis(liste->premier);
    printf("Le nombre total d'amis dans le reseau est : %u\n", totalAmis);
}

void AfficherUtilisateursEtAmis(ListeChainee *liste) {
    if (liste == NULL || liste->premier == NULL) {
        printf("La liste est vide. Aucun utilisateur a afficher.\n");
        return;
    }

    Profil *temp = liste->premier; // Pointeur pour parcourir la liste
    int compteur = 1;

    while (temp != NULL) {
        printf("******** UTILISATEUR %d ********\n", compteur++);
        printf("Nom : %s\n", temp->nom);
        printf("Prenom : %s\n", temp->prenom);
        printf("Age : %d\n", temp->age);

        3+.

        if (temp->nbr_amis == 0) {
            printf("Amis : Aucun ami enregistre.\n");
        } else {
            printf("Amis :\n");
            for (unsigned int i = 0; i < temp->nbr_amis; i++) {
                printf("  - %s\n", temp->liste_ami[i]);
            }
        }

        printf("\n"); // Ligne vide pour séparer les utilisateurs
        temp = temp->suivant; // Passer au prochain profil
    }
}



void Menu_principale(ListeChainee *liste)
{
    int choix;

    do
    {
        printf("************************************************************************\n");
        printf("*****************************MENU PRINCIPAL*****************************\n");
        printf("************************************************************************\n");
        printf("[1] AJOUTER UN PROFIL\n");
        printf("[2] AFFICHER LES PROFILS\n");
        printf("[3] SUPPRIMER UN PROFIL\n");
        printf("[4] RECHERCHER UN PROFIL\n");
        printf("[5] NOMBRE D'AMIS TOTAL\n");
        printf("[6] AFFICHER UTILISATEURS ET LEURS AMIS\n");
        printf("[7] QUITTER\n");

        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            Ajouter_Profil(liste);
            system("cls");
            break;
        case 2:
            Afficher_Profil(liste);
            break;
        case 3:
            Supprimer_Profil(liste);
            system("cls");
            break;
        case 4:
            Recherche_Profil(liste);
            system("cls");
            break;
        case 5:
            CalculerNombreTotalAmis(liste);
            break;
        case 6:
            AfficherUtilisateursEtAmis(liste);
            break;
        default:
            printf("Choix invalide. Veuillez réessayer.\n");
        }

    } while (choix != 7);
}

int main()
{
    ListeChainee *liste = initialisation_liste();
    Menu_principale(liste);
    freeMemoryList(liste);

    return 0;
}
