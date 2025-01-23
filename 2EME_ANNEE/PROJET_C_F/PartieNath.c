#include <stdio.h>
#include "definition_fourmis.h"
#include <stdbool.h>
#include <string.h>
#include <time.h>

bool VerifiersaisonPrintemps(const char *season);
void Ajouter_une_fourmi_tableau(struct FourmiChimere *fourmi);

const char *Saison(int jour)
{ // Fonction simulant le cycle de saison en fonction du jour de l'annee

    jour = (jour % 365 == 0) ? 365 : jour % 365;

    if (jour >= 1 && jour <= 79)
    {
        return "Hiver";
    }

    if (jour >= 80 && jour <= 172)
    {
        return "Printemps";
    }

    if (jour >= 173 && jour <= 266)
    {
        return "Ete";
    }

    if (jour >= 267 && jour <= 356)
    {
        return "Automne";
    }
    if (jour >= 356 && jour <= 365)
    {
        return "Hiver";
    }
}

bool VerifiersaisonHiver(const char *season)
{ // Fonctions booléenne verifiant les saisons pour le cycle de vie des fourmis

    if (strcmp(season, "Hiver") == 0)
    {
        return true;
    }
    return false;
}

bool VerifiersaisonPrintemps(const char *season)
{

    if (strcmp(season, "Printemps") == 0)
    {
        return true;
    }
    return false;
}

bool VerifiersaisonEte(const char *season)
{

    if (strcmp(season, "Ete") == 0)
    {
        return true;
    }
    return false;
}

bool VerifiersaisonAutomne(const char *season)
{

    if (strcmp(season, "Automne") == 0)
    {
        return true;
    }
    return false;
}

char *Rechercher_fourmi(Fourmiliere *fourmiliere, char *nom_fourmi)
{ // Fonction recherchant une fourmi en fonction de son nom

    for (int i = 0; i < fourmiliere->nombresOccupants; i++)
    {
        if (strcmp(fourmiliere->fourmis[i].nom, nom_fourmi) == 0)
        {
            return fourmiliere->fourmis[i].nom;
        }
    }
    return NULL;
}

int Distance_evenement()
{
    ExploratriceChimere *fourmi_evenement;
    int distance;
    distance = fourmi_evenement->distanceCompteur;

    int min = 1;   // en kilomètres
    int max = 100; // en kilomètres

    distance = min + rand() % (max - min + 1);

    return distance;
}

void detection_evenement(Evenement *event)
{ // Genere un event de manière aléatoire
    int evenement_aleatoire = rand() % 12;

    if (evenement_aleatoire == 0)
    {
        strcpy(event->type, "Pluie");
        event->impactSante = 0;
        event->impactNourriture = 0;
    }

    else if (evenement_aleatoire == 1)
    {
        strcpy(event->type, "Tempete");
        event->impactSante = 2;
        event->impactNourriture = 5;
    }

    else if (evenement_aleatoire == 2)
    {
        strcpy(event->type, "Sécheresse");
        event->impactSante = 5;
        event->impactNourriture = 5;
    }

    else if (evenement_aleatoire == 3 && Distance_evenement() <= 5)
    {
        strcpy(event->type, "Eruption volcanique");

        event->impactSante = 25 * (6 - Distance_evenement()); // Plus les eruptions volcaniques sont proches plus les degats sont importants et vice-versa
        event->impactNourriture = 20;
    }

    else if (evenement_aleatoire >= 4)
    {
        strcpy(event->type, "Maladie");
        event->impactSante = 20;
        event->impactNourriture = 15;
    }

    else if (evenement_aleatoire >= 5)
    {
        strcpy(event->type, "Normal");
        event->impactSante = 0;
        event->impactNourriture = 0;
    }

    printf("Attention presence de %s \n", event->type);
}

