#include<stdio.h>
#include<stdlib.h>

void ScanTableau(int hauteur, int largeur, int tab[hauteur][largeur]){
	for(int i = 0; i < hauteur; i++){
		for(int j = 0; j < largeur; j++){
			scanf("%d", &tab[i][j]);
		}
	}
}

void InitTableau(int hauteur, int largeur, int tableau[hauteur][largeur]){
	for(int i = 0; i < hauteur; i++){
		for(int j = 0; j < largeur; j++){
			tableau[i][j] = 0;
		}
	}
}

void AffTableau(int hauteur, int largeur, int tab[hauteur][largeur]){
	for(int i = 0; i < hauteur; i++){
		for(int j = 0; j < largeur; j++){
			scanf("%d", &tab[i][j]);
			printf("%2d ", tab[i][j]);
		}
		printf("\n");
	}
}

void Propagation(int hauteur, int largeur, int vir, int i, int j, int tab[hauteur][largeur], int tableau[hauteur][largeur]){
	int x, y;

	if((tab[i][j] <= vir) && (tableau[i][j] == 0 || tableau[i][j] == -2)){
		if(tableau[i][j] == 0){
			tableau[i][j] == -1;
		}

		for(x = (i-1); i < (i+2); x++){
			for(y = (j-1); y < (j+2); y++){
				if((x >= 0 && x < hauteur) && (y >= 0 && y < largeur) && (x != i || y != j)){
					Propagation(hauteur, largeur, vir, i, j, tab, tableau);}
			}
		}
	}
}

int main(){
	int hauteur, largeur;
	int i, j;
	int vir;
	scanf("%d %d", &hauteur, &largeur);
	printf("Taille = %d * %d\n", hauteur, largeur);

	int tab[hauteur][largeur];
	int tableau[hauteur][largeur];

	InitTableau(hauteur, largeur, tableau);

	ScanTableau(hauteur, largeur, tab);
	scanf("%d %d", &i, &j);
        scanf("%d", &vir);

	AffTableau(hauteur, largeur, tab);
	printf("Foyer = (%d, %d)\n", i, j);
	printf("Virulence = %d\n", vir);

	tableau[i][j] = -2;

	printf("\nPropagation du virus : \n");
	Propagation(hauteur, largeur, vir, i, j, tab, tableau);
	AffTableau(hauteur, largeur, tableau);
	return 0;
}
