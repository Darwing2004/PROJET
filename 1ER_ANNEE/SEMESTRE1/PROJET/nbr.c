#include <stdio.h>
#include <stdlib.h>

// Fonction qui récupère le plateau des joueurs
void plateau(long tableau[], long n)
{
    for (long i = 0; i < n; i++)
    {
        scanf("%ld", &tableau[i]);
        getchar();
    }
}

//Fonction qui vérifie si les deux joueurs ont bien le bon nombre de vaisseaux spatiaux 
int vérification_vaisseau(long tableau[], long n, long b)
{
    long c = 0;
    for (long i = 0; i < n; i++)
    {
        if (tableau[i] == 1)
        {
            c++;
        }
    }
    if (c != b)
    {
        printf("FIN DE PARTIE : PAS ASSEZ DE VAISSEAUX SPATIAUX");
        exit(-1);
    }

    return 0;
}

//Fonction qui récupères les coups du fichier texte et qui compte le nombre de coups

//Fonction qui vérifie si les joueurs ont le même nombre de coups et si les coups sont tous bon
void verification_coups(long nbr_coups, long n, long coups[])
{
    for (long i = 0; i < nbr_coups;i++)
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
long combat(long coups[], long tabA[], long tabB[], char premier, long b, long n)
{
    int numero_coups = 0;
    long count = 0;

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

void gagnant(long tabA[], long tabB[], int n)
{
    long point_A = 0;
    long point_B = 0;

    for (long i = 0; i < n; i++)
    {
        if (tabA[i] == 1)
        {
            point_A++;
        }
    }
    for (long i = 0; i < n; i++)
    {
        if (tabB [i] == 1)
        {
            point_B++;
        }
    }

    if (point_A > point_B) {
        printf("PARTIE TERMINE: GAGNANT ALICE : %ld a %ld\n", point_A, point_B);
    }
    if (point_B > point_A) {
        printf("PARTIE TERMINE: GAGNANT BERNARD : %ld a %ld\n", point_B, point_A);
    }
    if (point_A == point_B) {
        printf("PARTIE FINIE A EGALITE : %ld a %ld\n", point_A, point_B);
    }
}

int main() {

    // VARIABLES :
    long n = 0;
    long b = 0;
    char espace;
    char Alice;
    char Bernard;
    long coups[100000];
    char premier;


    scanf("%ld %ld", &n, &b);
    scanf(" %c", &espace);
    scanf(" %c", &Alice);

    long tableau_Alice[n];
    long tableau_Bernard[n];

    plateau(tableau_Alice, n);

    scanf(" %c", &espace);
    scanf(" %c", &Bernard);

    plateau(tableau_Bernard, n);

    vérification_vaisseau(tableau_Alice, n, b);
    vérification_vaisseau(tableau_Bernard, n, b);

    scanf(" %c", &espace);

    scanf(" %c", &premier);

    scanf(" %c", &espace);

    long nbr_coups = combat(coups, tableau_Alice, tableau_Bernard, premier, b, n);

    printf("TAILLE DU TABLEAU: %ld\n", n);
    printf("NOMBRE DE VAISSEAU SPATIAUX: %ld\n", b);
    printf("NOMBRE DE COUPS : %ld\n", nbr_coups);
    gagnant(tableau_Alice, tableau_Bernard, n);
    printf("PARTIE TERMINEE: FIN DU JEU\n");

}