void Cycledeviefourmis(Evenement *event, Fourmiliere *fourmiliere, int jour, int nombre_de_jour_simules)
{
    // Boucle principale pour simuler les jours
    while (jour < nombre_de_jour_simules)
    {
        const char *season = Saison(jour);
        detection_evenement(event);

        // Parcours de toutes les fourmis dans la fourmilière
        for (int i = 0; i < fourmiliere->nombresOccupants; i++)
        {
            FourmiChimere *fourmitemp = &fourmiliere->fourmis[i];

            // Vérifier si la fourmi est encore vivante
            if (fourmitemp->sante <= 0)
            {
                continue;
            }

            // Mise à jour des statistiques en fonction du rôle
            if (strcmp(fourmitemp->role, "SoldatChimere") == 0)
            {
                fourmitemp->age++;
                fourmitemp->role_specifique.soldat.puissanceCombat--;

                if (strcmp(season, "Été") == 0)
                {
                    fourmitemp->sante += 4;
                    fourmitemp->nen += 5;
                }
                else if (strcmp(season, "Hiver") == 0)
                {
                    fourmitemp->sante -= 5;
                }
                else if (strcmp(season, "Automne") == 0)
                {
                    fourmitemp->sante -= 2;
                }
                else if (strcmp(season, "Printemps") == 0)
                {
                    fourmitemp->sante -= 1;
                }
            }
            else if (strcmp(fourmitemp->role, "Ouvriere") == 0)
            {
                fourmitemp->age++;

                if (strcmp(season, "Été") == 0)
                {
                    fourmitemp->sante += 4;
                    fourmitemp->nen += 5;
                }
                else if (strcmp(season, "Hiver") == 0)
                {
                    fourmitemp->sante -= 5;
                }
                else if (strcmp(season, "Automne") == 0)
                {
                    fourmitemp->sante -= 2;
                }
                else if (strcmp(season, "Printemps") == 0)
                {
                    fourmitemp->sante -= 1;
                }
            }
            else if (strcmp(fourmitemp->role, "GardeRoyaleChimere") == 0)
            {
                fourmitemp->age++;
                fourmitemp->role_specifique.gardeRoyale.defense--;
                fourmitemp->role_specifique.gardeRoyale.attaque--;

                if (strcmp(season, "Été") == 0)
                {
                    fourmitemp->sante += 4;
                    fourmitemp->nen += 5;
                }
                else if (strcmp(season, "Hiver") == 0)
                {
                    fourmitemp->sante -= 5;
                }
                else if (strcmp(season, "Automne") == 0)
                {
                    fourmitemp->sante -= 2;
                }
                else if (strcmp(season, "Printemps") == 0)
                {
                    fourmitemp->sante -= 1;
                }
            }
            else if (strcmp(fourmitemp->role, "Exploratrice") == 0)
            {
                fourmitemp->age++;

                if (strcmp(season, "Été") == 0)
                {
                    fourmitemp->sante += 4;
                    fourmitemp->nen += 5;
                }
                else if (strcmp(season, "Hiver") == 0)
                {
                    fourmitemp->sante -= 5;
                }
                else if (strcmp(season, "Automne") == 0)
                {
                    fourmitemp->sante -= 2;
                }
                else if (strcmp(season, "Printemps") == 0)
                {
                    fourmitemp->sante -= 1;
                }
            }

            // Gérer les événements ayant un impact sur la santé
            if (event->impactSante > 0)
            {
                fourmitemp->sante -= event->impactSante;
            }

            // Vérification de la mort
            if (fourmitemp->sante <= 0)
            {
                printf("La fourmi chimère %s du nom de %s est décédée à l'âge de %d ans.\n", fourmitemp->role, fourmitemp->nom, fourmitemp->age);
            }
        }

        // Passage au jour suivant
        jour++;
    }

    printf("Simulation terminée.\n");
}



void ChercherNourriture(Ressources *Ressources)
{ // Type de nourriture selectionné de manière aléatoire

    char *categories[] = {"Hhumain", "fruits", "graines", "insectes"};
    int sante_boost[] = {20, 10, 5, 15};

    int i = rand() % 4;

    strcpy(Ressources->categories, categories[i]);
    Ressources->sante_boost = sante_boost[i];
}

