/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 13/11/2017
    copyright            : (C) 2017 par Théo Lorette-Froidevaux
			   Anatolii Gasiuk
    e-mail               : $EMAIL$
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

typedef struct Element
{
	Trajet *trajet;
	Element *suivant;
} Element;

typedef struct
{
	Element *Tete;
} ListeChainee;
//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
//
//
//------------------------------------------------------------------------

class Catalogue
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	void Run();
    // Mode d'emploi :
    //
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
    Catalogue ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Catalogue ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

	void Ajouter (const char *villeDep, const char *villeArr, const char *moyenTransport);
	void Afficher() const;
	void recherche (const char *villeDep, const char *villeArr) const;
	bool Ajouter( const UnTrajetSimple *listeTrajetSimple, unsigned int tailleListe);
//----------------------------------------------------- Attributs protégés
	ListeChainee listeTrajets;
};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // XXX_H

