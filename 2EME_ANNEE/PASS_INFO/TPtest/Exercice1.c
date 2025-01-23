#include <stdio.h>
#include <stdlib.h>

int **allocate_matricee(int N, int M)
{
    int **matrice = (int **)malloc(N * sizeof(int *));

    if (matrice == NULL)
    {
        printf("Erreur d'allocation\n");
        exit(1);
    }

    for (int i = 0; i < N; i++)
    {
        matrice[i] = (int *)malloc(M * sizeof(int));
        if (matrice[i] == NULL)
        {
            printf("Erreur d'allocation\n");
            exit(1);
        }
    }

    return matrice;
}

int **read_and_fill_matrix(char *number, int *N, int *M)
{

    FILE *file = fopen(number, "r");
    if (file == NULL)
    {
        printf("Erreur");
        exit(1);
    }

    fscanf(file, "%d %d", N, M);
    int **matrice = allocate_matricee(*N, *M);

    for (int i = 0; i < *N; i++)
    {
        for (int j = 0; j < *M; j++)
        {
            fscanf(file, "%d", &matrice[i][j]);
        }
    }

    fclose(file);

    return matrice;
}

void print_matrix(int **matrice, int N, int M)
{

    printf("N = %d et M = %d\n", N, M);

    printf("MATRICE :\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }
}

int moyenne(int **matrice, int N, int M)
{
    int somme = 0;
    int nbr_total = N * M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            somme = somme + matrice[i][j];
        }
    }

    int moyenne = somme / nbr_total;

    return moyenne;
}

float pixel_seuil(int seuil, int **matrice, int N, int M)
{
    int compt = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (matrice[i][j] > seuil)
            {
                compt++;
            }
        }
    }

    return compt;
}

int main()
{
    int N, M, seuil, moy, compt;

    char *file = "number.txt";

    // Création de la matrice
    int **matrice = read_and_fill_matrix(file, &N, &M);
    print_matrix(matrice, N, M);

    // Calcul de l'intensité moyenne des pixels
    moy = moyenne(matrice, N, M);
    printf("L'intensite moyenne des pixels est %d\n", moy);

    // Calcule du nombre de pixels ayant une intensité supérieure à un seuil donné.

    printf("Quel est le seuil choisis ? : ");
    scanf("%d", &seuil);
    compt = pixel_seuil(seuil, matrice, N, M);
    printf("Il a %d pixel(s) superieur a %d", compt, seuil);

    for (int i = 0; i < N; i++)
    {
        free(matrice[i]);
    }
    free(matrice);

    return 0;
}