int NourritureOuvriereDynamique(FourmiChimere *fourmi, Ressources *ressources)
{ // Fonction simulant les quantités de nourritures collectées mais a priori Samuel l'a fait
    Ressources * quantiteCollectee;

    if (strcmp(fourmi->role, "Ouvriere") != 0)
    {
        printf("Erreur : La fourmi %s n'est pas une ouvrière.\n", fourmi->nom);
        return quantiteCollectee;
    }

    char nourriture_a_chercher[30];
    int quantite_objectif;

    printf("Entrer le type de nourriture à chercher (ex. : graines, fruits) : ");
    scanf("%s", nourriture_a_chercher);

    printf("Entrer la quantité cible à collecter : ");
    scanf("%d", &quantite_objectif);

    printf("La fourmi ouvrière %s commence sa tâche pour chercher %s.\n", fourmi->nom, nourriture_a_chercher);

    quantiteCollectee->stockNourriture = 0;

    if (strcmp(nourriture_a_chercher, quantiteCollectee->categories) == 0)
    {
        while (quantiteCollectee->categories < quantite_objectif)
        {

            if (strcmp(fourmi->role, "Ouvriere") == 0)
            {
                struct Ouvriere fourmi_ouvriere;
                fourmi_ouvriere.base.sante = fourmi->sante;
                fourmi_ouvriere.base.force = fourmi->force;
                quantiteCollectee.stockNourriture++;

                if (fourmi->force <= 0)
                {
                    printf("La fourmi %s est trop fatiguée pour continuer.\n", fourmi->nom);
                    break;
                }
                fourmi_ouvriere.base.force--;
            }
        }

        printf("La fourmi %s a collecté %d unités de %s.\n",
               fourmi->nom, quantiteCollectee.stockNourriture, nourriture_a_chercher);
    }
    return quantiteCollectee;
}

struct Fourmiliere CreationZone(struct Salle *nouvelleSalle)
{ // Crée une salle ou zone de la fourmilier(jsp si on la garde celle la)

    nouvelleSalle = (struct Salle *)malloc(sizeof(struct Salle));
    struct Fourmiliere zone_fourmiliere;
    nouvelleSalle = zone_fourmiliere.salles;
    int distance_evenement = Distance_evenement();

    printf("Créer une nouvelle salle :\n");
    printf("Entrer l'ID de la salle : ");
    scanf("%d", &nouvelleSalle->id);

    printf("Entrer le type de la salle: ");
    scanf("%s", nouvelleSalle->type);

    printf("Entrer la capacité de la salle : ");
    scanf("%d", &nouvelleSalle->capacite);

    if (distance_evenement < 5)
    {
        nouvelleSalle->capacite--;
    }
    nouvelleSalle->enfant = NULL;
    nouvelleSalle->frere = NULL;

    return zone_fourmiliere;
}

void AjouterSousSalle(struct Fourmiliere parent)
{ // Ajoute une salle ou zone de la fourmilier(jsp si on la garde celle la)
    printf("Ajout d'une sous-salle à la salle ID %d (%s).\n", parent.salles->id, parent.salles->type);
    struct Salle *nouvelle_salle;
    struct Fourmiliere nouvelle_sous_Salle = CreationZone(nouvelle_salle);

    if (parent.salles->enfant == NULL)
    {
        parent.salles->enfant = nouvelle_sous_Salle.salles;
    }
    else
    {
        struct Fourmiliere courante;
        courante.salles = parent.salles->enfant;
        while (courante.salles->frere != NULL)
        {
            courante.salles = courante.salles->frere;
        }
        courante.salles->frere = nouvelle_sous_Salle.salles;
    }

    printf("Sous-salle ajoutée à la salle ID %d.\n", parent.salles->id);
}

void AfficherStructure(struct Salle *salle, int niveau)
{
    if (salle == NULL)
        return;

    for (int i = 0; i < niveau; i++)
    {
        printf("  ");
    }

    printf("- Salle ID: %d, Type: %s, Capacité: %d\n", salle->id, salle->type, salle->capacite);

    AfficherStructure(salle->enfant, niveau + 1);
    AfficherStructure(salle->frere, niveau);
}

