#include <stdio.h>

int main()
{
    int nbr_l = 5;
    int nbr_c = 9; 
    int etoile, i, j;
    int k = 1;

    for(int i = 0; i < 5; i++){
	for(int j = 0; j < 8 - (2 * i); j++){
		printf(" ");
	}
	for(int j = 0; j < 1 + (2*i); j++){
		printf("* ");
	}
	printf("\n");
}
}
