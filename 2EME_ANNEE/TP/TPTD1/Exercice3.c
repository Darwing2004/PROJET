#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool PALINDROME(char *tab, int D, int G)
{
    if (D >= G)
    {
        return true;
    }

    if (tab[D] != tab[G])
    {
        return false;
    }

    return PALINDROME(tab, D + 1, G - 1);
}

int main()
{
    char tab[50];
    printf("Choisissez un mot : ");
    scanf("%s", tab);

    int longueur = strlen(tab);

    if (PALINDROME(tab, 0, longueur - 1))
    {
        printf("%s est un palindrome\n", tab);
    }
    else
    {
        printf("%s n'est pas un palindrome\n", tab);
    }

    return 0;
}