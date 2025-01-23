#include <stdio.h>

int OCCU(int *tab, int n, float X, int i, int result)
{
    if (i == n)
    {
        return result;
    }

    if (i < n)
    {
        if (tab[i] == X)
        {
            result++;
        }
    }

    return OCCU(tab, n, X, i + 1, result);
}

int main()
{
    float X;
    int n = 5;
    int i = 0;
    int compt = 0;

    printf("Quel nombre cherche vous ? : ");
    scanf("%f", &X);

    int tab[5] = {1, 6, 1, 4, 8};
    int result = OCCU(tab, n, X, i, compt);

    printf("%.2f est present %d fois", X, result);
}