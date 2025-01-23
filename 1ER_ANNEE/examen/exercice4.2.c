#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Nlignesp3 8000
#define Ncolonnesp3 4000
void prod3(int Matrice[Nlignesp3][Ncolonnesp3], int Vecteur[Ncolonnesp3])
{
	int i, j;
	int Som = 0;
	int VecteurLoc[Ncolonnesp3];
	for (j = 0; j < Ncolonnesp3; j++)
	{
		Som = 0;
		for (i = 0; i < Nlignesp3; i++)
		{
			Som = Som + Matrice[i][j] * Vecteur[i];
		}
		VecteurLoc[j] = Som;
	}
	for (i = 0; i < Ncolonnesp3; i++)
	{
		Vecteur[i] = VecteurLoc[i];
	}
}
