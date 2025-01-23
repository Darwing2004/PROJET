#include <stdio.h>

void inverse(int *tab, int n)
{
    int *p1 = tab;

    int *p2 = tab + (n - 1);


    for (int i = 0; i < n; i++)
    {
        printf("%d\n", *p1);

        printf("%d\n", *p2);

        *p1 = *(p1 + 1);
        *p2 = *(p2 - 1);
    }
}

int main()
{
    int n = 10;
    int tab[10] = {1, 5, 6, 8, 7, 2, 3, 8, 1, 12};
    int *p = tab;

    /*printf("AVANT\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(p + i));
    }*/

    inverse(tab, n);

    /*printf("\nAPRES\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(p + i));
    }*/
}