/*************************************************************************
                           Catalogue  -  Répertoire de trajets
                             -------------------
    début                : 13/11/2017
    copyright            : (C) 2017 par Théo Lorette-Froidevaux
			   Anatolii Gasiuk
    e-mail               : theo.lorette-froidevaux@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
typedef struct
{
	char *villeDep;
	char *villeArr;
	char *moyenTransport;

} UnTrajetSimple;
// Regroupe les données nécessaires à la création d'un trajet simple.

typedef struct Element
{
	Trajet *trajet;
	Element *suivant;
} Element;
// Représente un élément d'une liste chainée

typedef struct
{
	Element *Tete;
} ListeChainee;
// Représente le début d'une liste chainée

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
// Représente un ensemble de trajets, pouvant être agrandit, et intègre 
// diverse foctionnalitées de recherche. Gère les interactions avec
// l'utilisateur.
//
//------------------------------------------------------------------------

class Catalogue
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Run();
    // Mode d'emploi : Lance le programme permettant à l'utiisateur
    // d'utiliser l'application par l'intermédiaire d'une petite
    // interface dans la console.
    //
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
    Catalogue ( );
    // Mode d'emploi : Construit un Catalogue vide
    //
    // Contrat :
    //

    virtual ~Catalogue ( );
    // Mode d'emploi : détruit tous les trajets du catalogue puis se 
    // détruit.
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

    void Ajouter (const char *villeDep, const char *villeArr, const char *moyenTransport);
    // Mode d'emploi : Construit et ajoute un trajet simple au catalogue
    // villeDep : la ville de départ
    // villeArr : la ville d'arrivée
    // moyenTransport : le moyen de transport utilisé
    // Contrat : Aucune vérification n'est effectuée
    //

    void Afficher() const;
    // Mode d'emploi : Affiche tous les trajets du catalogue
    //
    // Contrat :
    //

    void Recherche (const char *villeDep, const char *villeArr) const;
    // Mode d'emploi : Recherche et affiche tous les trajets dont la ville
    // de départ est villeDep et la ville d'arriver est villeArr.
    // villeDep : la ville de départ désirée
    // villeArr : la ville d'arrivée désirée 
    // Contrat :
    //

    void Ajouter( const UnTrajetSimple *listeTrajetSimple, unsigned int tailleListe);
    // Mode d'emploi : Construit et ajoute un trajet composé au catalogue.
    // listeTrajetSimple : la liste des informations de chaque trajet simple
    // à ajouter
    // tailleListe : la taille de cette liste
    // Contrat : Aucune vérification n'est effectuée
    //

//----------------------------------------------------- Attributs protégés
    ListeChainee listeTrajets;
};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // CATALOGUE_H

