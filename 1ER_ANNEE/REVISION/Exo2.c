#include <stdio.h>

int main ()
{
    int nbr_table;
    printf("Quel table de multiplication voulez-vous ? : ");
    scanf("%d", &nbr_table);

    for(int i = 0; i < 11; i++)
    {
        int result = nbr_table * i;
        printf("%d x %d = %d\n", nbr_table, i, result);
    }

}