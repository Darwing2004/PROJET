#include <stdio.h>

int main() {
    int i;
    int j = 0;
    int nbr;

    printf("Entrez le nombre:");
    scanf("%d", &nbr);

    printf("nbr = %d\n", nbr);

    while (nbr != 0)
    {
        if (nbr % 10 == 9)
        {
            nbr = (nbr - 9) / 10;
            i++;
        }
        nbr = nbr 10;
        i++;
    }
    printf("i = %d\n", i);
    float temp = nbr;
    while (j != i)
    {
        temp = temp * 10;
        printf("nbr = %f\n", nbr);
        j++;
    }
    nbr = temp;
    printf("j = %d\n", j);
    printf("%f", nbr);
}
