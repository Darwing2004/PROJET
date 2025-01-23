#include <stdio.h>

unsigned int longueur_nbr(int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        n = n * -1;
    }
    int compt = 0;
    while (n > 0)
    {
        n /= 10;
        compt++;
    }

    return compt;
}

int mirroir(int n)
{
    int nombre = 0;
    while (n > 0)
    {
        int reste = n % 10;
        nombre = nombre * 10 + reste;
        n /= 10;
        printf("%d <-------------> %d\n", n, nombre);
    }
    return nombre;
}
int main()
{
    int n = 123;
    mirroir(n);
}