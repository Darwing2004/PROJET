#include <stdio.h>

int main()
{
    char tab[10];

    printf("Saisir une chaine de caractères:");
    scanf("%[^\n]", tab);
    printf("Chaîne saisie : %s\n", tab);

    return 0;
}