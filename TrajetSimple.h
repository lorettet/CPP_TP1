/*************************************************************************
                           TrajetSimple  -  Trajet entre deux villes.
                             -------------------
    début                : 13/11/2017
    copyright            : (C) 2017 par Théo Lorette-Froidevaux
			   Anatolii Gasiuk
    e-mail               : theo.lorette-froidevaux@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h)
#if ! defined ( TRAJETSIMPLE_H )
#define TRAJETSIMPLE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
// Représente un trajet entre deux villes et indique son moyen de transport
//
//------------------------------------------------------------------------

class TrajetSimple : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Afficher() const;
    // Mode d'emploi : Affiche la ville de départ,la ville d'arrivée et
    // et le moyen de transport utilisé.
    //
    // Contrat :
    //

    const char* getVilleArrivee() const;
    // Mode d'emploi : Renvoi la ville de départ.
    //
    // Contrat :
    //

    const char* getVilleDepart() const;
    // Mode d'emploi : Renvoi la ville d'arrivée.
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    TrajetSimple(const char *villeDep, const char *villeArr, const char *moyenTransp);
    // Mode d'emploi : Construit un trajet simple
    //
    // Contrat : 
    //

    virtual ~TrajetSimple ( );
    // Mode d'emploi : détruit le trajet simple
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    	const char *villeDepart;
	const char *villeArrivee;
	const char *moyenTransport;
};

//-------------------------------- Autres définitions dépendantes de <TrajetSimple>

#endif // TRAJETSIMPLE_H

