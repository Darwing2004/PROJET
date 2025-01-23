int trouverMaximum(int tableau[], int taille)
{
    int max = 0;
    for (int i = 0; i < taille; i++)
    {
        if (tableau[i] > tableau[i + 1] && tableau[i] > max)
        {
            max = tableau[i];
        }
    }

    return max;
}