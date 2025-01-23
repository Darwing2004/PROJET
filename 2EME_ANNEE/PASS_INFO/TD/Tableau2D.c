#include <stdio.h>

int somme(int tab[3][3])
{

    int i, j;
    int k = 0;
    int result = 0;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            k = k + tab[i][j];
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }

    return k;
}

int main()
{
    int tab[3][3] = {{1, 1, 1}, {1, 3, 2}, {1, 6, 5}};

    int result = somme(tab);

    printf("La somme est %d", result);

}