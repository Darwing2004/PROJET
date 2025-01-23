#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#ifndef _MON_MODULE_H
#define _MON_MODULE_H

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
    struct FourmiChimere* oeufs[50];
    int frequence_reproduction;
};

struct GardeRoyaleChimere
{
    struct FourmiChimere base;
    int defense;
    int attaque;

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
  int capacite;
  int fourmisOccupantes;
  struct Salle* enfant;
  struct Salle* frere;
};

struct Ressources
{
    int stockNourriture;
    int stockMateriel;
    int Consommation;
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

struct Fourmiliere
{
    struct Salle* salles;
    int salleCount;
    struct Ressources gestionRessources;
    struct FourmiChimere* occupantes[50];
    int nombresOccupants;
};

struct FourmiChimere* tableau_de_fourmi[5000];//Tableau permettant de classer les fourmis au fur et à mesure qu'elles sont créées
int taille = 0;//taille du tableau en question

#endif



