#include <stdio.h>
#include <stdlib.h>

int remplir(int **tab, int nbr_v)
{
    *tab = (int *)malloc(nbr_v * sizeof(int *));

    if (*tab == NULL)
    {
        printf("ERREUR");
        return 1;
    }

    // Ajouter des valeurs
    for (int i = 0; i < nbr_v; i++)
    {
        printf("Entrer votre %d valeurs: ", i + 1);
        scanf("%d", &(*tab)[i]);
    }

    // Afficher les valeurs
    printf("Les valeurs sont : ");
    for (int i = 0; i < nbr_v; i++)
    {
        printf("%d ", (*tab)[i]);
    }

    printf("\n\n");
    return 0;
}

void somme_moy(int *tab, int nbr_v)
{
    int somme = 0;

    for(int i = 0; i < nbr_v; i++)
    {
        somme = somme + tab[i];
    }

    float moy = somme / nbr_v;

    printf("La somme des valeurs est %d\nLa moyenne des valeurs est %.2f", somme, moy);
}

int main()
{
    int nbr_v = 0;
    int *tab;

    printf("Choisissez le nombre de valeurs : ");
    scanf("%d", &nbr_v);
    remplir(&tab, nbr_v);
    somme_moy(tab, nbr_v);

    free(tab);
}