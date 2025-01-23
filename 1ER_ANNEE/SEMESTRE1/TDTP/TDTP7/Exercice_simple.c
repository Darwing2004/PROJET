#include <stdio.h>
#define Nlong 10

int monTableau[Nlong] = {9, 6, -10, 7, 9, 3, 5, 12, -4, 8};
int ElementIndex;
int ElementValue;

void affichage_tab(int TAB[10])
{
    for (ElementIndex = 0; ElementIndex < 10; ElementIndex++)
    {
        printf("TAB[%d]\n", TAB[ElementIndex]);
    }
}

int main()
{
    affichage_tab(monTableau);
    return 0;
}
