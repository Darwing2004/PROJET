#include <stdio.h>

int DICHREC(int *tab, int X, int D, int G)
{
    if (D >= G)
    {
        int M = G + D / 2;

        if (tab[M] == X)
        {
            return M;
        }

        if (tab[M] > X)
        {
            return DICHREC(tab, X, M - 1, G);
        }

        return DICHREC(tab, X, D, M + 1);
    }

    return -1;
}

int main()
{
    int n = 10;
    int tab[] = {2, 4, 6, 8, 9, 12, 46, 52, 55, 67};
    int X = 12;

    int result = DICHREC(tab, X, n, 0);

    printf("L'element est a l'indice %d", result);
}