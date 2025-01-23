#include<stdio.h>
#include<stdlib.h>

int Best_Fit(int items[], int nbitems, int capacity){
	int bacs[nbitems]; /*Tableau pour stocker les bacs*/
	int nbrebacs = 0; /*Nombre de bacs utilisés*/
	
	/*Parcourir chaque objet*/
	for(int i = 0; i < nbitems; i++){
		/*Chercher le bac qui a la capacité minimale mais suffisante pour accueillir l'objet*/
		int best_bac = -1;
		int min_space = capacity + 1;
		for(int j = 0; j < nbrebacs; j++) {
			int space_left = capacity - bacs[j];
			if(items[i] <= space_left && space_left < min_space){
				best_bac = j;
				min_space = space_left;
			}
		}
		if(best_bac == -1){/*Aucun bac disponible pour accueillir l'objet, créer un nouveau bac*/
			bacs[nbrebacs++] = items[i];
		}else{/*Ajouter l'objet au meilleur bac trouvé*/
			bacs[best_bac] += items[i];
		}
	}
	return nbrebacs; /*Retourner le nombre de bacs utilisés*/
}

int First_Fit(int items[], int nbitems, int capacity){
        int bacs[nbitems]; /*tableau pour stocker les bacs*/
        int nbrebacs = 0; /*nombre de bacs utilisés*/

        /*Parcourir chaque item*/
        for(int i=0; i < nbitems; i++){
                int j;
		/*chercher le premier bac pouvant accueillir l'item*/
                for(j = 0; j < nbrebacs; j++){
                        if(items[i] <= capacity - bacs[j]){
                                bacs[j] += items[i];
                                break;
                        }
                }
                if(j == nbrebacs){ /*aucun bac ne peut accueillir l'item, créer un autre bac*/
                        bacs[nbrebacs++] = items[i];
                }
        }

        return nbrebacs; /*retourner le nombre de bacs utilisés*/
}

int Partition_Lomuto(int tab[], int debut, int fin){
	int x = tab[fin] /*On choisit le pivot*/;
	int i = debut - 1;
	int temp;

	for(int j = debut; j <= fin - 1; j++){
		if(tab[j] >= x){
			i++;
			temp = tab[i];
			tab[i] = tab[j];
			tab[j] = temp;
		}
	}
	temp = tab[i+1];
	tab[i+1] = tab[fin];
	tab[fin] = temp;/*On ramène le pivot entre les deux partitions*/;
	return i+1;
}

void Tri_Rapide(int tab[], int debut, int fin){
	int m;
        if(debut < fin){
                m = Partition_Lomuto(tab, debut, fin);
                Tri_Rapide(tab, debut, m-1);
                Tri_Rapide(tab, m+1, fin);
        }
}

void AFFICHAGE_TAB(int tab[], int N){
	for(int i = 0; i < N; i++){
		printf("%d ", tab[i]);
	}
	printf("\n");
}

int BFF(int items[], int nbitems, int capacity){
        int bacs[nbitems]; /*Tableau pour stocker les bacs*/
        int nbrebacs = 0; /*Nombre de bacs utilisés*/

        /*Parcourir chaque objet*/
        for(int i = 0; i < nbitems; i++){
                /*Chercher le bac qui a la capacité minimale mais suffisante pour accueillir l'objet*/
                int best_bac = -1;
                int min_space = capacity + 1;
                for(int j = 0; j < nbrebacs; j++) {
                        int space_left = capacity - bacs[j];
                        if(items[i] <= space_left && space_left < min_space){
                                best_bac = j;
                                min_space = space_left;
                        }
                }
                if(best_bac == -1){/*Aucun bac disponible pour accueillir l'objet, créer un nouveau bac*/
                        bacs[nbrebacs++] = items[i];
                }else{/*Ajouter l'objet au meilleur bac trouvé*/
                        bacs[best_bac] += items[i];
                }
        }
        return nbrebacs; /*Retourner le nombre de bacs utilisés*/
}

int FFD(int items[], int nbitems, int capacity){
        int bacs[nbitems]; /*tableau pour stocker les bacs*/
        int nbrebacs = 0; /*nombre de bacs utilisés*/

        /*Parcourir chaque item*/
        for(int i=0; i < nbitems; i++){
                int j;
                /*chercher le premier bac pouvant accueillir l'item*/
                for(j = 0; j < nbrebacs; j++){
                        if(items[i] <= capacity - bacs[j]){
                                bacs[j] += items[i];
                                break;
                        }
                }
                if(j == nbrebacs){ /*aucun bac ne peut accueillir l'item, créer un autre bac*/
                        bacs[nbrebacs++] = items[i];
                }
        }

        return nbrebacs; /*retourner le nombre de bacs utilisés*/
}


int main(){
	int items[] = {8, 5, 7, 6, 2, 4, 1};
	int nbitems = sizeof(items) / sizeof(items[0]);
	int capacity = 10;
	int fin = nbitems - 1;

	printf("Nombre minimum de bacs avec Best-Fit : %d\n", Best_Fit(items, nbitems, capacity));
	printf("Nombre minimum de bacs avec First-Fit : %d\n", First_Fit(items, nbitems, capacity));

	Tri_Rapide(items, 0, fin);
        AFFICHAGE_TAB(items, nbitems);


}
