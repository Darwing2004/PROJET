#include <stdio.h>

void loadSentence(char sentence[50])
{
    printf("Please enter a sentence (50 char max):\n");
    scanf("%[^\n]", sentence);  
    printf("You have entered the sentence:%s", sentence);
}

int main ()
{
    char myTabe[50];
    loadSentence(myTabe);
    return 0;
}