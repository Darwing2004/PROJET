#include <stdio.h>

void decimal_to_base_b ( unsigned int n , unsigned int b ) 
{
    int result;
    while (n!=0)
    {
        result = n%b;
        n = (n-result)/b;
        printf("%d", result);
    }
    printf("\n");
}
