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

void FUSION(int N, int TAB[N], int debut, int milieu, int fin){
	int i, j, k;
	int TEMP[fin-debut+1]; //Tableau temporaire
	i=debut;
	j=milieu+1;
	k=0;
	
	while ((i<=milieu) && (j<=fin)){
		/*On compare élément par élément les deux sous tableaux*/
		if (TAB[i] <= TAB[j]){
			TEMP[k] = TAB[i];
			i++;
		}
		else{
			TEMP[k] = TAB[j];
			j++;
		}
		k++;
	}
	
	while (i<=milieu)/*Si le premier tas n'est pas encore fini, on recopie le reste*/{
		TEMP[k] = TAB[i];
		k++;
		i++;
	}
	
	while (j<=fin)/* Si le deuxième tas n'est pas encore fini, on recopie le reste*/{
		TEMP[k] = TAB[j];
		k++;
		j++;
	}
	
	k=0;
	for (i=debut; i<=fin; i++)/*On copie le tableau temporaire dans le tableau original*/{
		TAB[i] = TEMP[k];
		k++;
	}
}

void TRI_FUSION(int N, int TAB[N], int debut, int fin){
	int milieu;
	if (debut != fin){
		milieu = (debut + fin)/2;
		TRI_FUSION(N, TAB, debut, milieu);
		TRI_FUSION(N, TAB, milieu+1, fin);
		FUSION(N, TAB, debut, milieu, fin);
		/*AFFICHAGE_TAB(TAB)*/
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
        AFFICHAGE_TAB(t, tab);

        TRI_FUSION(t, tab, debut, fin);
        AFFICHAGE_TAB(t, tab);

        int med = mediane(tab, t);
        printf("La médiane est: %d\n", med);
}
