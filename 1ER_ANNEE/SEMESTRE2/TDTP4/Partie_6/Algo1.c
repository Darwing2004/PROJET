#include <stdio.h>
#include <math.h>

float Puissance_Modulaire(float g, int e)
{
    if (e == 1)
    {
        return g;
    }
    if (e % 2 == 0)
    {
        return Puissance_Modulaire(g*g, e/ 2);
    }
    else
    {
        return g * Puissance_Modulaire((g*g), (e-1)/2);
    }
}

int main (){
    float a = 6;
    int e = 2;

    int puissance = Puissance_Modulaire(a, e);

    printf("%d", puissance);
}
