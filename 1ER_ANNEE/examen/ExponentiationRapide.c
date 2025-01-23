#include <stdlib.h>
#include <stdio.h>

unsigned long long Puiss_mod(unsigned long long g,unsigned long long  e,unsigned long long  n);


int main()
{
    unsigned long long g=7654321;
    unsigned long long e=999999;
    unsigned long long n=123456789;
    unsigned long long result=Puiss_mod(g,e,n);
    printf("\nResultat: %llu\n", result);
    return 0;
}

unsigned long long  Puiss_mod(unsigned long long g,unsigned long long  e,unsigned long long  n)
{
    if(e==1)
    {
        return g%n;
    }
    if(e%2==0)
    {
        e=e/2;
        return Puiss_mod((g*g)%n,e,n);
    }
    else
    {
        e=(e-1)/2;
        return (g*Puiss_mod((g*g)%n,e,n)%n);
    }
}

