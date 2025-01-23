#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int find_pic(int *tab, int n)
{
    if(n == 1) return tab[0];

    if(tab[0] >= tab[1]) return tab[0];

    if(tab[n-1] >= tab(n-2)) return tab[n-1];

    for(int i = 1; i < n-1; i++)
    {
        if(tab[i] >= tab[i-1] && tab[i] >= tab[i+1])
        {
            return tab[i];
        }
    }

    return -1;
}

void remplirTableau(int tableau[], int taille, int min, int max) {
    int i;
    for (i = 0; i < taille; ++i) {
        tableau[i] = rand() % (10 - 0 + 1) + min;
    }
}

int main (){

}