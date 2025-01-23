#include <stdio.h>

float Racine_Carre(int n, float e)
{
    float a = 0;
    float b = n;
    float m = 0;

    while ((b - a) > e) // test de la question 3 chef ! //
    {
        if (m * m < n)
        {
            a = m;
        }
        else
        {
            b = m;
        }
        m = m + e; // On ajoute e pour avancer tout simple !
    }
    return m;
}
int main()
{
    int c = Racine_Carre(4, 0.1);

    printf("nbr = %d", c);

}