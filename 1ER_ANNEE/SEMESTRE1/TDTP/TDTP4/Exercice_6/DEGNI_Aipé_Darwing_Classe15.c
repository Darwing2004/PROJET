#include <stdio.h>

int main()
{
    int nbr_l;
    int nbr_c;
    int i = 0;
    int j = 0;

    printf("nombre de ligne:");
    scanf("%d", &nbr_l);
    printf("nombre de colonne:");
    scanf("%d", &nbr_c);

    for (i = 0; i < nbr_l; i++)
    {
        do
        {
            printf("* ");
            j++;
        } while (j < nbr_c);
        j = 0;
        printf("\n");
    }
}