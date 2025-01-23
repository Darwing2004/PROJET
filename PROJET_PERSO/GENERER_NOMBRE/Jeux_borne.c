#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int nombre_aleatoire(int a, int b)
{
   int min = (a < b) ? a : b;
   int max = (a > b) ? a : b;

    int nombre = min + rand() % (max - min + 1);

    return nombre;
}
int main()
{
    // Déclaration des variables
    int nombreA ,nombreB ,result = 0;

    // Initialisation du générateur de nombre aléatoire
    srand(time(NULL));

    printf("Choisissez le premier nombre :");
    while (scanf("%d", &nombreA) != 1)
    {
        printf("Entree invalide. Veuillez entrer un entier :");

        // Nettoyer le buffer
        while (getchar() != '\n')
            ;
    }
    printf("Choisissez le deuxieme nombre :");
    while (scanf("%d", &nombreB) != 1)
    {
        printf("Entree invalide. Veuillez entrer un entier :");

        // Nettoyer le buffer
        while (getchar() != '\n')
            ;
    }

    result = nombre_aleatoire(nombreA, nombreB);
    printf("Le nombre genere est %d", result);

}