#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure d'un nœud d'arbre
typedef struct TaskNode
{
    char name[50];            // Nom de la tâche
    int priority;             // Priorité de la tâche
    int antsNeeded;           // Nombre de fourmis nécessaires
    int antsAssigned;         // Nombre de fourmis déjà assignées
    struct TaskNode *child;   // Premier enfant (sous-tâches)
    struct TaskNode *sibling; // Frère/sœur au même niveau
} TaskNode;

// Fonction pour créer un nœud de tâche
TaskNode *createTaskNode(const char *name, int priority, int antsNeeded)
{
    TaskNode *node = (TaskNode *)malloc(sizeof(TaskNode));
    strcpy(node->name, name);
    node->priority = priority;
    node->antsNeeded = antsNeeded;
    node->antsAssigned = 0;
    node->child = NULL;
    node->sibling = NULL;
    return node;
}

// Fonction pour ajouter une sous-tâche
void addSubTask(TaskNode *parent, TaskNode *child)
{
    if (parent->child == NULL)
    {
        parent->child = child; // Si aucun enfant, on ajoute directement
    }
    else
    {
        TaskNode *current = parent->child;
        while (current->sibling != NULL)
        {
            current = current->sibling; // On va jusqu'au dernier frère/sœur
        }
        current->sibling = child; // On ajoute l'enfant à la fin
    }
}

// Fonction pour afficher l'arbre (débogage)
void printTaskTree(TaskNode *node, int depth)
{
    if (node == NULL)
        return;
    for (int i = 0; i < depth; i++)
        printf("  "); // Indentation
    printf("- %s (Priorité: %d, Besoin: %d, Assignées: %d)\n",
           node->name, node->priority, node->antsNeeded, node->antsAssigned);
    printTaskTree(node->child, depth + 1); // Appel récursif pour les enfants
    printTaskTree(node->sibling, depth);   // Appel récursif pour les frères/sœurs
}

// Exemple d'utilisation
int main()
{
    // Créer la tâche principale
    TaskNode *root = createTaskNode("Collecte de nourriture", 1, 5);

    // Créer les sous-tâches
    TaskNode *subTask1 = createTaskNode("Trouver une source de nourriture", 1, 2);
    TaskNode *subTask2 = createTaskNode("Transporter la nourriture au nid", 1, 3);

    // Ajouter les sous-tâches à la tâche principale
    addSubTask(root, subTask1);
    addSubTask(root, subTask2);

    // Afficher l'arbre
    printf("Arbre des tâches :\n");
    printTaskTree(root, 0);

    return 0;
}
