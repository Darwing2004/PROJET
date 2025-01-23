#include <stdio.h>

unsigned int somme_M13(unsigned int G, unsigned int D)
{
    int somme = 0;
    int compt = G;

    while (compt < D)
    {
        if (compt % 13 == 0)
        {
            somme = somme + compt;

            compt++;
        }
        if (D % 13 == 0)
        {
            somme = somme + D;
        }
        return somme;
    }
}

unsigned int somme_M13_R(unsigned int G, unsigned int D)
{
    int somme = G;
    if (G > D)
    {
        return somme;
    }
    if (somme % 13 == 0)
    {
        return somme_M13_R(somme = somme + G, D);
    }
    
}

int main()
{
    int G = 1;
    int D = 50;

    int nbr = somme_M13_R(G, D);

    printf("La somme = %d", nbr);
}