#include <stdio.h>
#include <math.h>

float power(float a, int E)
{
    if (E == 1)
    {
        return a;
    }
    if (E == 0)
    {
        return 1;
    }
    if (E % 2 == 0)
    {
        return power(a * a, E / 2);
    }
    else
    {
        return a * power((a * a), (E - 1) / 2);
    }
}


int main()
{
    float a = 56;
    int E = 1;

    int puissance = power(a, E);
    printf("%.2f puissance %d =  %d\n", a, E, puissance);

}