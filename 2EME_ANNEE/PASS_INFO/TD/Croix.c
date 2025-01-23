#include <stdio.h>

int main()
{
    int nbr_l;
    int nbr_c;
    int i = 0;
    int j = 0;

    printf("nombre de colonnes:");
    scanf("%d", &nbr_c);
    printf("nombre de lignes:");
    scanf("%d", &nbr_l);

    for (i = 0; i < nbr_l; i++)
    {
        while (j < nbr_c)
        {
            if ((i + j == nbr_c - 1) || i == j)
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
            j++;
        }
        printf("\n");
        j = 0;
    }
}