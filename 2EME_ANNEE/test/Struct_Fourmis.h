#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#ifndef _MON_MODULE_H
#define _MON_MODULE_H

#define TAILLE_INITIAL 13
// Définition des rôles possibles pour une fourmi
typedef enum
{
    ENFANT,
    OUVRIERE,
    SOLDAT,
    REINE,
    MALE,
    EXPLORATRICE,
    GARDE_ROYAL,
    VIEILLE,
} RoleChimere;

struct FourmiChimere
{
    int id;
    char nom[30];
    char role[20];
    int age;
    int force;
    int intelligence;
    int nen;
    int sante;
};

struct ReineChimere
{
    struct FourmiChimere base;
    struct FourmiChimere *oeufs[50];
    int frequence_reproduction;
};

struct GardeRoyaleChimere
{
    struct FourmiChimere base;
    int defense;
    int attaque;
    int nenSpécial;
};

struct SoldatChimere
{
    struct FourmiChimere base;
    int puissanceCombat;
    int endurance;
};

struct Ouvriere
{
    struct FourmiChimere base;
    int nourritureCollect;
    int tacheAccompli;
};

struct ExploratriceChimere
{
    struct FourmiChimere base;
    int distanceCompteur;
    int découvertes;
};

struct Salle
{
    int id;
    char type[20];
    int capacité;
    int fourmisOccupantes;
    struct Salle *enfant;
    struct Salle *frere;
};

struct Ressources
{
    int stockNourriture; // quantité actuelle de nourriture dans la colonie
    int stockMateriel;   // quantité actuelle de matariel dans la colonie
    int Consommation;    // suit combien de nourriture a été consommé
    char categories[20];
    int sante_boost;
    int portions;
};

struct Evenement
{
    char type[50];
    int impactNourriture;
    int impactSante;
    int impactFourmi;
};

struct OccupationSalle
{
    int salleid;
    struct FourmiChimere *occupantes[50];
    int nombresOccupants;
};

struct Fourmiliere
{
    struct Salle *salles;
    int salleCount;
    struct Ressources gestionRessources;
    struct Fourmichimere *occupante[50];
    int nombresOccupants;
};

struct FourmiChimere *tableau_de_fourmi[5000]; // Tableau permettant de classer les fourmis au fur et à mesure qu'elles sont créées
int taille = 0;                                // taille du tableau en question

struct GestionColonies
{
    struct Fourmiliere *colonies;
    int nombreColonies;
};

struct ChampAgricole
{
    int id;
    int productionParJour;
    int capaciteMax;
    int nourritureStockee;
};

struct ProjetConstruction
{
    char type[20];
    int materielNecessaire;
    int progression;
};

void ajouterNourriture(struct Ressources *ressources, int quantite);
bool consommerNourriture(struct Ressources *ressources, int quantite);
void simulerConsommation(struct Ressources *ressources, struct FourmiChimere *fourmis, int nombreDeFourmis);
struct Fourmiliere creerColonie(int nombreSalles, int nombreReines);
struct GestionColonies creerGestionColonies(int nombreColonies, int nombreSalles, int nombreReines);
void afficherGestionColonies(struct GestionColonies *gestion);
void creerChamp(struct ChampAgricole *champ, int id, int production, int capacite);
void produireNourriture(struct ChampAgricole *champ);
void recolterNourriture(struct ChampAgricole *champ, struct Ressources *ressources);
void demarrerProjet(struct ProjetConstruction *projet, const char *type, int materielNecessaire);
bool avancerProjet(struct ProjetConstruction *projet, struct Ressources *ressources);
void afficherProjet(struct ProjetConstruction *projet);

#endif
