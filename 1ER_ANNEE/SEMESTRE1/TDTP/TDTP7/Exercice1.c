#include <stdio.h>
#define Nlong 10

int main()
{
    int Tab[Nlong] = {10, 20, 30, 40};

    for (int i = 0; i <Nlong;  i++)
    {
        printf("%d ", Tab[i]);
    }
    return 0;
}