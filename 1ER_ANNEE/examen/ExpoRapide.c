#include <stdio.h>
#include <stdlib.h>

unsigned long long exponentiationRapide(unsigned long long g, unsigned long long e, unsigned long long n);

int main()
{
    unsigned long long result;
    result =exponentiationRapide(7654321,999999,123456789);
    printf("\n Result : %llu\n", result);
    return 0;
}

unsigned long long exponentiationRapide(unsigned long long g, unsigned long long e, unsigned long long n)
{
    unsigned long long result = 1;
    g=g%n;
    while(e>0)
    {
        if(e%2==1)
            result=(result*g)%n;
        e=e/2;
        g=(g*g)%n;
    }
    return result;
}