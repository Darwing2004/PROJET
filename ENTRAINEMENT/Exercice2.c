#include <stdio.h>

struct ETUDIANT
{
    char nom[50];
    char prenom[50];
    unsigned age;
    float moyenne;
};

struct ETUDIANT etudiants[3];

void remplir(struct ETUDIANT *e)
{
    printf("Entrez le nom : ");
    scanf("%s", e->nom);
}

void afficher(struct ETUDIANT *e)
{
    printf("Nom : %s\n", e->nom)
}

int main()
{
    int nbr_etudiant  = 3;

    for(int i = 0; i < nbr_etudiant; i++)
    {
        printf("\nEntrez les informations pour l'étudiant %d : \n", i + 1);
        remplir(&etudiants[i]);
    }
    struct ETUDIANT e1;
    remplir(&e1);
}