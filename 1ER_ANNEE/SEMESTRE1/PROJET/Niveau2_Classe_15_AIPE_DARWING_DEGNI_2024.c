#include <stdio.h>
#include <stdlib.h>

// Fonction qui récupère le plateau des joueurs
void plateau(int tableau[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tableau[i]);
        getchar();
    }
}

//Fonction qui vérifie si les deux joueurs ont bien le bon nombre de vaisseaux spatiaux 
int vérification_vaisseau(int tableau[], int n, int b)
{
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (tableau[i] + tableau[i + 1] + tableau[i + 2] == 3)
        {
            c++;
            i += 2;
        }
    }
    if (c != b)
    {
        printf("FIN DE PARTIE : PAS ASSEZ DE VAISSEAUX SPATIAUX");
        exit(-1);
    }

    return 0;
}

//Fonction qui vérifie si les joueurs ont le même nombre de coups et si les coups sont tous bon
void verification_coups(int nbr_coups, int n, int coups[])
{
    for (int i = 0; i < nbr_coups;i++)
    {
        if (coups[i] > n)
        {
            printf("COUP INTERDIT : PARTIE FINIE\n");
            exit(-1);
        }
    }
    if (nbr_coups % 2 != 0)
    {
        printf("COUP MANQUANT : PARTIE INCOMPLETE\n");
        exit(-1);
    }
}

//Fonction qui effectue l'échange de coups entre les joueurs et affiche le gagnant et compte les bateaux restant
int combat(int tabA[], int tabB[], char premier, int b, int n)
{
    int numero_coups = 0;
    int count = 0;

    while (numero_coups != -1)
    {
        scanf("%d", &numero_coups);
        if (numero_coups > n)
        {
            printf("COUP INTERDIT : PARTIE FINIE\n");
            exit(-1);
        }

        if (premier == 'A')
        {
            tabB[numero_coups] = 0;
            premier = 'B';
        }
        if (premier == 'B')
        {
            tabA[numero_coups] = 0;
            premier = 'A';
        }
        count++;
    }
    count--;
    return count;
}

void gagnant(int tabA[], int tabB[], int n)
{
    int point_A = 0;
    int point_B = 0;

    for (int i = 0; i < n; i++)
    {
        if (tabA[i] + tabA[i + 1] + tabA[i + 2] == 3)
        {
            point_A++;
            i += 2;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (tabB[i] + tabB[i + 1] + tabB[i + 2] == 3)
        {
            point_B++;
            i += 2;
        }
    }

    if (point_A > point_B) {
        printf("PARTIE TERMINE: GAGNANT ALICE : %d a %d \n", point_A, point_B);
    }
    if (point_B > point_A) {
        printf("PARTIE TERMINE: GAGNANT BERNARD : %d a %d \n", point_B, point_A);
    }
    if (point_A == point_B) {
        printf("PARTIE FINIE A EGALITE : %d a %d \n", point_A, point_B);
    }
}

int main() {

    // VARIABLES :
    int n = 0;
    int b = 0;
    char espace;
    char Alice;
    char Bernard;
    char premier;


    scanf("%d  %d ", &n, &b);
    scanf(" %c", &espace);
    scanf(" %c", &Alice);

    int* tableau_Alice = malloc(n * sizeof(int));
    int* tableau_Bernard = malloc(n * sizeof(int));

    plateau(tableau_Alice, n);

    scanf(" %c", &espace);
    scanf(" %c", &Bernard);

    plateau(tableau_Bernard, n);

    vérification_vaisseau(tableau_Alice, n, b);
    vérification_vaisseau(tableau_Bernard, n, b);

    scanf(" %c", &espace);

    scanf(" %c", &premier);

    scanf(" %c", &espace);

    int nbr_coups = combat(tableau_Alice, tableau_Bernard, premier, b, n);

    printf("TAILLE DU TABLEAU: %d \n", n);
    printf("NOMBRE DE VAISSEAU SPATIAUX: %d \n", b);
    printf("NOMBRE DE COUPS : %d \n", nbr_coups);
    gagnant(tableau_Alice, tableau_Bernard, n);
    printf("PARTIE TERMINEE: FIN DU JEU\n");

    free(tableau_Alice);
    free(tableau_Bernard);
}