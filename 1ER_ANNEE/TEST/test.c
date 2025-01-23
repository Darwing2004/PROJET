#include <stdio.h>

unsigned int chassezlezero(int n)
{
    unsigned int nombre = 0;
    while (n > 0)
    {
        int reste = n % 10;
        if (reste != 9)
        {
            nombre = nombre * 10 + reste;
        }
        n /= 10;
    }

    unsigned int m = 0;
    unsigned int n1;

    while (nombre > 0)
    {
        n1 = nombre % 10;
        m = m * 10 + n1;
        nombre /= 10;
    }

    return m;
}

int main()
{
    int a = 189598;
    int n = chassezlezero(a);

    printf("n = %d", n);
}