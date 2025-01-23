#include <stdio.h>
#include <stdbool.h>

bool duplication(int *tab, int n)
{
    int i, j, k;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (tab[i] == tab[j] && i != j)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n = 5;
    int tab[] = {3, 3, 2, 5, 9};
    printf("RESULT=");
    printf("%s\n", duplication(tab, n) ? "true" : "false");
}