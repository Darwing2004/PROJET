#include <stdio.h>

int main()
{
    int a;
    int b;

    printf("Choisis la valeur de a:");
    scanf("%d", &a);
    printf("Choisis la valeur de b:");
    scanf("%d", &b);

    if (a > b)
    {
        printf("a est plus grand que b\n");
    }
    else
    {
        printf("b est plus grand que a\n");
    }

    int diff = a - b;

    printf("La différence entre a et b est %d", diff);
}