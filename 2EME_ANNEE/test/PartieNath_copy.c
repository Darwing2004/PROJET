#include <stdio.h>
#include "Struct_Fourmis.h"
#include <stdbool.h>
#include <string.h>
#include <time.h>

bool VerifiersaisonPrintemps(const char *season);
void Ajouter_une_fourmi_tableau(struct FourmiChimere *fourmi);

const char *Saison(int jour)
{ // Fonction simulant le cycle de saison en fonction du jour de l'an

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

struct FourmiChimere Cyclereproductionreine(struct ReineChimere *reine, int *jour)
{ // Reproduction du nombre d'oeufs de la reine mais a priori Darwing l'a fait donc on prendra sa fonction
    const char *season = Saison(*jour);

    if (VerifiersaisonPrintemps(season) == 1)
    { 
        reine->frequence_reproduction = 30; // La reine pond plus d'oeufs au printemps
    }
    else
    {
        reine->frequence_reproduction = 10;
    }

    int joursponte = 7;
    int nombreoeuf = 0;

    for (int i = 0; i < reine->frequence_reproduction; i++)
    {
        if (joursponte <= 0)
        {

            joursponte = 7;
            
            reine->oeufs[nombreoeuf] = nouveloeuf;
            nouvellefourmi = nouveloeuf;
            nouvellefourmi->id = i + 1;
            nouvellefourmi->age = 0;
            nouvellefourmi->sante = 100;
            nombreoeuf++; // Je souhaitais retourner le nombre d'oeufs pondus par la reine
            break;
        }
        joursponte--;
    }
    struct FourmiChimere fourmi = *nouvellefourmi;

    return fourmi;
}

void Ajouter_une_fourmi_tableau(struct FourmiChimere *fourmi)
{ // Ajoute la fourmi créée dans le main au tableau

    if (taille >= 1000)
    {
        printf("Erreur : Le tableau de fourmis est plein !\n");
        return;
    }
    tableau_de_fourmi[taille++] = fourmi; // Ajoute la fourmi et incrémente la taille
}

struct FourmiChimere *Rechercher_fourmi(const char *nom_fourmi)
{ // Fonction recherchant une fourmi en fonction de son nom

    for (int i = 0; i < taille; i++)
    {
        if (strcmp(tableau_de_fourmi[i]->nom, nom_fourmi) == 0)
        {
            return tableau_de_fourmi[i];
        }
    }
    return NULL;
}

int Distance_evenement()
{
    struct ExploratriceChimere fourmi_evenement;
    int distance;
    distance = fourmi_evenement.distanceCompteur;

    int min = 1;   // en kilomètres
    int max = 100; // en kilomètres

    distance = min + rand() % (max - min + 1);

    return distance;
}

struct Evenement Détection_evenement()
{ // Genere un evenement de manière aléatoire
    struct Evenement evenement;
    int evenement_aleatoire = rand() % 12;

    if (evenement_aleatoire == 0)
    {
        strcpy(evenement.type, "Pluie");
        evenement.impactSante = 0;
        evenement.impactNourriture = 0;
    }

    else if (evenement_aleatoire == 1)
    {
        strcpy(evenement.type, "Tempete");
        evenement.impactSante = 2;
        evenement.impactNourriture = 5;
    }

    else if (evenement_aleatoire == 2)
    {
        strcpy(evenement.type, "Sécheresse");
        evenement.impactSante = 5;
        evenement.impactNourriture = 5;
    }

    else if (evenement_aleatoire == 3 && Distance_evenement() <= 5)
    {
        strcpy(evenement.type, "Eruption volcanique");

        evenement.impactSante = 25 * (6 - Distance_evenement()); // Plus les eruptions volcaniques sont proches plus les degats sont importants et vice-versa
        evenement.impactNourriture = 20;
    }

    else if (evenement_aleatoire >= 4)
    {
        strcpy(evenement.type, "Maladie");
        evenement.impactSante = 20;
        evenement.impactNourriture = 15;
    }

    else if (evenement_aleatoire >= 5)
    {
        strcpy(evenement.type, "Normal");
        evenement.impactSante = 0;
        evenement.impactNourriture = 0;
    }

    printf("Attention presence de %s \n", evenement.type);

    return evenement;
}

void Cycledeviefourmis(struct ReineChimere *reine, struct FourmiChimere *fourmi, int *jour, const char *nom_fourmi, int nombre_de_jour_simules)
{ // simule le cycle de vie d'une fourmi en fonction du nom recherche. Les fourmis gagnent des points de santé en ete et en mangeant. Tout dépend des saisons et des evenements egalement

    struct Evenement evenement = Détection_evenement();
    const char *season = Saison(*jour);

    for (int i = 0; i < taille; i++)
    {
        if (strcmp(tableau_de_fourmi[i]->nom, nom_fourmi) == 0)
        {
            tableau_de_fourmi[i] = fourmi;
        }
    }
    struct SoldatChimere fourmi1; // les 4 types de fourmis (numerotées de 1 à 4)
    struct Ouvriere fourmi2;
    struct GardeRoyaleChimere fourmi3;
    struct ExploratriceChimere fourmi4;

    int an = 0; // durée de la simulation en annee

    while (fourmi->sante > 0 && jour != nombre_de_jour_simules)
    {
        if ((*jour) % 365 == 0)
        {

            if (strcmp(fourmi->role, "SoldatChimere") == 0)
            {

                fourmi1.base.age = fourmi->age;
                fourmi1.base.sante = fourmi->sante;
                fourmi1.base.force = fourmi->force;
                fourmi1.endurance--;
                fourmi1.puissanceCombat--;

                if (strcmp(season, "Hiver") == 0)
                {

                    break;
                }
                else if (strcmp(season, "Printemps") == 0)
                {
                    fourmi1.base.sante -= 1;

                    break;
                }
                else if (strcmp(season, "Été") == 0)
                {
                    fourmi1.base.sante += 4;
                    fourmi1.base.force += 5;

                    break;
                }
                else if (strcmp(season, "Automne") == 0)
                {
                    fourmi1.base.sante -= 2;

                    break;
                }

                if (evenement.impactSante == 20)
                {
                    fourmi1.base.sante -= evenement.impactSante;
                    break;
                }
                else if (evenement.impactSante == 5)
                {
                    fourmi1.base.sante -= evenement.impactSante;
                    break;
                }
                else if (evenement.impactSante == 2)
                {
                    fourmi1.base.sante -= evenement.impactSante;
                    break;
                }
                else if (evenement.impactSante >= 25)
                {
                    fourmi1.base.sante -= evenement.impactSante;
                    break;
                }
                if (fourmi->sante <= 0)
                {
                    fourmi->sante = 0;

                    break;
                }
            }

            if (strcmp(fourmi->role, "Ouvriere") == 0)
            {

                fourmi2.base.age = fourmi->age;
                fourmi2.base.sante = fourmi->sante;
                fourmi2.base.force = fourmi->force;

                if (strcmp(season, "Hiver") == 0)
                {
                    fourmi2.base.sante -= 5;

                    break;
                }
                else if (strcmp(season, "Printemps") == 0)
                {
                    fourmi2.base.sante -= 1;

                    break;
                }
                else if (strcmp(season, "Été") == 0)
                {
                    fourmi2.base.sante += 4;
                    fourmi2.base.force += 5;

                    break;
                }
                else if (strcmp(season, "Automne") == 0)
                {
                    fourmi2.base.sante -= 2;

                    break;
                }

                if (evenement.impactSante == 20)
                {
                    fourmi2.base.sante -= evenement.impactSante;
                    break;
                }
                else if (evenement.impactSante == 5)
                {
                    fourmi2.base.sante -= evenement.impactSante;
                    break;
                }
                else if (evenement.impactSante == 2)
                {
                    fourmi2.base.sante -= evenement.impactSante;
                    break;
                }
                else if (evenement.impactSante >= 25)
                {
                    fourmi2.base.sante -= evenement.impactSante;
                    break;
                }
                if (fourmi->sante <= 0)
                {
                    fourmi->sante = 0;
                    printf("La fourmi chimère %s du nom de %s est décédée à %d", fourmi->role, fourmi->nom, fourmi2.base.age);
                    break;
                }
            }

            if (strcmp(fourmi->role, "GardeRoyaleChimere") == 0)
            {

                fourmi3.base.age = fourmi->age;
                fourmi3.base.sante = fourmi->sante;
                fourmi3.base.force = fourmi->force;
                fourmi3.defense--;
                fourmi3.attaque--;

                if (strcmp(season, "Hiver") == 0)
                {
                    fourmi3.base.sante -= 5;

                    break;
                }
                else if (strcmp(season, "Printemps") == 0)
                {
                    fourmi3.base.sante -= 1;

                    break;
                }
                else if (strcmp(season, "Été") == 0)
                {
                    fourmi3.base.sante += 4;
                    fourmi3.base.force += 5;
                    break;
                }
                else if (strcmp(season, "Automne") == 0)
                {
                    fourmi3.base.sante -= 2;

                    break;
                }

                if (evenement.impactSante == 20)
                {
                    fourmi3.base.sante -= evenement.impactSante;
                    break;
                }
                else if (evenement.impactSante == 5)
                {
                    fourmi3.base.sante -= evenement.impactSante;
                    break;
                }
                else if (evenement.impactSante == 2)
                {
                    fourmi3.base.sante -= evenement.impactSante;
                    break;
                }
                else if (evenement.impactSante >= 25)
                {
                    fourmi3.base.sante -= evenement.impactSante;
                    break;
                }
                if (fourmi->sante <= 0)
                {
                    fourmi->sante = 0;
                    printf("La fourmi chimère %s du nom de %s est décédée à %d", fourmi->role, fourmi->nom, fourmi3.base.age);
                    break;
                }
            }
            if (strcmp(fourmi->role, "Exploratrice") == 0)
            {

                fourmi4.base.age = fourmi->age;
                fourmi4.base.sante = fourmi->sante;
                fourmi4.base.force = fourmi->force;

                if (strcmp(season, "Hiver") == 0)
                {
                    fourmi4.base.sante -= 5;

                    break;
                }
                else if (strcmp(season, "Printemps") == 0)
                {
                    fourmi4.base.sante -= 1;

                    break;
                }
                else if (strcmp(season, "Été") == 0)
                {
                    fourmi4.base.sante += 4;
                    fourmi4.base.force += 5;

                    break;
                }
                else if (strcmp(season, "Automne") == 0)
                {
                    fourmi4.base.sante -= 2;

                    break;
                }

                if (evenement.impactSante == 20)
                {
                    fourmi4.base.sante -= evenement.impactSante;
                    break;
                }
                else if (evenement.impactSante == 5)
                {
                    fourmi4.base.sante -= evenement.impactSante;
                    break;
                }
                else if (evenement.impactSante == 2)
                {
                    fourmi4.base.sante -= evenement.impactSante;
                    break;
                }
                else if (evenement.impactSante >= 25)
                {
                    fourmi4.base.sante -= evenement.impactSante;
                    break;
                }
                if (fourmi->sante <= 0)
                {
                    fourmi->sante = 0;
                    printf("La fourmi chimère %s du nom de %s est décédée à %d", fourmi->role, fourmi->nom, fourmi4.base.age);
                    break;
                }
            }
            fourmi->age++;
            fourmi->sante -= 10;
            fourmi->force--;

            if (strcmp(fourmi->role, "Ouvriere") == 0 && fourmi->age == 20)
            { // Meurent à 20 ans sachant que leurs points de vie sont de max 500
                fourmi->sante = 0;
                printf("La fourmi chimère %s du nom de %s est décédée à %d", fourmi->role, fourmi->nom, fourmi->age);
                break;
            }

            if (strcmp(fourmi->role, "SoldatChimere") == 0 && fourmi->age == 50)
            { // Meurent à 50 ans sachant que leurs points de vie sont de max 1000
                fourmi->sante = 0;
                printf("La fourmi chimère %s du nom de %s est décédée à %d", fourmi->role, fourmi->nom, fourmi->age);
                break;
            }

            if (strcmp(fourmi->role, "GardeRoyaleChimere") == 0 && fourmi->age == 95)
            { // Meurent à 95 ans sachant que leurs points de vie sont de max 6000
                fourmi->sante = 0;
                printf("La fourmi chimère %s du nom de %s est décédée à %d\n", fourmi->role, fourmi->nom, fourmi->age);
                break;
            }

            if (strcmp(fourmi->role, "Exploratrice") == 0 && fourmi->age == 15)
            { // Meurent à 15 ans sachant que leurs points de vie sont de max 100
                fourmi->sante = 0;
                printf("La fourmi chimère %s du nom de %s est décédée à %d\n", fourmi->role, fourmi->nom, fourmi->age);
                break;
            }

            if (fourmi->sante <= 0)
            {
                fourmi->sante = 0;
                printf("La fourmi chimère %s du nom de %s est décédée à %d\n", fourmi->role, fourmi->nom, fourmi->age); // Annonce du deces de la fourmi. RIP la fourmi
                break;
            }
            if (fourmi->sante > 0 && *jour == nombre_de_jour_simules)
            {
                printf("Jour:%d\n An:%d\n Saison:%s\n Informations sur la fourmi:\n Nom:%s\n Age:%d\n Sante:%d\n Role:%s\n ", *jour, an, season, fourmi->nom, fourmi->age, fourmi->sante, fourmi->role);
                break;
            }
            an++;
        }
        (*jour) = (*jour) + 1;
    }
}

struct Ressources ChercherNourriture()
{ // Type de nourriture selectionné de manière aléatoire

    struct Ressources nourriture_trouvee;
    char *categories[] = {"viande", "fruits", "graines", "insectes"};
    int sante_boost[] = {20, 10, 5, 15};

    int i = rand() % 4;

    strcpy(nourriture_trouvee.categories, categories[i]);
    nourriture_trouvee.sante_boost = sante_boost[i];

    return nourriture_trouvee;
}

struct Ressources NourritureOuvriereDynamique(struct FourmiChimere *fourmi)
{ // Fonction simulant les quantités de nourritures collectées mais a priori Samuel l'a fait
    struct Ressources quantiteCollectee;

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

    quantiteCollectee.stockNourriture = 0;

    if (strcmp(nourriture_a_chercher, quantiteCollectee.categories) == 0)
    {
        while (quantiteCollectee.stockNourriture < quantite_objectif)
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
            Détection_evenement(); // simule aleatoirement un evenement
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
