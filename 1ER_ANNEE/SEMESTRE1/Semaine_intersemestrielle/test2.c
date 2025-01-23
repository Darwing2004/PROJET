#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int tableau(int tab[], int n)
{
    srand(time(NULL));
    int temp;

    for (int i = 0; i < n; i++)
    {
        do
        {
            tab[i] = rand() % 7;
            temp = 0;
            for (int j = 0; j < i; j++)
            {
                if (tab[i] == tab[j])
                {
                    temp = 1;
                    break;
                }
            }
        } while (temp);
    }

    for (int i = 0;i < n; i++)
    {
        printf("%d ", tab[i]);
    }
}

int main()
{
    int v = 7;
    int perm[v];
    tableau(perm, v);

}