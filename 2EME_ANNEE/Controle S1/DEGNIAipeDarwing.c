#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node1
{
    char value;
    struct Node1 *next;
} Node1;

typedef struct Node2
{
    char direction;
    int shift;
    struct Node2 *next;
    struct Node2 *prev;
} Node2;

typedef struct listechainee
{
    struct Node1 *premier;
    struct Node1 *dernier;
}listechainee;

Node1* creatList1(const char *sentence)
{
    Node1* node;

    int taille = strlen(sentence);

    
    Node1 *temp = ;
    while (temp != NULL)
    {
        printf("*********LISTE %d*********\n", compt++);
        printf("Nom : %s\n", temp->nom);
        printf("Prenom : %s\n", temp->prenom);
        printf("Age = %d\n", temp->age);

        if (temp->nbr_amis == 0)
        {
            printf("Pas d'amis\n");
        }
        else
        {
            printf("Liste d'amis : \n");
            for (int i = 0; i < temp->nbr_amis; i++)
            {
                printf("  ID : %s\n", temp->liste_ami[i]);
            }
        }

        temp = temp->suivant;
        printf("\n");
    }r(int i = 0; i < taille; i++);
    {
        node->value = sentence[i];

        n
    }
    node->value = sentence;

    return node->value;
}
int main()
{
    Node1 *node;
    char lettre = 'a';
    node->value = lettre;
    printf("La lettre est %c", node->value);
}