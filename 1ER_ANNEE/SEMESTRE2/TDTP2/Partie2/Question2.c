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
    }
    return nombre;
}

unsigned int somme_digit(int n)
{
    int nombre = 0;
    while (n > 0)
    {
        int reste = n % 10;
        nombre = nombre + reste;
        n /= 10;
    }
    return nombre;
}

int chassez_le_9(int n)
{
    int nombre = 0;
    int position = 1;

    while (n > 0)
    {
        int reste = n % 10;
        if (reste != 9)
        {
            nombre = nombre + reste * position;
            position *= 10;
        }
        n/=10;
    }
    return nombre;
}

int chassez_le_zero(int n)
{
    int nombre = 0;
    int position = 1;

    while(n > 0)
    {
        int reste = n %   10;
        if (reste != 0)
        {
            nombre = nombre + reste * position;
            position = position * 10;
        }
        n/=10;
    }
    return nombre;
}
int main()
{
    int n = 1903;
    int m_nbr = mirroir(n);
    int s_nbr = somme_digit(n);
    int l_nbr = longueur_nbr(n);
    int c9_nbr = chassez_le_9(n);
    int c0_nbr = chassez_le_zero(n);

    printf("La longueur de %d est %d\n", n, l_nbr);
    printf("Le mirroir de %d est %d\n", n, m_nbr);
    printf("La somme des digits de %d est %d\n", n, s_nbr);
    printf("Le nombre sans 9 est %d\n", c9_nbr);
    printf("Le nombre sans 0 est %d\n", c0_nbr);
}