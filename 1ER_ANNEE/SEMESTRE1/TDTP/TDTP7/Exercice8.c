#include <stdio.h>

void loadWord (char word [50])
{
    printf("Please enter a word (50 char max):\n");
    scanf("%s", word);
    printf("You have entered the word: %s", word);
}

int main ()
{
    char mytabe[50];
    loadWord(mytabe);
    return 0;
}