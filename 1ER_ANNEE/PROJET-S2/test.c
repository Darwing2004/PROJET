#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <ctype.h> // Pour la fonction isdigit()

#define BASE 10

typedef struct
{
    int base;
    int *digits;
    int size;
    bool sign;
} BigInt;

void initializeBigIntFromString(BigInt *bigInt, const char *str, int base)
{
    if (bigInt == NULL || str == NULL)
        return;

    int length = strlen(str);
    int startIndex = 0;

    bigInt->base = base;  // Définir la base
    bigInt->sign = false; // Défaut à positif

    // Vérifier si le nombre est négatif
    if (str[0] == '-')
    {
        bigInt->sign = true;
        startIndex = 1; // Commencer à lire les chiffres après le signe
    }

    // Allocation de mémoire pour les chiffres (nombre de chiffres = longueur de la chaine - startIndex)
    bigInt->size = length - startIndex;
    bigInt->digits = malloc(bigInt->size * sizeof(int));
    if (bigInt->digits == NULL)
    {
        fprintf(stderr, "Erreur d'allocation m�moire\n");
        return;
    }

    // Convertir chaque caractère en chiffre et les stocker dans `digits`
    for (int i = 0; i < bigInt->size; i++)
    {
        char c = str[startIndex + i];
        if (isdigit(c))
        {
            bigInt->digits[i] = c - '0'; // Convertir le caractère en chiffre entier
        }
        else
        {
            fprintf(stderr, "Caractère invalide '%c' dans la chaine.\n", c);
            free(bigInt->digits);
            bigInt->digits = NULL;
            bigInt->size = 0;
            return;
        }
    }
}

void printBigInt(const BigInt *bigInt)
{
    if (bigInt == NULL || bigInt->digits == NULL)
    {
        printf("BigInt invalide (NULL).\n");
        return;
    }

    if (bigInt->sign)
    {
        printf("-");
    }

    for (int i = 0; i < bigInt->size; i++)
    {
        printf("%d", bigInt->digits[i]);
    }
    printf("\n");
}

bool egal(const BigInt *A, const BigInt *B)
{
    // On compare les bases des deux BigInt
    if (A->base != B->base)
    {
        return false;
    }

    // On compare la taille des deux
    if (A->size > B->size || A->size < B->size)
    {
        return false;
    }

    if (A->sign != B->sign)
    {
        return false;
    }

    // On compare les digits des deux BigInt
    for (int i = A->size - 1; i >= 0; i--)
    {
        if (A->digits[i] != B->digits[i])
        {
            return false;
        }
    }
    return true;
}

bool inferieur(const BigInt *A, const BigInt *B)
{
    if (A->size < B->size)
    {
        return true;
    }
    else
    {
        return false;
    }

    for (int i = 0; i > A->size - 1; i++)
    {
        if (A->digits[i] < B->digits[i])
        {
            return true;
        }
    }

    return false;
}

