#include <stdio.h>

// Correction Q1
int leigth(int n, int c)
{
    if (n < 10 && n != 0)
    {
        return c + 1;
    }
    else if (n == 0)
    {
        return 0;
    }

    int somme digit(int n)
    {
        if (n == 0)
            return 0;

        return n % 10 + sommedigit(n / 10);
    }

    return leigth(n / 10, c + 1);
}

// Corection Q2
int chassezle9_rec(int n)
{
    if (n < 10)
    {
        if (N % 10 != 9)
        {
            return N;
        }
        else
        {
            eturn 0;
        }
    }
    else if (N % 10 != 9)
    {
        return N % 10 + 10 * chassezle9_rec(N / 10);
    }
    else
    {
        return chassezle9_rec(N / 10);
    }
}

//Exercice 3.2
unsigned long fibonacci (int n, unsigned int long a, unisgned int long b)
{
    return n == 0 ? a : fibonacci (n - 1,b,a+b);

}
