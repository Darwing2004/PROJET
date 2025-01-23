#include <stdio.h>

/*void unique_element(int *tab, int size, int *tab_unique, int *size_unique)
{
    //On cherche d'abord les éléments uniques

}*/

int main()
{
    int tab[] = {4, 5, 6, 9, 6, 2};
    int tab2[6];
    int k;
    /*for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (tab[i] == tab[j] && i != j)
            {
                printf("%d ", tab[i]);
                tab[i] = tab2[k];
                printf("%d ", tab2[k]);
            }
        }
        k++;
    }

    printf("\n");
    for(int i = 0; i < 6; i++)
    {
        printf("%d ", tab2[i]);
    }
}

ire un fichier Ecrire dans un fichier Fermeture d'un dossier Following sont les fonctions de gestion de fichiers les plus importantes disponibles en « C », fonction but fopen () Créer un fichier ou ouvrir un fichier existant fclose () Fermeture d'un dossier fprintf () Écrire un bloc de données dans un fichier fscanf ()