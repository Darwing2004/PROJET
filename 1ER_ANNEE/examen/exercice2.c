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

int mediane(int tab[], int n){
	int d;
	int median1;
	int median;

	if((n%2) == 0){
		d = n / 2;
		median = ((tab[d] + tab[d+1]) / 2);
		return median;
	}
	else if((n%2) != 0){
                d = n - 1;
                median1 = d / 2;
                return tab[median1];
        }
}

int main(){
	srand(time(NULL));
	int t = rand()%40;
	int tab[t];
	int debut = 0;
	int fin = t-1;
	REMPLISSAGE_TAB(tab, t);
	AFFICHAGE_TAB(tab, t);

	Tri_Rapide(tab, debut, fin);
        AFFICHAGE_TAB(tab, t);

	int med = mediane(tab, t);
	printf("La médiane est: %d\n", med);
}
