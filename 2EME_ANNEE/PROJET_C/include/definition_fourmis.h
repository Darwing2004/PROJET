#ifndef FOURMILIERE_H
#define FOURMILIERE_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE_INITIAL 13

// Définitions des structures pour les rôles spécifiques :
typedef struct
{
    int frequence_reproduction;
    int consommation;
    int nb_oeufs;
} ReineChimere;

typedef struct
{
    int defense;
    int attaque;
    int nenSpécial;
} GardeRoyaleChimere;

typedef struct
{
    int consommation;
    int puissanceCombat;
} SoldatChimere;

typedef struct
{
    int consommation;
    int capacite;
    int nourritureCollect;
    int endurance;
} OuvriereChimere;

typedef struct
{
    int consommation;
    int distanceCompteur;
    int endurance;
    int decouvertes;
} ExploratriceChimere;

// Strcuture générale pour les fourmis
typedef struct FourmiChimere
{
    int id;
    char nom[30];
    char role[50];
    int age;
    int nen;
    int sante;
    int consommation_nourriture;
    union
    {
        OuvriereChimere ouvriere;
        SoldatChimere soldat;
        ReineChimere reine;
        ExploratriceChimere exploratrice;
        GardeRoyaleChimere gardeRoyale;
    } role_specifique;
} FourmiChimere;

// Structure pour gérer les ressources de la fourmilière
typedef struct
{
    int objectif;
    int stockNourriture;
    int stockMateriel;
    int Consommation;
    char categories[50];
    int sante_boost;
    int portions;
} Ressources;

typedef struct
{
    int quantite_nourriture;
} Source_nourriture;

// Structure pour chacune des salles de la fourmilière
typedef struct
{
    int id;
    char type[20];
    int capacite;
    int fourmisOccupantes;
    struct Salle *enfant;
    struct Salle *frere;
} Salle;

// Structure représentant la fourmilière
typedef struct Fourmiliere
{
    FourmiChimere *fourmis;
    Salle *salles;
    int salleCount;
    int nombresOccupants;
    int decouvertes;
    Ressources ressources;
} Fourmiliere;

typedef struct
{
    int nombreColonies;
    Fourmiliere *colonies;
    Ressources *Ressources;
} GestionColonies;

// Structure pour un champ agricole
typedef struct
{
    int productionParJour;
    int capaciteMax;
    int nourritureStockee;
} ChampAgricole;

// Structure pour un projet de construction
typedef struct
{
    char type[30];
    int materielNecessaire;
    int progression;
} ProjetConstruction;

// Structure pour les evenement meteorologique
typedef struct
{
    int distance;
    char type[50];
    int impactNourriture;
    int impactSante;
    int impactFourmi;
} Evenement;

typedef struct Tache
{
    char nom[100];
    struct Tache *sousTaches;
    int nbsousTaches;
    bool valide;
} Tache;

// Prototypes pour les initialisations :
void init_fourmiliere(Fourmiliere *fourmiliere, int taille_initiale);
void initialisation_ressource(Ressources *ressources);
void initialisation(Fourmiliere *fourmiliere, Ressources *ressources, ChampAgricole *champs);

void supprimerFourmi(Fourmiliere *fourmiliere);
void simuler_supprimer_fourmis(Fourmiliere *fourmiliere);

// Prototypes des fonctions pour les roles :
void attribuer_role(FourmiChimere *f);
void afficher_fourmis(Fourmiliere *f);
void simuler_cycle(Fourmiliere *f, int nbr_cycle);

// Prototype pour la Reine :
void simualtion_cycle_reine(Fourmiliere *fourmiliere, int jours);
void simulation_cycle_reine_details(Fourmiliere *fourmiliere);
void vieillir_fourmis(Fourmiliere *f);
void pondre_oeufs(Fourmiliere *f, int jours);

// Prototypes des fonctions pour la simulation de la collecte de nourriture :
void explorer_source(Fourmiliere *fourmiliere);
void objectif_nourriture(Fourmiliere *fourmiliere, Ressources *besoin);
int ChercherNourriture(Fourmiliere *fourmiliere, Source_nourriture **source, Evenement *event, int jours);
void collect_nourriture(Source_nourriture *source, Fourmiliere *Fourmiliere);
void deposer_nourriture(Fourmiliere *fourmiliere, Ressources *besoin);
void simulation_collect_nourriture_details(Fourmiliere *fourmiliere, Ressources *besoin, Evenement *event);
void simulation_chasse(Fourmiliere *fourmiliere, Ressources *ressource, Evenement *event, int jours);

// Prototypes des fonction pour la gestion des ressources :
void ajouterNourriture(Ressources *ressources, int quantite);
bool consommerNourriture(Ressources *ressources, int quantite);
void simulerConsommation(Ressources *ressources, Fourmiliere *fourmilieres);

// Prototypes des fonctions pour la gestion des fourmilières :
Fourmiliere creerColonie(int nombreSalles, int nombreReines);
GestionColonies creerGestionColonies(int nombreColonies, int nombreSalles, int nombreReines);
void afficherGestionColonies(GestionColonies *gestion);

// Prototypes des fonctions pour la gestions des champs agricoles :
void creerChamp(ChampAgricole *champ, Fourmiliere *fourmiliere);
void produireNourriture(ChampAgricole *champ);
void recolterNourriture(ChampAgricole *champ, Ressources *ressources);
void simulation_agricole(ChampAgricole *champs, Ressources *besoin);
void simulation_champs_details(ChampAgricole *champs, Fourmiliere *fourmiliere, Ressources *besoin, int temps);


// Prototypes des foncitons pour la gestion des evenements
const char *Saison(int jour);
bool VerifiersaisonAutomne(const char *season);
bool VerifiersaisonHiver(const char *season);
bool VerifiersaisonPrintemps(const char *season);
bool VerifiersaisonEte(const char *season);

// Prototypes pour le cycle de vie des fourmis
void Cycledeviefourmis(Evenement *event, Fourmiliere *fourmiliere, int jour, int nombre_de_jour_simules);
void detection_evenement(Evenement *event);

// Prototypes pour la simulation de la fourmiliere
void simulation(Fourmiliere *fourmiliere, Ressources *besoin, Evenement *event, ChampAgricole *champs);
int nombre_ouvriere(Fourmiliere *fourmiliere);
int nombre_exploratrice(Fourmiliere *fourmiliere);
int nombre_soldat(Fourmiliere *fourmiliere);
int nombre_male(Fourmiliere *fourmiliere);
int nombre_garde_royal(Fourmiliere *fourmiliere);
int nombre_reine(Fourmiliere *fourmiliere);

//Prototype pour l'arbre de tache :
Tache *cree_tache(const char *nom);
void ajouterSousTache(Tache *tache, Tache *sousTache);
void validerTache(Tache *tache, Ressources *besoin);
void afficheTache(Tache *tache, int niveau);
void libererTache(Tache *tache);
void simulation_gestion_tache(Tache *tache, Ressources *besoin);
void gererStock(Ressources *ressources);



#endif // FOURMILIERE_H
