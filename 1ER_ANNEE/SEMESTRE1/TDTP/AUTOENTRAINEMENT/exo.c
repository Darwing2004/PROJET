#include <stdio.h>

int main ()
{
    int client = 20;
    int commerçant = 15;

    float result;

    result = commerçant - client;

    if (result < 0)
    {
        result = result * -1;
    }

    printf("Le commerçant lui rend %f €", result);
}