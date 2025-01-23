#include <stdio.h>

int main()
{
    int a, b, i;

    int nbr = 0;

    printf("choose a:");
    scanf("%d", &a);

    printf("choose b:");
    scanf("%d", &b);

    for (i = a; i < b + 1; i++)
    {
        if (i % 2 == 0)
        {
            nbr = nbr + i;
        }
    }

    printf("La somme des nombres paires est %d\n", nbr);
}