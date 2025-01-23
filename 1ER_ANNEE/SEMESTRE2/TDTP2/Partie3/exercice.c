#include <stdio.h>

unsigned int FIBONACCI_REC_SIMPLE(unsigned int N)
{
    if (N == 0 || N == 1)
    {
        return N;
    }
    return FIBONACCI_REC_SIMPLE(N - 1) + FIBONACCI_REC_SIMPLE(N - 2);
}