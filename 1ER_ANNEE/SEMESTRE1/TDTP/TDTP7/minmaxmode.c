#include <stdio.h>
#include <stdlib.h>

void LoadArray(int size, int iArray[])
{
    printf("Remplissez le tableau de %d terme(s):\n", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &iArray[i]);
    }
}

void ShowArray(int size, int iArray[])
{
    for (int i = 0; i < size;i++)
    {
        printf("%d ", iArray[i]);
    }
    printf("\n");
}

int getMax(int size, int iArray[])
{
    int max = 0;
    int i;
    for (i = 0; i < size; i++)
    {
        if (iArray[i] > max)
        {
            max = iArray[i];
        }
    }
    return max;
}

int getMin(int size, int iArray[])
{
    int i; 
    for (i = 0; i < size;i++)
    {
        if (iArray[0] > iArray[i])
        {
            iArray[0] = iArray[i];
        }
    }
    return iArray[0];
}

int getMaxIndex(int size, int iArray[])
{
    int max = 0;
    int index;
    
    for(int i = 0; i < size;i++)
    {
        if (iArray[i] > max)
        {
            max = iArray[i];
            index = i;
        }
    }
    printf("Le (premier) maximum des éléments a pour index %d\n", index);
}

int getMinIndex(int size, int iArray[])
{
    int min = iArray[0];
    int index = 0;
    for(int i = 0; i < size; i++)
    {
        if (iArray[i] < min)
        {
            min = iArray[i];
            index = i;
        }
    }
    printf("Le (premier) minimum des éléments a pour index %d\n", index);
}

int getMode(int size, int iArray[])
{
    int comp;
    int b;

    for(int i = 0; i < size ; i++)
    {
        b = iArray[i];
        for  (int j = i + 1; j < size; j++)
        {
            if ( b == iArray[i])
            {
                comp = iArray[i];
            }
        }
    }
    printf("La valeur en double est %d", comp);
}

void toLOwerCase(char sentence [])
{
    
}

int main() {
    int taille;
    printf("Choissisez la taille du tableau:");
    scanf("%d", &taille);

    int myTab[taille];

    LoadArray(taille, myTab);
    ShowArray(taille, myTab);

    getMode(taille, myTab);
}