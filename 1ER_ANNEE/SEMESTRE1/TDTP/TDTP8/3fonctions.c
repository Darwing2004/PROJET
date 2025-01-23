#include <stdio.h>

// chaque joueur à son plateau//

unsigned int plateau(int tableau[], int n, int b)
{
    int c;
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &tableau[i]);
    }
}
int main()
{
    //Variable du code//
    int n, b;
    char espace;
    char Alice;
    char Bernard;
    int tabA[16];
    int tabB[16];

    scanf("%d %d", &n, &b);
    scanf(" %c", &espace);
    scanf(" %c", &Alice);
    printf("%d et %d\n%c", n, b, espace);

    printf("\n%c\n", Alice);

    int tableau_Alice = plateau(tabA, n, b);
    printf("%d", tableau_Alice);

    printf("\n%c\n", espace);

    int tableau_Bernard = plateau(tabB, n, b);
    printf("%d", tableau_Bernard);

    printf("%c\n", Bernard); 

    printf("\n%c\n", espace);

    // Le joueur qui commence peut changer//
    printf("%c\n", Alice);

    printf("%c\n", espace);

    printf("TAILLE DU TABLEAU : %d\n", n);
    printf("NOMBRE DE VAISSEAUX SPATIAUX: %d\n", b);
    printf("NOMBRE DE COUPS: ");

}