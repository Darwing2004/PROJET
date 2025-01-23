#include <stdio.h>
#define Nlong 10

int monTableau[Nlong] = {9, 6, -10, 7, 9, 4, 5, 12, -4, };
int ElementIndex;
int ElementValue;

int Chercher3(int T[])
{
    int i;
    for (i = 0; i < 10; i++)
    {
        if (monTableau[i] == 3)
        {
            ElementIndex = 3;
        }
        else
        {
            ElementIndex = -1;
        }
    }
}

int main()
{
    Chercher3(monTableau);
    printf("%d", ElementIndex);
    return 0;
}