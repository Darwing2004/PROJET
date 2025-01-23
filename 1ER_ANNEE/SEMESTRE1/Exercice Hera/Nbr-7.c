#include <stdio.h>

int nbr(int seven)
{
    int i;
    int j;
    do
    {
        if (seven % 10 == 7)
        {
            j++;
            seven = seven / 10;
        }
        else
        {
            seven = seven / 10;
        }
    } while (seven != 0);
    return j;
}

int main()
{
    int a;

    printf("Nombre:");
    scanf("%d", &a);

    int result = nbr(a);
    printf("Il y a %d nombre(s) de 7 dans %d", result, a);
}