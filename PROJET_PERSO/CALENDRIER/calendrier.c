#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int entre_annee()
{
    int annee;
    printf("Quel est l'annee du calendrier a afficher ? :");
    if (scanf("%d", &annee) != 1)
    {
        printf("La saisie est invalide ! Veuillez entrer un entier svp\n");
        while (getchar() != '\n')
            ;
    }
    return annee;
}

bool verifie_annee_bissextile(int annee)
{
    if (annee % 4 == 0 && annee % 100 != 0)
    {
        return true;
    }
    else if (annee % 400 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int nombre_jours_mois(int mois, int annee)
{
    if (mois == 2)
    {
        if (verifie_annee_bissextile(annee))
        {
            return 29;
        }
        else
        {
            return 28;
        }
    }

    if (mois == 4 || mois == 6 || mois == 9 || mois == 11)
    {
        return 30;
    }
    else
    {
        return 31;
    }
}

void afficher_jours_semaine(char *jours_semaine[])
{
    for (int i = 0; i < 7; i++)
    {
        printf("%s  ", jours_semaine[i]);
    }
    printf("\n");
}

int formule_de_Zeller(int annee, int mois, int jours)
{
    if (mois == 1 || mois == 2)
    {
        mois += 12;
        annee--;
    }
    int K = annee % 100;
    int J = annee / 100;
    int result = 0;

    int result_1 = (13 * (mois + 1)) / 5;
    int result_2 = K / 4;
    int result_3 = J / 4;

    result = (jours + result_1 + K + result_2 + result_3 - 2 * J) % 7;

    result = (result + 5) % 7;
    printf("Le premier jours est le %d\n", result);
    return result;
}

void affichage_jours(int annee, int mois, char *jours_semaine[], char *jours_mois[])
{
    int jours_m = nombre_jours_mois(mois, annee);
    int premier_jour = formule_de_Zeller(annee, mois, 1);

    // Titre
    printf("=================================\n");
    printf("           %s %d     \n", jours_mois[mois - 1], annee);
    printf("=================================\n\n");

    // Affiche les noms des jours de la semaine
    afficher_jours_semaine(jours_semaine);

    // Alignement pour le premier jour du mois
    for (int i = 0; i < premier_jour; i++)
    {
        printf("     ");
    }

    // On affiche les jours de la semaine
    for (int jours = 1; jours <= jours_m; jours++)
    {
        printf("%3d  ", jours);
        if ((jours + premier_jour) % 7 == 0)
        {
            printf("\n");
        }
    }
    printf("\n");
}
int main()
{
    char *jours_mois[] = {"Janvier", "Fevrier", "Mars", "Avril", "Mai", "Juin", "Juillet", "Aout", "Septembre", "Octobre", "Novembre", "Decembre"};
    char *jours_semaine[] = {"Lun", "Mar", "Mer", "Jeu", "Ven", "Sam", "Dim"};

    int annee = entre_annee();
    int mois = 0;

    do
    {
        printf("Entrez le numero du mois (1-12) : ");
        scanf("%d", &mois);
    } while (mois < 1 || mois > 12);

    // Affichage du calendrier
    affichage_jours(annee, mois, jours_semaine, jours_mois);

    return 0;
}