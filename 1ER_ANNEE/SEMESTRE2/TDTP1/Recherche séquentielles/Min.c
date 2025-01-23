include<stdio.h>

    int trouverMinimum(int tableau[], int taille)
{
    int min = tableau[0];

    for (int i = 0; i < taille; i++)
    {
        if (tableau[i] < tableau[i + 1] && min > tableau[i])
        {
            min = tableau[i];
        }
    }

    return min;
}