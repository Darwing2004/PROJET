#include <stdio.h>

int length(char str[50])
{
    int i = 0;

    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

int digits(char str[])
{
    int compt;
    int k = 0;

    for (compt = 0; str[compt] != 0; compt++)
    {
        int nbr = 0;
        nbr = str[compt];
        if (nbr >= 48 && nbr <= 57)
        {
            k++;
        }
    }
    return k;
}

int characters(char str[])
{
    int compt;
    int j;

    for (compt = 0; str[compt] != '\0'; compt++)
    {
        int nbr = 0;
        nbr = str[compt];
        if (nbr >= 97 && nbr <= 122)
        {
            j++;
        }
    }
    return j;
}

int espace(char str[])
{
    int compt;
    int m = 0;

    for (compt = 0; str[compt] != '\0'; compt++)
    {
        int nbr = 0;
        nbr = str[compt];
        if (nbr == 32)
        {
            m++;
        }
    }
    return m;
}

void reverse(char str[])
{
    int temp;
    int taille = length(str);

    for (int i = 0; i < taille / 2 + 1; i++)
    {
        temp = str[i];
        str[i] = str[taille - i - 1];
        str[taille - i - 1] = temp;
    }
    printf("la chaine renversé donne %s\n", str);
}

int count(char str[], char c)
{

    int i;
    int p = 0;
    for (i = 0; str[i] != 0; i++)
    {
        if (str[i] == c)
        {
            p++;
        }
    }
    if (p == 0)
    {
        return -1;
    }
    printf("Il y a %d %c dans la chaine de caractères\n", p, c);
}

int find(char str[], char c)
{
    int indx = 0;

    while (str[i] != '\0')
    {
        if (str[i] == c)
        {
            return indx;
        }
       i++;
    }
   return -1;
}

int main()
{
    char mytab[50];
    char d;

    printf("Entrez une chaine de caractères:\n");
    scanf("%[^\n]", mytab);

    printf("Choisis le terme à chercher:\n");
    scanf(" %c", &d);

    length(mytab);
    digits(mytab);
    characters(mytab);
    espace(mytab);
    reverse(mytab);
    find(mytab, d);
    count(mytab, d);
}