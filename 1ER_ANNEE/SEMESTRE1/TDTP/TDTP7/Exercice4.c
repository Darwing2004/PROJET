#include <stdio.h>

void mirroir (int T[], int taille)
{
    int temp;
    for(int i =0; i < taille / 2; i++)
    {
        temp=T[i];
        T[i] = T[taille - i-1];
        T[taille - i - 1] = temp;
    }
}

int main  ()
{
    int myTab[]={1,2,3,4,5}
}