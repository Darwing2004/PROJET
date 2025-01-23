#include<stdlib.h>
#include<time.h>
#include<stdio.h>

void REMPLISSAGE_TAB(int tab[], int N){
	for(int i = 0; i < N; i++){
		tab[i] = rand() % 100;
	}
}

void AFFICHAGE_TAB(int tab[], int N){
	for(int i = 0; i < N; i++){
		printf("%d ", tab[i]);
	}
	printf("\n");
}

int Partition_Lomuto(int tab[], int debut, int fin){
	int x = tab[fin] /*On choisit le pivot*/;
	int i = debut - 1;
	int temp;

	for(int j = debut; j <= fin - 1; j++){
		if(tab[j] <= x){
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

int Partition_Hoare(int tab[], int debut, int fin){
	int x = tab[debut] /*pivot*/;
	int i = debut - 1;
	int j = fin + 1;
	int temp;

	while(1){
		do{
			j = j-1;
		}
		while(tab[j] > x);
		do{
			i = i+1;
		}
		while(tab[i] < x);
		if(i < j){
			temp = tab[i];
			tab[i] = tab[j];
			tab[j] = temp;
		}
		else{
			return j;
		}
	}
}

void Tri_Rapide2(int tab[], int debut, int fin){
        if(debut < fin){
                int m = Partition_Hoare(tab, debut, fin);
                Tri_Rapide2(tab, debut, m-1);
                Tri_Rapide2(tab, m+1, fin);
        }
}

int main(){
	int t = 12;
	int tab[t];
	srand(time(NULL));
	int debut = 0;
	int fin = t-1;
	REMPLISSAGE_TAB(tab, t);
	AFFICHAGE_TAB(tab, t);

	Tri_Rapide(tab, debut, fin);
        AFFICHAGE_TAB(tab, t);

	Tri_Rapide2(tab, debut, fin);
	AFFICHAGE_TAB(tab, t);
}
