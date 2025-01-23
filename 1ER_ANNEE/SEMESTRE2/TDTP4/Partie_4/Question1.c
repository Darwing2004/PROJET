#include <stdio.h>
#include <stdlib.h>

unsigned int min_TAB(int *tab, int n, int k) // int tab[] <=> int * : Un tableau est un pointeur
{

    int min = tab[0];
    int temp, compt;
    while (compt < k)
    {
        for (int i = 0; i < n; i++)
        {
            if (tab[i] < min)
            {
                min = tab[i];
            }
        }
        compt++;
    }
    return temp;
}

int Recherche_Dicho(int *tab, int n, int ELT)
{
    int D = n;
    int G = 0;
    int M;

    while (D >= G)
    {
        M = (G + D) / 2;
        if (ELT < tab[M])
        {
            D = M - 1;
        }
        else
        {
            G = M + 1;
        }
        if (tab[M] == ELT)
        {
            return M;
        }
    }
    return -1;
}

int main()
{
    int elt = 6;
    int n = 3;
    int k = 2;
    int tab[10] = {5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

    int min = min_TAB(tab, n, k);
    printf("Le plus petit nombre est %d\n", min);

    int indice = Recherche_Dicho(tab, n, elt);
    printf("%d est a l'indice %d\n", elt, indice);
}