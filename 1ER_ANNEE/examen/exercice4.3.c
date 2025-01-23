#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Nlignes1 8
#define Ncolonnes1 8
#define Nlignes2 8
#define Ncolonnes2 8
void remp(int tab[][Ncolonnes1], int lignes, int colonnes)
{
	for (int i = 0; i < lignes; i++)
	{
		for (int j = 0; j < colonnes; j++)
		{
			tab[i][j] = rand() % 100;
		}
	}
}
void displayMatrix(int matrix[][Ncolonnes2], int lignes, int colonnes)
{
	for (int i = 0; i < lignes; i++)
	{
		for (int j = 0; j < colonnes; j++)
		{
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
}
void prod4(int mat1[][Ncolonnes1], int mat2[][Ncolonnes2], int result[][Ncolonnes2])
{
	for (int i = 0; i < Nlignes1; i++)
	{
		for (int j = 0; j < Ncolonnes2; j++)
		{
			result[i][j] = 0;
			for (int k = 0; k < Ncolonnes1; k++)
			{
				result[i][j] += mat1[i][k] * mat2[k][j];
			}
		}
	}
}
int main()
{
	srand(time(NULL));
	int mat1[Nlignes1][Ncolonnes1];
	remp(mat1, Nlignes1, Ncolonnes1);
	int mat2[Nlignes2][Ncolonnes2];
	remp(mat2, Nlignes2, Ncolonnes2);
	int result[Nlignes1][Ncolonnes2];

	printf("Matrice 1 :\n");
	displayMatrix(mat1, Nlignes1, Ncolonnes1);

	printf("Matrice 2 :\n");
	displayMatrix(mat2, Nlignes2, Ncolonnes2);

	prod4(mat1, mat2, result);

	printf("Le résultat :\n");
	displayMatrix(result, Nlignes1, Ncolonnes2);
}
