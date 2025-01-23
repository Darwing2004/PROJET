#include <stdio.h>

int main()
{
    int nbr_l;
    int i = 0;
    int j = 0;

    printf("nombre de ligne:");
    scanf("%d", &nbr_l);

    for (i = 0; i < nbr_l; i++)
    {
        j = nbr_l;

        while (i < j)
        {
            printf("*");
            j--;
        }
        j = nbr_l;
        printf("\n");
    }
}