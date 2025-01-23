#include <stdio.h>

void toUpperCase(char sentence[50])
{
    printf("Please enter a sentence:\n");
    scanf("%[^\n]", sentence);
    int i;
    int temp;
    for (i = 0; i < 50; i++)
    {
        temp = sentence[i];
        if (temp >= 97 && temp <= 122)
        {
            temp = temp - 32;
            sentence[i] = temp;
        }
    }
    printf("%s", sentence);
}

int main()
{
    char myTab[50];
    toUpperCase(myTab);
    return 0;
}