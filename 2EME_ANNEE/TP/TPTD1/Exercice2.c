#include <stdio.h>

int NBM(char *tab, int n, int i, int result)
{
    int temps = 0;
    if (i == n)
    {
        return result;
    }

    if (i < n)
    {
        temps = tab[i];
        if (temps >= 65 && temps <= 90)
        {
            result++;
        }
    }

    return NBM(tab, n, i + 1, result);
}

int main()
{
    int n = 30;
    int i = 0;
    int compt = 0;

    char tab[n];
    printf("Entrez une chaine de caracteres (max 30 caracteres !):");
    scanf("%[^\n]", tab);
    int result = NBM(tab, n, i, compt);

    printf("Il y a %d majuscule dans %s", result, tab);
}