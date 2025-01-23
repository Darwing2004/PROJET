#include <stdio.h>
#include <stdlib.h>

char **remplir(int nbr_mot)
{
    char **mots = (char **)malloc(nbr_mot * sizeof(char *));

    if (mots == NULL)
    {
        exit(1);
    }

    for (int i = 0; i < nbr_mot; i++)
    {
        mots[i] = (char *)malloc(20 * sizeof(char));
        if(mots[i] == NULL)
        {
            exit(1);
        }
    }

    //Remplir les mots
    for (int i = 0; i < nbr_mot; i++)
    {
        printf("Entrez votre mot %d (max 19 caracteres) : ", i + 1);
        scanf("%19s", mots[i]);
    }

    //Afficher les mots
    printf("Les chaines sont:\n");
    for (int i = 0; i < nbr_mot; i++)
    {
        printf("Chaine %d : %s\n", i + 1, mots[i]);
    }



     int compt = 0;
    for (int j = 0; j < 20; j++) // On compare jusqu'à 19 caractères
    {
        for (int i = 0; i < nbr_mot - 1; i++)
        {
            if (mots[i][j] != mots[i + 1][j])
            {
                printf("Le prefixe en commun est: ");
                for (int k = 0; k < compt; k++)
                {
                    printf("%c", mots[0][k]);
                }
                printf("\n");
                return; // Sortir dès que les caractères diffèrent
            }
        }
        compt++; // Si tous les caractères sont identiques pour cette position, on augmente le compteur
    }

    printf("compt = %d\n", compt);
    printf("Le prefixe en commun est:\n");
    for(int k = 0; k < compt; k++)
    {
        printf("%c", mots[0][k]);
    }

    return mots;
}

int main()
{
    int nbr_mot = 3;
    char **mots;

    remplir(nbr_mot);

    for (int i = 0; i < nbr_mot; i++)
    {
        free(mots[i]);
    }
    free(mots);
    return 0;
}
