#include <stdio.h>

unsigned int Longueur (unsigned int N)
{
    int i = 0;
    while(N != 0)
    {
        N = N / 10;
        i++;
    }

    printf("La longueur de l'entier est %d", i);
}

int main (){
    int a;
    printf("Choisis un entier:");
    scanf("%d", &a);

    Longueur(a);
}