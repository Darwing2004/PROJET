#include <stdio.h>
#include <stdlib.h>

void plateau(int tableau[], int n, int vaisseau);
void changertir(int tab[], int tir);
void lire_coup(int tabAlice[], int tabBernard[], int taille);
void afficher_gagnant(int tabAlice[], int tabBernard[], int taille);

int main()
{
    int case_total;
    int vaisseau_total;
    char espace;
    char joueur;


    scanf("%d %d\n", &case_total, &vaisseau_total);
    printf("TAILLE DU TABLEAU : %d\n", case_total);
    printf("NOMBRE DE VAISSEAUX SPATIAUX : %d\n", vaisseau_total);
    int tabA[case_total];
    int tabB[case_total];
    scanf("%c\n", &espace);
    scanf("%c\n", &joueur);
    plateau(tabA, case_total, vaisseau_total);
    scanf("%c\n", &espace);
    scanf("%c\n", &joueur);
    plateau(tabB, case_total, vaisseau_total);
    scanf("%c\n", &espace);
    scanf("%c\n", &joueur);
    scanf("%c\n", &espace);
    lire_coup(tabA, tabB, case_total);
    afficher_gagnant(tabA, tabB, case_total);

    return 0;
}

void plateau(int tableau[], int taille, int vaisseau)
{
    int compteur_vaisseau = 0;
    for (int i = 0; i < taille; i++)
    {
        scanf("%d ", &tableau[i]);
        if (tableau[i] == 1)
        {
            compteur_vaisseau++;
        }
        printf("%d ", tableau[i]);
    }
    printf("\n");
    if (compteur_vaisseau < vaisseau)
    {
        printf("\nFIN DE PARTIE : PAS ASSEZ DE VAISSEAUX SPATIAUX ");
    }
}

void changertir(int tab[], int tir)
{
    if (tab[tir] == 1)
    {
        tab[tir] = 0;
    }
}

void lire_coup(int tabAlice[], int tabBernard[], int taille)
{
    int nbcoupAlice = 0;
    int nbcoupBernard = 0;
    int nbcoupgeneral = 0;
    int coupjoue = 0;
    while (coupjoue != -1)
    {
        if (coupjoue < taille && nbcoupBernard % 2 == 0)
        {
            changertir(tabBernard, coupjoue);
            nbcoupAlice++;

        }if (coupjoue < taille && nbcoupAlice % 2 == 1)
        {
            changertir(tabAlice, coupjoue);
            nbcoupBernard++;
        }
        if (coupjoue >= taille)
        {
            printf("\nCOUP INTERDIT : PARTIE FINIE");
            exit(-1);
        }
        scanf("%d", &coupjoue);
        printf("%d", coupjoue);
    }
    if (nbcoupBernard == nbcoupAlice)
    {
        nbcoupgeneral = nbcoupAlice;
    }
    if (nbcoupAlice != nbcoupBernard)
    {
        printf("\nCOUP MANQUANT : PARTIE INCOMPLETE");
    }
    printf("\nNOMBRE DE COUP : %d\n", nbcoupgeneral);
}

void afficher_gagnant(int tabAlice[], int tabBernard[], int taille)
{
    int reste_vaisseau_A = 0;
    int reste_vaisseau_B = 0;

    for (int i = 0; i < taille; i++)
    {
        if (tabAlice[i] == 1)
        {
            reste_vaisseau_A++;
        }
        if (tabBernard[i] == 1)
        {
            reste_vaisseau_B++;
        }
    }

    if (reste_vaisseau_A > reste_vaisseau_B && reste_vaisseau_A != reste_vaisseau_B)
    {
        printf("\nPARTIE FINIE : GAGNANT ALICE : %d à %d", reste_vaisseau_A, reste_vaisseau_B);
    }
    else if (reste_vaisseau_B > reste_vaisseau_A && reste_vaisseau_A != reste_vaisseau_B)
    {
        printf("\nPARTIE FINIE : GAGNANT BERNARD : %d à %d", reste_vaisseau_A, reste_vaisseau_B);
    }
    else if (reste_vaisseau_A == 0 && reste_vaisseau_A != reste_vaisseau_B)
    {
        printf("\nPARTIE FINIE : GAGNANT BERNARD");
    }
    else if (reste_vaisseau_B == 0 && reste_vaisseau_A != reste_vaisseau_B)
    {
        printf("\nPARTIE FINIS : GAGNANT ALICE");
    }
    else if (reste_vaisseau_A == reste_vaisseau_B)
    {
        printf("\nPARTIE FINIE A EGALITE : %d à %d", reste_vaisseau_A, reste_vaisseau_B);
    }

    printf("\nPARTIE TERMINÉE : FIN DU JEU");
}