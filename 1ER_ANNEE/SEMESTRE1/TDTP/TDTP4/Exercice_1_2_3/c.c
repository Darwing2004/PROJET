#include <stdio.h>

int signe(int a)
{
    if (a % 2 == 0)
    {
        printf("a est pair");
    }
    else
    {
        printf("a est impair");
    }
    return 0;
}

int main()
{
    int x;

    printf("Choisis la valeur de a:");
    scanf("%d", &x);

    signe(x);
}