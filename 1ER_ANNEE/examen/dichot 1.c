#include<stdio.h>

void affiche(int n, int tab[]);
int dichotomie(int n, int tab[], int g , int d, int x);

int main()
{
    int taille;
    int x;
    printf("Saisissez la taille\n");
    scanf("%d", &taille);
    printf("Saisissez la valeur chercher\n");
    scanf("%d", &x);

    int tab[taille];

    printf("Saisissez les valeurs du tableau\n");
    for(int i = 0; i<taille; i++)
    {
        scanf("%d", &tab[i]);
    }
    int g=0;
    int d= taille;
    dichotomie(taille, tab, g, d, x);


    return 0;
}
void affiche(int n, int tab[])
{
    for(int i = 0; i<n; i++)
    {
        printf("%d ", tab[i]);
    }
    printf("\n");
}
int dichotomie(int n, int tab[], int g , int d, int x)
{
        int m= 0;
        m= (g+d)/2;
        if(tab[m]<x)
        {
            printf("le nombre est mystère est plus grand: %d\n", m);
            affiche(d, tab);
            return dichotomie(n, tab, m ,d , x);
        }
        if(tab[m]>x)
        {
            printf("le nombre est mystère est plus petit: %d\n", m);
            return dichotomie(n, tab, g, m, x);
        }
        if(tab[m]==x)
        {
            printf("nombre mystère trouvé à la position: %d ", m);
            return 1;
        }
}
    