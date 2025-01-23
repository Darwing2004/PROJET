#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int nombre_secret(int nbr)
{
    srand(time(NULL));
    int nbgen = rand() % 10 + 1;
}
int main()
{
    int nbr;
    int nbr_c;
    int nbr_s = nombre_secret(nbr);

    printf("Recherche de nombre secret entre 1 et 10\n");

    while (nbr_s != nbr_c)
    {
        printf("Choisis un nombre entre 1 et 10 : ");
        scanf("%d", &nbr_c);
        if (nbr_c < nbr_s)
        {
            printf("Le nombre secret est plus grand\n");
        }
        else
        {
            printf("Le nombre secret est plus petit\n");
        }
    }

    printf("Le nombre secrete est %d", nbr_c);

    return 0;
}
