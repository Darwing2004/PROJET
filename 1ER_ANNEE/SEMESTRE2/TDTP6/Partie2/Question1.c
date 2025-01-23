#include <stdio.h>

void echange(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int tab[], int min, int max)
{
    int pivot = tab[max];

    int i = (min - 1);

    for(int j = 0; j < max; j++)
    {
        if(tab[j] <= pivot)
        {
            i++;
            echange(&tab[i], &tab[j]);
        }
    }

    echange(&tab[i+1], &tab[max]);

    return (i+1);
}

void tri_rapide(int *tab, int min, int max)
{
    if(min< max)
    {
        int pi = partition(tab, min, max);

        tri_rapide(tab, min, pi - 1);

        tri_rapide(tab, pi + 1, max);

    }
}

void afficher_tab(int *tab, int taille)
{
    for(int i = 0; i < taille; i++)
    {
        printf("%d ", tab[i]);
    }
    printf("\n");
}

int main () {
    int tableau[] = {5, 2, 9, 7, 6, 3, 2};

    int n = sizeof(tableau) / sizeof(tableau[0]);

    printf("Tableau non trie\n");
    afficher_tab(tableau, n);

    tri_rapide(tableau, 0, n-1);

    printf("Tableau trie dans l'ordre croissant: \n");
    afficher_tab(tableau, n);
}