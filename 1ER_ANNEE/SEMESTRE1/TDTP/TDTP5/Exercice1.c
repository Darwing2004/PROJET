#include <stdio.h>

int main()
{
    unsigned int a = 0;
    int i = 0;

    printf("Entrez une valeur:");
    scanf("%d", &a);
    
    while (a != 0)
    {
        i++;
        a = a / 10;
    }
    printf("La longueur du nombre est %d", i);
}