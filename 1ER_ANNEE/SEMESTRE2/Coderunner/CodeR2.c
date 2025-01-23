#include <stdio.h>

int Chassez_le_0_par_moins_un(unsigned int N)
{
    if (N == 0)
        return 0;
    int digit = N % 10;
    if (digit == 0)
        digit = -1;
    return Chassez_le_0_par_moins_un(N / 10) * 10 + digit;
}

unsigned int chassez_le_9(unsigned int n)
{
    if (n == 0)
        return 0;
    int digit = n % 10;
    if (digit == 9)
        digit = digit - 9;

    return chassez_le_9(n / 10) * 10 + digit;
}

int longueur_entier(int n)
{
    if (n <= 0)
    {
        return 0;
    }
    else
    {
        return longueur_entier(n/10)+1;
    }
}

int miroir_entier(int n, int result) 
{
    if (n == 0)
    {
        return result;
    }
    int reste = n % 10;
    
    return miroir_entier(n/10, result*10 + reste);
}

unsigned int FIBONACCI_REC(unsigned int N)
{
    if (N == 0 || N == 1)
    {
        return N;
    }
    else
    {
        return FIBONACCI_REC(N - 1) + FIBONACCI_REC(N - 2);
    }
}

void inverser_tab_rec(int tab[], int L, int I)
{
    int start = I;
    int end = L - 1 - I;

    if (start > end)
    {
        return;
    }
    else
    {
        int temp = tab[start];
        tab[start] = tab[end];
        tab[end] = tab[start];
    }

   inverser_tab_rec(start + 1 && end + 1)
}

int main()
{
    int N = 6;
    int nbr = FIBONACCI_REC(N);

    printf("nbr  = %d ", nbr);
}