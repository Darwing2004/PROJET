#include <stdio.h>

int comp(int a, int b)
{
    int max;
    if (a < b)
    {
        max = b;
    }
    else
    {
        max = a;
    }
    return max;
}

int main()
{
    int x;
    int y;
    printf("Choisis la première valeur:");
    scanf("%d", &x);
    printf("choisi la deuxieme valeur:");
    scanf("%d", &y);
    int result = comp(x, y);
    printf("%d", result);
}
