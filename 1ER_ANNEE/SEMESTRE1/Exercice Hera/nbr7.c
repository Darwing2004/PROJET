#include <stdio.h>

int main()
{
    int i;
    int j;
    int seven;

    scanf("%d", &seven);
    do
    {
        if ((seven + 3) % 10 == 0)
        {
            j++;
            seven = seven / 10;
        }
        else
        {
            seven = seven / 10;
        }
    } while (seven != 0);

    printf("%d nombre(s) de 7", j);
}