BigInt Addition(const BigInt *A, const BigInt *B)
{
    BigInt resultAdd;

    // On compare les base des deux BigInt et on initialise la base de result
    if (A->base != B->base)
    {
        printf("Les bases des nombres ne correspondent pas\n");
        resultAdd.size = 0;
        resultAdd.base = 0;
        resultAdd.sign = false;
        return resultAdd;
    }
    resultAdd.base = A->base;

    // On initialise la taille de result
    if (A->size > B->size)
    {
        resultAdd.size = A->size + 1;
    }
    else
    {
        resultAdd.size = B->size + 1;
    }

    // On initialise le nombre de digit de result
    resultAdd.digits = malloc(resultAdd.size * sizeof(int));
    if (resultAdd.digits == NULL)
    {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }
    // On initialise le signe de result
    resultAdd.sign = false;

    // On remplie de 0 resultAdd.digits
    for (int i = 0; i < resultAdd.size; i++)
    {
        resultAdd.digits[i] = 0;
    }

    int retenue = 0;
    int A_i = A->size - 1;
    int B_i = B->size - 1;
    int result_i = resultAdd.size - 1;

    while (A_i >= 0 || B_i >= 0 || retenue > 0)
    {
        if (A_i < 0)
        {
            A->digits[A_i] = 0;
        }

        if (B_i < 0)
        {
            B->digits[B_i] = 0;
        }

        resultAdd.digits[result_i] = A->digits[A_i] + B->digits[B_i] + retenue;

        if (resultAdd.digits[result_i] >= 10)
        {
            resultAdd.digits[result_i] = resultAdd.digits[result_i] % 10;
            retenue = 1;
        }
        else
        {
            retenue = 0;
        }

        A_i--;
        B_i--;
        result_i--;
    }

    // On décale tout à gauche si il reste un 0 à gauche
    while (resultAdd.digits[0] == 0)
    {
        memmove(resultAdd.digits, resultAdd.digits + 1, (resultAdd.size - 1) * sizeof(int));
        resultAdd.size--;
    }

    return resultAdd;
}

BigInt Soustraction(const BigInt *A, const BigInt *B)
{
    BigInt resultSou;

    // On compare la base des deux BigInt et on initialise la base de result
    if (inferieur(A, B))
    {
        resultSou.size = 0;
        resultSou.base = BASE;
        resultSou.sign = false;
        return resultSou;
    }
    resultSou.base = A->base;
    resultSou.size = A->size;

    // On vérifie le signe des deux BigInt
    if (A->sign == true)
    {
        printf("Le signe de A n'est pas positif !\n");
        resultSou.size = 0;
        resultSou.base = 0;
        resultSou.sign = false;
        return resultSou;
    }
    if (B->sign == true)
    {
        printf("Le signe de B n'est pas positif !\n");
        resultSou.size = 0;
        resultSou.base = 0;
        resultSou.sign = false;
        return resultSou;
    }

    resultSou.digits = malloc(resultSou.size * sizeof(int));
    if (resultSou.digits == NULL)
    {
        fprintf(stderr, "Erreur d'allocation memoire\n");
        exit(EXIT_FAILURE);
    }

    // On initialise le signe du résultat
    resultSou.sign = false;

    for (int i = 0; i < resultSou.size; i++)
    {
        resultSou.digits[i] = 0;
    }

    int retenue = 0;
    int A_i = A->size - 1;
    int B_i = B->size - 1;
    int result_i = resultSou.size - 1;

    while (A_i >= 0 || B_i >= 0)
    {
        if (A_i < 0)
        {
            A->digits[A_i] = 0;
        }

        if (B_i < 0 && retenue == 0)
        {
            B->digits[B_i] = 0;
        }

        if (A->digits[A_i] < B->digits[B_i])
        {
            resultSou.digits[result_i] = (A->digits[A_i] + 10) - B->digits[B_i];
            retenue = 1;
            B->digits[B_i - 1] = (B->digits[B_i - 1] + retenue);
        }
        else
        {
            resultSou.digits[result_i] = A->digits[A_i] - B->digits[B_i];
            retenue = 0;
        }

        A_i--;
        B_i--;
        result_i--;
    }

    while (resultSou.digits[0] == 0)
    {
        memmove(resultSou.digits, resultSou.digits + 1, (resultSou.size - 1) * sizeof(int));
        resultSou.size--;
    }

    return resultSou;
}

