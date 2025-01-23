#include <stdio.h>
#include <stdlib.h>

int **create(int ligne, int colonne)
{
    int **tab = (int **)malloc(ligne * sizeof(int *));

    for (int i = 0; i < ligne; i++)
    {
        tab[i] = (int *)malloc(colonne * sizeof(int));
    }

    if (tab == NULL)
    {
        printf("Erreur d'allocation\n");
        exit (1);
    }

    for (int i = 0; i < ligne; i++)
    {
        if (tab[i] == NULL)
        {
            printf("Erreur d'allocation\n");
            exit (1);
        }
    }

    printf("Remplie ton tableau:");
    for (int i = 0; i < ligne; i++)
    {
        for (int j = 0; j < colonne; j++)
        {
            scanf("%d", tab[i][j]);
        }
    }

    return 0;
}

void **display(int ligne, int colonne)
{
    printf("La matrice est:\n");
    for (int i = 0; i < ligne; i++)
    {
        for (int j = 0; j < colonne; j++)
        {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
}

int mult(int **tab, int **tab2, int ligne, int colonne)
{
    int **tab_r[ligne][ligne];

    printf("BOOM\n");

    for (int i = 0; i < ligne; i++)
    {
        for (int j = 0; j < ligne; j++)
        {
            tab_r[i][j] = 0;
            printf("%d ", tab_r[i][j]);
        }
        printf("\n");
    }

    printf("BOOM\n");

    for (int i = 0; i < ligne; i++)
    {
        for (int j = 0; j < ligne; j++)
        {
            for (int k = 0; k < colonne; k++)
            {
                tab_r[i][j] += tab[i][k] * tab2[k][j];
            }
        }
    }

    printf("BOOM\n");

    for (int i = 0; i < ligne; i++)
    {
        for (int j = 0; j < ligne; j++)
        {
            printf("%d ", tab_r[i][j]);
        }
        printf("\n");
    }

    printf("BOOM\n");

    return 0;
}
int main()
{
    int ligne;
    int colonne;

    int **tab;
    int **tab2;
    int **tab_r;

    printf("Choisis le nombre de ligne du tableau:");
    scanf("%d", &ligne);

    printf("Choisis le nombre de colonne du tableau:");
    scanf("%d", &colonne);

    create(ligne, colonne);
    display(ligne, colonne);

    create(colonne, ligne);
    display(colonne, ligne);

    mult(tab, tab2, ligne, ligne);
    display(ligne, ligne);

    for (int i = 0; i < ligne; i++)
    {
        free(tab[i]);
        free(tab2[i]);
    }
    free(tab);
    free(tab2);
}