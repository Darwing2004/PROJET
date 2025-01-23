#include <stdio.h>

int max3(int a, int b, int c)
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

    if (c > max)
    {
        max = c;
    }
    return max;
}

int main()
{
    int x;
    int y;
    int z;

    printf("Choisis la premiere valeur:");
    scanf("%d", &x);
    printf("choisis la deuxieme valeur:");
    scanf("%d", &y);
    printf("Choisis la troisieme valeur:");
    scanf("%d", &z);

    int result = max3(x, y, z);
    printf("Le maximum est %d", result);
}