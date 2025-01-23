#include <stdlib.h>
#include <stdio.h>

char affrontement(char val, char val2)
{
    if (val == 'C' && val2 == 'P')
    {
        return val2;
    }
    if (val == 'P' && val2 == 'C')
    {
        return val;
    }
}

void tournoi(char tab[])
{
    int j = 0;
    int taille = 8;
    while (taille > 1)
    {
        for (int i = 0; i < taille; i++)
        {
            tab[j] = (tab[i], tab[i + 1]);
            j++;
        }
        j++;
    }

    printf("%s", tab);
}

int main() {

    char tab[] = "CPFFPC";
    tournoi(tab);
}