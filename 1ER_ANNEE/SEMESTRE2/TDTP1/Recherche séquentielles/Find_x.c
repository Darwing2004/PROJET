int chercherElement(int x, int tableau[], int NTab)
{
    for (int i = 0; i < NTab; i++)
    {
        if (tableau[i] == x)
        {
            return i;
        }
    }
    // Retourne -1 si l'élément n'est pas trouvé
    return -1;
}