#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void REMPLISSAGE_TAB(int *tab, int n)
{
    for (int i = 0; i < n; i++)
    {
        tab[i] = rand() % 100;
    }
}

void AFFICHAGE_TAB(int *tab, int n)
{
    printf("tab : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", tab[i]);
    }
}
void FUSION(int *tab,int n)
{
    // Création des sous-tableaux
    int n1 = m - a + 1; // n1 va du début à 
    int n2 = b - m;

    int L[n1], M[2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = tab[a + 1];
    }

}   


int main()
{

    int size = 10;
    int tab[size];
    REMPLISSAGE_TAB(tab, size);
    TRI_FUSION(tab, size);
}