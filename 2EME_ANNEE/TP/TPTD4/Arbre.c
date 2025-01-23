#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Définition de la structure Arbre pour chaque noeud de l'arbre
typedef struct Arbre
{
    int valeur;
    struct Arbre *gauche;
    struct Arbre *droite;
} Arbre;

// On crée une fonction pour pouvoir crée les noeuds de l'arbre
struct Arbre *creation_noeud(int valeur)
{
    struct Arbre *Nv_noeud = malloc(sizeof(Arbre));
    Nv_noeud->valeur = valeur;
    Nv_noeud->gauche = NULL;
    Nv_noeud->droite = NULL;
    return Nv_noeud;
}

// Fonction pour liberer la mémoire d'un arbes A
void liberer_memoire(Arbre *Arbre)
{
    if (Arbre == NULL)
    {
        return;
    }

    liberer_memoire(Arbre->gauche);
    liberer_memoire(Arbre->droite);

    free(Arbre);
}
// 4) Fonction permettant de construire un arbre binaire à partir d'un tableau T donnné.
Arbre *creation_arbre(int *tab, int taille)
{
    if (taille == 0)
    {
        return 0;
    }

    // Tableau des noeuds : on stock dans de tableau les noeuds
    Arbre *noeuds[taille];

    // La fonction créée un noeud si la valeur n'est pas positif et stock le noeud dans tableau de noeuds
    for (int i = 0; i < taille; i++)
    {
        noeuds[i] = (tab[i] != -1) ? creation_noeud(tab[i]) : NULL;
    }

    // On forme l'abre binaire en mettant à jour les pointeurs
    for (int i = 0; i < taille; i++)
    {
        if (noeuds[i] != NULL)
        {
            int i_gauche = 2 * i + 1;
            int i_droite = 2 * i + 2;

            if (i_gauche < taille)
            {
                noeuds[i]->gauche = noeuds[i_gauche];
            }
            if (i_droite < taille)
            {
                noeuds[i]->droite = noeuds[i_droite];
            }
        }
    }

    return noeuds[0];
}

/*Fonction pour construire un arbre à partir d'un tableau en récursif
Arbre *buildTreeFromArray(int *array, int size, int index)
{
    if (index >= size || array[index] == -1)
    {
        return NULL;
    }

    Arbre *root = createNode(array[index]);
    root->left = buildTreeFromArray(array, size, 2 * index + 1);
    root->right = buildTreeFromArray(array, sie, 2 * index + 2);
    return root;
}

*/

// Fonction pour parcourir l'arbre et retourner sa taille
int search_size(Arbre *Arbre)
{
    if (Arbre == NULL)
    {
        return 0;
    }

    return 1 + search_size(Arbre->droite) + search_size(Arbre->gauche);
}

int search_deep(Arbre *Arbre)
{
    if (Arbre == NULL)
    {
        return 0;
    }

    int t_gauche = 1 + search_deep(Arbre->gauche);
    int t_droite = 1 + search_deep(Arbre->droite);

    if (t_droite > t_gauche)
    {
        return t_droite;
    }
    return t_gauche;
}


// 7) Fonction inverse
void inverse_arbre(Arbre *racine)
{
    if (racine == NULL)
    {
        return;
    }

    Arbre *temp = racine->gauche;
    racine->gauche = racine->droite;
    racine->droite = temp;

    inverse_arbre(racine->gauche);
    inverse_arbre(racine->droite);   

}

//8) Fonction booléenne pour tester deux arbres
bool arbre_egale(Arbre *racine1, Arbre *racine2)
{

    if(racine1 == NULL && racine2 == NULL)
    {
        return true;
    }

    if (racine1 == NULL && racine2 != NULL)
    {
        return false;
    }

    if (racine2 == NULL && racine1 != NULL)
    {
        return false;
    }

    if(search_size(racine1) != search_size(racine2))
    {
        return false;
    }

    if(search_deep(racine1) != search_deep(racine2))
    {
        return false;
    }

    return arbre_egale(racine1->gauche, racine2->gauche) && arbre_egale(racine1->droite, racine2->droite);
}

// 9) Affichage préfixe
void affichage_prefix(Arbre *Arbre)
{
    if (Arbre == NULL)
    {
        return;
    }

    printf("%d ", Arbre->valeur);
    affichage_prefix(Arbre->gauche);
    affichage_prefix(Arbre->droite);
}

// 10) Affichage suffixe
void affichage_suffix(Arbre *Arbre)
{
    if(Arbre == NULL)
    {
        return ;
    }   

    affichage_suffix(Arbre->gauche);
    affichage_suffix(Arbre->droite);
    printf("%d ", Arbre->valeur);
}

// 11) Affichage infixe
void affichage_infix(Arbre *Arbre)
{
    if (Arbre == NULL)
    {
        return;
    }

    affichage_infix(Arbre->gauche);
    printf("%d ", Arbre->valeur);
    affichage_infix(Arbre->droite);
}

// 12) Fonction qui parcours l'arbre en largeur
Arbre *toruver_plus_petit(Arbre *racine)
{
    if(racine == NULL)
    {
        return NULL;
    }

    Arbre *result = NULL;

    if(racine->gauche != NULL && racine->droite != NULL)
    {
        if(result == NULL || racine->valeur < result->valeur)
        {
            result = racine;
        }
    }

    Arbre *result_gauche = toruver_plus_petit(racine->gauche);
    Arbre *result_droite = toruver_plus_petit(racine->droite);

    if(result_gauche != NULL && (result == NULL || result->gauche->valeur < result->valeur))
    {
        result = result_gauche;
    }
 
    if (result_droite != NULL && (result == NULL || result_droite->valeur < result->valeur))
    {
        result = result_droite;
    }

    return result;

}

// 13) Fonction qui prend en entrer un arbre binaire et qui retourne le noeud de plus petite valeur et qui possède deux fils
void affichage_plus_petit(Arbre *Arbre)
{
    if (Arbre == NULL)
    {
        return;
    }   


}

int main()
{
    int tab[] = {5, 12, 40, -1, -1, 3, 25};
    int taille = sizeof(tab) / sizeof(tab[0]);

    Arbre *racine = creation_arbre(tab, taille);

    printf("La taille de l'arbre est : %d\n", search_size(racine));
    printf("La profondeur de l'arbre est : %d\n", search_deep(racine));

    printf("Parcours prefixe de l'arbre: ");
    affichage_prefix(racine);
    printf("\n");

    printf("Parcours suffixe de l'arbre: ");
    affichage_suffix(racine);
    printf("\n");

    printf("Parcours infixe de l'arbre: ");
    affichage_infix(racine);
    printf("\n");

    affichage_prefix(toruver_plus_petit(racine));

    liberer_memoire(racine);
    return 0;
}