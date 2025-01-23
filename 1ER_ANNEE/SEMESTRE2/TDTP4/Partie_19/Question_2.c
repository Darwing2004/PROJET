#include <stdio.h>

unsigned int Determ_Nbr_Seq(int *TAB, int n)
{
    int j = 1;
    int count = 1;
    for(int i = 0; i < n; i++)
    {
        if(TAB[i] > TAB[i-1])
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int n = 15;
    int TAB[] = {1, 2, 5, 3, 12, 25, 13, 8, 4, 7, 24, 28, 32, 11, 14};
    int nbr;
    nbr = Determ_Nbr_Seq(TAB, n);

    printf("nbr = %d", nbr);
}