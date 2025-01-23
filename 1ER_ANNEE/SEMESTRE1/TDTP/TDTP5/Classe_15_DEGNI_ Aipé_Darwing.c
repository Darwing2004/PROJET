#include <stdio.h>

unsigned int Longueur(unsigned int N)
{
    int i = 0;
    while (N != 0)
    {
        N = N / 10;
        i++;
    }

    printf("La longueur de l'entier est %d", i);
}

unsigned int Fréquence(unsigned int N, unsigned int d)
{
    int v = N;
    int i = 0;
    while (N != 0)
    {
        if (N % 10 == d)
        {
            N = N / 10;
            i++;
        }
        else
        {
            N = N / 10;
        }
    }
    printf("Il y a %d fois le chiffre %d dans le nombre %d", i, d, v);
}

unsigned int Decimation(unsigned int N)
{
  return -1;
}

unsigned int RemplaceImpair(unsigned int N)
{
    return -1;
}

unsigned int MiroirAddOneMod(unsigned int N)
{
    int i;
    int tab[100];

    for (i = 0; N != 0; i++)
    {
        tab[i] = N % 10 + 1;
        N = N / 10;
        printf("%d", tab[i]);
    }
}

unsigned int AddOneMod(unsigned int N)
{
    return -1;
}

void Test (unsigned int N, char S[], unsigned int d)
{
    Longueur(N);
    Fréquence(N, d);
    Decimation(N);
    RemplaceImpair(N);
    AddOneMod(N);
    MiroirAddOneMod(N);    
}
int main() {
    int a;
    int b;
    char mytab[50];
    printf("Choisis un entier:");
    scanf("%d", &a);
    printf("Choisir un entier:");

    Test(a, mytab, b);

}