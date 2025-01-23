#include <stdio.h>

int tri_negatif(int *tab, int n)
{
    int negatif = 0;
    int temp;

    for (int i = 0; i <= n; i++)
    {
        if (tab[i] < 0)
        {
            temp = tab[i];
            tab[i] = tab[negatif];
            tab[negatif] = temp;
            negatif++;
        }
    }
    return negatif;
}

int main()
{
    int n = 10;
    int tab[10] = {-1, 3, -4, -3, 6, 9, 7, -9, 9, -15};
    int negatif = tri_negatif(tab, n);

    printf("tab = ");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", tab[i]);
    }

    printf("\nnbr de negatif : %d", negatif);
}