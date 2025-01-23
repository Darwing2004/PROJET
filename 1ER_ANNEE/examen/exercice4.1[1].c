#include<stdio.h>
#include<stdlib.h>
#include<time.h>
# define Nlignesp3 8000
# define Ncolonnesp3 4000

void prod2(int Matrice[Nlignesp3][Ncolonnesp3], int Vecteur[Ncolonnesp3]){
	int i, j;
	int VecteurLoc[Ncolonnesp3];
	
	for(i =0; i < Nlignesp3 ;i++){
		VecteurLoc [ i ]=0;
		for(j=0; j < Ncolonnesp3;j++){
			VecteurLoc[i] = VecteurLoc[i]+ Matrice[i][j]*Vecteur[j];
		}
	}
	for(i =0; i < Ncolonnesp3; i++){
		Vecteur[i]= VecteurLoc[i];
	
	}
}