BigInt Multiplication(const BigInt *A, const BigInt *B)
{
    BigInt resultMult;
    BigInt temp;

    // On vérifie les bases des deux entiers
    if (A->base != B->base)
    {
        printf("Les bases des nombres ne correspondent pas\n");
        resultMult.size = 0;
        resultMult.base = 0;
        resultMult.sign = false;
        return resultMult;
    }
    resultMult.base = A->base;
    temp.base = A->base;

    // On déclare la taille de resultMult
    resultMult.size = A->size + B->size + 1;
    temp.size = A->size + B->size + 1;

    // On déclare le signe de resultMult
    resultMult.sign = false;
    temp.sign = false;

    // On initialise les tableau temporel et resul
    resultMult.digits = malloc(resultMult.size * sizeof(int));
    if (resultMult.digits == NULL)
    {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }

    temp.digits = malloc(temp.size * sizeof(int));
    if (temp.digits == NULL)
    {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }

    // On remplie de 0 resultMult.size
    for (int i = 0; i < resultMult.size; i++)
    {
        resultMult.digits[i] = 0;
        temp.digits[i] = 0;
    }

    int j = 0;
    int retenue = 0;
    int A_i = A->size - 1;
    int B_i = B->size - 1;
    int result_i = resultMult.size - 1;

    while (B_i >= 0)
    {
        while (A_i >= 0 || retenue > 0)
        {
            if (A_i < 0)
            {
                A->digits[A_i] = 0;
            }

            temp.digits[result_i] = B->digits[B_i] * A->digits[A_i] + retenue;
            if (temp.digits[result_i] >= 10)
            {
                temp.digits[result_i] = temp.digits[result_i] % 10;
                retenue = 1;
            }
            else
            {
                retenue = 0;
            }

            A_i--;
            result_i--;
        }

        resultMult = Addition(&temp, &resultMult);
        retenue = 0;
        A_i = A->size - 1;
        j++;
        result_i = resultMult.size - 1 - j;

        for (int i = 0; i < resultMult.size; i++)
        {
            temp.digits[i] = 0;
        }
        B_i--;
    }

    while (resultMult.digits[0] == 0)
    {
        memmove(resultMult.digits, resultMult.digits + 1, (resultMult.size - 1) * sizeof(int));
        resultMult.size--;
    }
    return resultMult;
}


int main()
{
    const char *numberStrA = "9999";
    const char *numberStrB = "664";

    // BigInt
    BigInt nbrA;
    BigInt nbrB;
    BigInt resultAdd;
    BigInt resultSou;
    BigInt resultMult;

    // Initialisation
    initializeBigIntFromString(&nbrA, numberStrA, BASE);
    initializeBigIntFromString(&nbrB, numberStrB, BASE);

    resultAdd = Addition(&nbrA, &nbrB);
    resultSou = Soustraction(&nbrA, &nbrB);
    resultMult = Multiplication(&nbrA, &nbrB);

    // ADDITION
    printf("\nA=");
    printBigInt(&nbrA);
    printf("B=");
    printBigInt(&nbrB);
    printf("ADDITION=");
    printBigInt(&resultAdd);

    // SOUSTRACTION
    printf("\nA=");
    printBigInt(&nbrA);
    printf("B=");
    printBigInt(&nbrB);
    printf("SOUSTRACTION=");
    printBigInt(&resultSou);

    // EGAL
    printf("\nA=");
    printBigInt(&nbrA);
    printf("B=");
    printBigInt(&nbrB);
    printf("EGAL=");
    printf("%s\n", egal(&nbrA, &nbrB) ? "true" : "false");

    // INFERIEUR
    printf("\nA=");
    printBigInt(&nbrA);
    printf("B=");
    printBigInt(&nbrB);
    printf("INFERIEUR=");
    printf("%s\n", inferieur(&nbrA, &nbrB) ? "true" : "false");

    // MULTIPLICATIONNAIVE
    printf("\nA=");
    printBigInt(&nbrA);
    printf("B=");
    printBigInt(&nbrB);
    printf("MULTIPLICATIONNAIVE=");
    printBigInt(&resultMult);

    // Libération de la mémoire
    free(nbrA.digits);
    free(nbrB.digits);
    free(resultAdd.digits);
    free(resultSou.digits);
    free(resultMult.digits);

    return EXIT_SUCCESS;
}
