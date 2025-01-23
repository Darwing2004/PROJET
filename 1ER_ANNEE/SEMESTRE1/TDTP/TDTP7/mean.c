#include <stdio.h>

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

double getMean(int size, int iArray[])
{
    float moy = 0;
    float b = size;

    for (int i = 0; i < size; i++)
    {
        moy = moy + iArray[i];
    }
    moy = moy / b;
    printf("La moyenne est %f", moy);
}
int main() {
    int a;
    printf("Choissisez la taille du tableau:");
    scanf("%d", &a);

    int myTab[a];

    LoadArray(a, myTab);
    ShowArray(a, myTab);
    getMean(a, myTab);


}