#include <stdio.h>
#include <math.h>

// mettre tiret lm
int equation_2(int a, int b, int c)
{
    // Calcule du discriminant
    int D = (b * b) - 4 * a * c;
    int x1, x0, x2;
    printf("Le discriminant est %d\n", D);

    if (D < 0)
    {
        printf("Le discriminant est negatif: PAS DE SOLUTION\n");
        return 0;
    }
    else if (D == 0)
    {
        printf("Le discriminant est nul, on a qu'une solution:\n");

        if (a == 0)
        {
            x0 = 0;
        }
        else
        {
            x0 = (-1 * b / (2 * a));
        }

        printf("La solutions est %d", x0);
    }
    else if (D > 0)
    {
        printf("Le discriminant est positif, on a deux solution:\n");

        x1 = (-1 * b + sqrt(D)) / 2 * a;
        x2 = (-1 * b - sqrt(D)) / 2 * a;

        printf("Les solutions sont %d et %d", x1, x2);
    }
    return 0;
}

int main()
{
    int a, b, c;

    printf("Entrez votre équation:\n");
    printf("Choisissez a:");
    scanf("%d", &a);

    printf("Choisissez b:");
    scanf("%d", &b);

    printf("Choisissez c:");
    scanf("%d", &c);

    equation_2(a, b, c);
}