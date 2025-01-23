#include <stdio.h>

int deplace_negatif(int *tab, int n)
{
    for (int i = 0; i < n; i++)
    {

        if (tab[i] < 0)
        {
            int temp = tab[i];
            tab[i] = tab[i + 1];
            tab[i + 1] = temp;
        }
    }
}

int main()
{
    int n = 10;

    int tab[] = {-74, 98, 58, -8, 7, 1, -6, 4, -58, 478};

    printf("tab = ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", tab[i]);
    }
}