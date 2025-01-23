#include <stdio.h>

int main()
{
    // Déclaration de variable//
    int nbr_l;
    int nbr_c;
    int i = 0;
    int j = 0;

    // On demande à l'utilisateur de choisir le nombre de lignes et de colonnes//
    printf("nombre de ligne:");
    scanf("%d", &nbr_l);
    printf("nombre de colonne:");
    scanf("%d", &nbr_c);

    for (i = 0; i < nbr_l; i++)
    {
        for (j = 0; j < nbr_c; j++)
        {
            if (i == 0 || j == 0 || i == nbr_l - 1 || j == nbr_c - 1)
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}