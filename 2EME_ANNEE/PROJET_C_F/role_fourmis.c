#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "definition_fourmis.h"

// Attribuer un rôle à une fourmi en fonction de sa nen et de son âge
void attribuer_role(FourmiChimere *fourmi)
{
    if (strcmp(fourmi->role, "ENFANT") == 0)
    {
        return;
    }

    if (fourmi->age >= 5)
    {
        if (fourmi->nen <= 60)
        {
            strcpy(fourmi->role, "OUVRIERE");
            fourmi->role_specifique.ouvriere.capacite = 1;
            fourmi->consommation_nourriture = 2;
        }
        else if (fourmi->nen > 60 && fourmi->nen <= 80)
        {
            strcpy(fourmi->role, "SOLDAT");
            fourmi->role_specifique.soldat.puissanceCombat = fourmi->nen;
            fourmi->consommation_nourriture = 5;
        }
        else
        {
            strcpy(fourmi->role, "EXPLORATRICE");
            fourmi->consommation_nourriture = 3;
            fourmi->role_specifique.exploratrice.endurance = 100;
        }
    }
}