void MenuPrincipal()
{ // Menu principal: choix de 1 a 7. Certains comme le 4 et le 5 seront surement echangées à la place de vos fonctions
    printf("\n=== Menu Principal ===\n");
    printf("1. Creer une nouvelle fourmi\n");
    printf("2. Gerer le cycle de vie d'une fourmi\n");
    printf("3. Reproduire la reine\n");
    printf("4. Ajouter une salle à la fourmiliere\n");
    printf("5. Afficher l'etat de la fourmiliere\n");
    printf("6. Recherche d'une fourmi\n");
    printf("7. Quitter\n");
    printf("Votre choix : \n");
}

int main()
{
    srand(time(NULL));

    int jour_global = 1;
    struct Fourmiliere fourmilliere;
    int fourmi_id = 0;

    struct ReineChimere reine = {
        .base = {1, "Reine Chimera Ant", "Reine", 5, 1000, 90, 5, 1000},
        .oeufs = 0,
        .frequence_reproduction = 30};

    char choix;
    do
    {
        MenuPrincipal();
        scanf(" %c", &choix);

        switch (choix)
        {
        case '1':
        {
            struct FourmiChimere *nouvellefourmi = malloc(sizeof(struct FourmiChimere));
            if (nouvellefourmi == NULL)
            {
                printf("Erreur d'allocation de mémoire.\n");
                break;
            }

            printf("Creation d'une nouvelle fourmi :\n");
            printf("Entrer le nom de la fourmi : ");
            scanf("%29s", nouvellefourmi->nom); // Limite à 29 caractères pour éviter les débordements
            printf("Entrer le role de la fourmi (Ouvriere, SoldatChimere, GardeRoyaleChimere, Exploratrice) : ");
            scanf("%19s", nouvellefourmi->role); // Limite à 19 caractères
            printf("Entrer le niveau de nen de la fourmi : ");
            scanf("%d", &nouvellefourmi->nen);
            printf("Entrer la sante de la fourmi : ");
            scanf("%d", &nouvellefourmi->sante);
            nouvellefourmi->id = fourmi_id++;

            printf("Fourmi creee :\nID:%d\nNom=%s\nRole=%s\nSante=%d\n", nouvellefourmi->id,
                   nouvellefourmi->nom, nouvellefourmi->role, nouvellefourmi->sante);

            Ajouter_une_fourmi_tableau(nouvellefourmi);
            break;
        }
        case '2':
        {
            struct FourmiChimere *fourmi;
            char nom_fourmi_recherche[50];
            int nombre_de_jour_a_simuler;

            printf("Entrez le nom de la fourmi recherchée: ");
            scanf("%s", &nom_fourmi_recherche);

            printf("Entrez le nombre de jours à simuler: ");
            scanf("%s", &nombre_de_jour_a_simuler);

            Cycledeviefourmis(&reine, fourmi, jour_global, nom_fourmi_recherche, nombre_de_jour_a_simuler);
            break;
        }
        case '3':
        {
            Détection_evenement(); // simule aleatoirement un event
            break;
        }
        case '4':
        {
            AjouterSousSalle(fourmilliere);
            break;
        }
        case '5':
        {
            int level;
            scanf("%d", &level);
            AfficherStructure(fourmilliere.salles, level);
            break;
        }
        case '6':
        {
            struct FourmiChimere *fourmi_recherche;
            char nom_fourmi_recherche[50];
            printf("Entrez le nom de la fourmi recherchée: ");
            scanf("%s", &nom_fourmi_recherche);
            fourmi_recherche = Rechercher_fourmi(nom_fourmi_recherche);

            if (fourmi_recherche != NULL)
            {
                printf("Voici les informations de la fourmi du nom de %s que vous recherchiez:\n Age:%d\n Points de vie:%d\n Intelligence:%d\n Role:%s\n Id:%d\n ", fourmi_recherche->nom, fourmi_recherche->age, fourmi_recherche->sante, fourmi_recherche->intelligence, fourmi_recherche->role, fourmi_recherche->id);
            }

            else
            {
                printf("Pas de fourmi trouvee\n");
            }
            break;
        }
        case '7':
            printf("Fermeture du programme.\n");
            break;
        }
    } while (choix != '7');
    free(fourmilliere.salles);
    return 0;
}
