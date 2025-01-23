#include <stdio.h>
#include <stdlib.h>

void renduDeMonnaie(int systemeMonetaire[], int caisse[], int montantARendre)
{
    int n = 8;
    int rendu[8];

    for(int i = 0; i < n; i++)
    {
        rendu[i] = 0;
    }

    for(int i = n - 1; i >= 0; i--)
    {
        while(montantARendre >= systemeMonetaire[i])
        {
            if(caisse[i] > rendu[i])
            {
                montantARendre -= systemeMonetaire[i];
                rendu[i]++;
                caisse[i]--;
            }
            else
            {
                printf("Pas assez de pieces dans la caisse...");
                exit(-1);
            }
        }
    }

    printf("Montant à rendre : ");

    for(int i = n - 1; i >= 0; i--)
    {
        if(systemeMonetaire[i] >= 5)
        {
            printf("%d billet(s) de %d euros \n", rendu[i], systemeMonetaire[i]);
        }
        else
        {
            printf("%d piece(s) de %d euros \n", rendu[i], systemeMonetaire[i]);
        }
    }
}

int main()
{
    int systemeMonetaire[] = {1,2,5,10,20,50,100,200};
    int caisse[] = {1000,500,200,100,50,20,10,5};
    int montantARendre = 0;

    printf("Saisir le montant...");
    scanf("%d", &montantARendre);
    printf("\n");
    
    renduDeMonnaie(systemeMonetaire, caisse, montantARendre);

    return 0;
}