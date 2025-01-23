#include <stdio.h>
#include <stdlib.h>


unsigned long long DoubleExpo(unsigned long long x, unsigned long long y, unsigned long long a, unsigned long long b, unsigned long long n);
unsigned long long DoubleExpoIterative(unsigned long long x, unsigned long long y, unsigned long long a, unsigned long long b, unsigned long long n);

int main()
{
    unsigned long long x=4;
    unsigned long long y=3;
    unsigned long long a=6;
    unsigned long long b=5;
    unsigned long long n=1467;
    unsigned long long result=DoubleExpo(x, y, a, b,n);
    unsigned long long iterative=DoubleExpoIterative(x,y,a,b,n);
    printf("\nDoubleExpo result : %llu\n", result);
    printf("\nDoubleExpoIterative result: %llu", iterative);
    return 0;
}


unsigned long long DoubleExpo(unsigned long long x, unsigned long long y, unsigned long long a, unsigned long long b, unsigned long long n)
{
    if(a==0 && b==0)
    {
        return 1;
    }
    if(a==1 && b==1)
    {
        return ((x*y)%n);
    }
    if(a%2==0)
    {
        if(b%2==0)
        {
            a=a/2;
            b=b/2;
            return DoubleExpo((x*x)%n,(y*y)%n,a,b,n);
        }
        else
        {
            a=a/2;
            b=(b-1)/2;
            return (y*DoubleExpo((x*x)%n,(y*y)%n,a,b,n)%n);
        }
    }
    else
    {
        if(b%2==0)
        {
            a=(a-1)/2;
            b=b/2;
            return (x*DoubleExpo((x*x)%n,(y*y)%n,a,b,n)%n);
        }
        else
        {
            a=(a-1)/2;
            b=(b-1)/2;
            return (x*y*DoubleExpo((x*x)%n,(y*y)%n,a,b,n)%n);
        }   
    }
}

unsigned long long DoubleExpoIterative(unsigned long long x, unsigned long long y, unsigned long long a, unsigned long long b, unsigned long long n)
{
    unsigned long long result=1;
    x=x%n;
    y=y%n;
    while(a>0 && b>0)
    {
        if(a%2==1 && b%2==1)
        {
            result=(result*x*y)%n;
            a=a/2;
            b=b/2;
            x=(x*x)%n;
            y=(y*y)%n;
        }
        else if(a%2==1 && b%2==0)
        {
            result=(result*x)%n;
            a=a/2;
            b=b/2;
            x=(x*x)%n;
            y=(y*y)%n;
        }
        else if(a%2==0 && b%2==1)
        {
            result=(result*y)%n;
            a=a/2;
            b=b/2;
            x=(x*x)%n;
            y=(y*y)%n;
        }
        else
        {
            a=a/2;
            b=b/2;
            x=(x*x)%n;
            y=(y*y)%n;
        }
    }
    return result;
}