#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define AssertNew(ptr) { if (ptr == NULL) { assert(false); abort(); } }

/// @brief Calcule le score associé à une permutation des ibijaux.
/// @param[in] potoos tableau 2D représentant les ibijaux.
/// @param[in] potooCount nombre d'ibijaux (taille de la première dimension).
/// @param[in] topicCount nombre maximal de sujets (taille de la deuxième dimension).
/// @param[in] perm permutation des ibijaux.
/// @return Le score associé à une permutation des ibijaux.

int computeCommonTopicCount(int** potoos, int potooCount, int topicCount, int *perm)
{
    int count;
    for (int i = 0; i < potooCount-1; i++)
    {
        for (int j = 0; j < topicCount; j++)
        {
            if (potoos[perm[i]][j] == 1 && potoos[perm[i+1]][j] == 1)
            {
                count++;
            }
        }
    }
    return count;
}
/// @brief Fonction d'optimisation des ibijaux.
/// @param[in] potoos tableau 2D représentant les ibjiaux.
/// @param[in] potooCount nombre d'ibijaux (taille de la première dimension).
/// @param[in] topicCount nombre maximal de sujets (taille de la deuxième dimension).
/// @param[out] bestPerm meilleure permutation calculée par la fonction.
void optimizePotoos(int** potoos, int potooCount, int topicCount, int* bestPerm)
{
    if (potooCount <= 15)
    {
        for (int i = 0; i < potooCount; i++)
        {
            bestPerm[i] = i;
        }

        srand(time(NULL));
        int temp;


        int scorePerm = 0;
        int scoreTemp = 0;

        int count = 0;

        while (count < 5000000)
        {
            int tab[potooCount];
            for (int i = 0; i < potooCount; i++)
            {
                do
                {
                    tab[i] = rand() % potooCount;
                    temp = 0;
                    for (int j = 0; j < i; j++)
                    {
                        if (tab[i] == tab[j])
                        {
                            temp = 1;
                            break;
                        }
                    }
                } while (temp);
            }

            scorePerm = computeCommonTopicCount(potoos, potooCount, topicCount, bestPerm);
            scoreTemp = computeCommonTopicCount(potoos, potooCount, topicCount, tab);

            if (scorePerm < scoreTemp)
            {
                for (int i = 0; i < potooCount;i++)
                {
                    bestPerm[i] = tab[i];
                }
            }
            count++;
        }

    }
    else {
        for (int i = 0; i < potooCount; i++)
        {
            bestPerm[i] = i;
        }
    }
}

int main()
{
    // Lecture de l'instance
    int potooCount = 0, topicCount = 0;

    int scanCount = scanf("%d %d", &potooCount, &topicCount);
    assert(scanCount == 2);

    int** potoos = (int**)calloc(potooCount, sizeof(int*));
    AssertNew(potoos);

    for (int i = 0; i < potooCount; i++)
    {
        potoos[i] = (int*)calloc(topicCount, sizeof(int));
        AssertNew(potoos[i]);

        for (int j = 0; j < topicCount; j++)
        {
            scanCount = scanf("%d", &(potoos[i][j]));
            assert(scanCount == 1);
        }
    }

    // Calcul de la permutation des ibijaux
    int* perm = (int*)calloc(potooCount, sizeof(int));
    AssertNew(perm);

    optimizePotoos(potoos, potooCount, topicCount, perm);

    // Calcul du score associé
    printf("Score = %d\n", computeCommonTopicCount(potoos, potooCount, topicCount, perm));

    // Libération de la mémoire
    free(perm); perm = NULL;

    for (int i = 0; i < potooCount; i++)
    {
        free(potoos[i]);
    }
    free(potoos); potoos = NULL;

    return EXIT_SUCCESS;
}