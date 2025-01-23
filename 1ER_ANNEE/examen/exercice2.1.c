#include<stdlib.h>
#include<time.h>
#include<stdio.h>

void REMPLISSAGE_TAB(int tab[], int N){
        for(int i = 0; i < N; i++){
                tab[i] = rand() % 100;
        }
}

void AFFICHAGE_TAB(int N, int TAB[N]){
	int i;
	for (i=0; i<N; i++){
		printf("%d ", TAB[i]);
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

int DPR_mediane(int tab[], int debut, int fin, int milieu){
	if(debut == fin){
		return tab[debut];
	}
        int pivot = Partition_Lomuto(tab, debut, fin);

	int taille = pivot - debut + 1;
	if(taille == milieu){
			return tab[pivot];
        }
        else if(milieu < taille){
		return DPR_mediane(tab, debut, pivot-1, milieu);
        }
	else{
		return DPR_mediane(tab, pivot+1, fin, milieu - taille);
	}
}

int main(){
        srand(time(NULL));
        int t = rand()%40;
        int tab[t];
        int debut = 0;
        int fin = t-1;
        REMPLISSAGE_TAB(tab, t);
        AFFICHAGE_TAB(t, tab);
	int med;
	int milieu = (debut + fin) / 2;

	if((t%2) == 0){
		med = DPR_mediane(tab, debut, fin, milieu) + DPR_mediane(tab, debut, fin, milieu + 1);
	}
	else{
		med = DPR_mediane(tab, debut, fin, milieu + 1);
	}
        printf("La médiane est: %d\n", med);
}
