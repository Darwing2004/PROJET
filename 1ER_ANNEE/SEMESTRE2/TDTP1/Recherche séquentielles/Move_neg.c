int deplacerNegatifs(int tableau[], int NTab)
{
    int temp;
    int negatif = 0;

    for (int i = 0; i < NTab; i++)
    {
        if (tableau[i] < 0)
        {
            temp = tableau[i];
            tableau[i] = tableau[negatif];
            tableau[negatif] = temp;

            negatif++;
        }
    }
    return negatif;
}