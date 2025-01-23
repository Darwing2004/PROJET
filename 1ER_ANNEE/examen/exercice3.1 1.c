#include <stdio.h>
#define taille 7

int* rendre_monnaie(int montant_a_rendre, int systeme_monetaire[], int caisse[]){
	static int rendu[taille] = {0}; /* Initialiser un tableau statique pour stocker le rendu*/
	/*Parcourir le système monétaire en ordre décroissant*/
	for (int i = 0; i < taille; i++){
		/*Calculer le nombre maximum de pièces/billets de cette valeur que l'on peut utiliser*/
		int nombre_max_pieces = (montant_a_rendre / systeme_monetaire[i] < caisse[i]) ? montant_a_rendre / systeme_monetaire[i] : caisse[i];
		/*Ajouter ce nombre de pièces/billets au rendu*/
		rendu[i] = nombre_max_pieces;
		/*Mettre à jour le montant à rendre*/
		montant_a_rendre -= systeme_monetaire[i] * nombre_max_pieces;
	}
	/*Si le montant restant n'est pas 0, alors on ne peut pas rendre la monnaie*/
	if (montant_a_rendre != 0){
		return NULL;
	}
	/*Retourner le tableau de rendu*/
	return rendu;
}

int main(){
	int systeme_monetaire[taille] = {200, 100, 50, 20, 10, 5, 2};
	int caisse[taille] = {5, 10, 20, 50, 100, 200, 500};
	int montant_a_rendre = 367;
	int* resultat = rendre_monnaie(montant_a_rendre, systeme_monetaire, caisse);
	/*Vérifier si le rendu est possible*/
	if (resultat == NULL){
		printf("Impossible de rendre la monnaie\n");
	}else{
		printf("Rendu de monnaie :\n");
		for(int i = 0; i < taille; i++){
			if (resultat[i] > 0) {
				printf("%d pièces/billets de %d euros\n", resultat[i], systeme_monetaire[i]);
			}
		}
	}
}

