#include <stdio.h>

int minimum_val(int *tab, int n)
{
    int min = tab[0];
    for (int i = 1; i <= n - 1; i++)
    {
        if (tab[i] < min)
        {
            min = tab[i];
        }
    }
    return min;
}

int maximum_val(int *tab, int n)
{
    int max = tab[0];
    for (int i = 1; i < n - 1; i++)
    {
        if (tab[i] > max)
        {
            max = tab[i];
        }
    }
    return max;
}

int minimum_ind(int *tab, int n)
{
    int IndMin = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        if(tab[i] < tab[IndMin])
        {
            IndMin = i;
        }
    }
    return IndMin;
}

int maximum_ind(int *tab, int n)
{
    int IndMax = 0;
    for(int i = 1; i <= n -1; i++)
    {
        if(tab[i] > tab[IndMax])
        {
            IndMax = i;
        }
    }
    return IndMax;
}

int min_max(int *tab, int n)
{
    int min;
    int max;
    if(tab[0] < tab[1])
    {
        min = tab[0];
        max = tab[1];
    }
    else
    {
        min = tab[1];
        max = tab[0];
    }

    for(int i = 2; i < n-1;i++)
    {
        if(tab[i] < min)
        {
            min = tab[i];
        }
        else if(tab[i] > max)
        {
            max = tab[i];
        }
    }
    return (min max);
}

int main()
{
    int tab[10] = {12, 2, 3, 0, 7, 9, 2, 6, 7, 3};
    int n = 10;

    printf("tab = ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", tab[i]);
    }

    int min = minimum_val(tab, n);
    int max = maximum_val(tab, n);
    int min_ind = minimum_ind(tab, n);
    int max_ind = maximum_ind(tab, n);

    printf("\nmin = %d", min);
    printf("\nmax = %d", max);
    printf("\nmin_ind = %d", min_ind);
    printf("\nmax_ind = %d", max_ind);

    int max_min = min_max(tab, n);

    printf("\nmin = %d", max_min);
}