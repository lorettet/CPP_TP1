/*************************************************************************
                           TrajetCompose  -  Trajet composé de sous-trajets
                             -------------------
    début                : 13/11/2017
    copyright            : (C) 2017 par Théo Lorette-Froidevaux
			   Anatolii Gasiuk
    e-mail               : theo.lorette-froidevaux@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ----------------
#if ! defined ( TRAJETCOMPOSE_H )
#define TRAJETCOMPOSE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
// Représente un trajet composé d'autres trajets.
//
//------------------------------------------------------------------------

class TrajetCompose : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Afficher() const;
    // Mode d'emploi : Affiche les informations sur le trajet, incluant
    // toutes les escales.
    //
    // Contrat :
    //

    const char* getVilleArrivee() const;
    // Mode d'emploi : Renvoi la ville de départ.
    //
    // Contrat :
    //

    const char* getVilleDepart() const;
    // Mode d'emploi : Renvoi le terminus du trajet.
    //
    // Contrat :
    //



//-------------------------------------------- Constructeurs - destructeur
    TrajetCompose( Trajet** trajets, unsigned int nb);
    // Mode d'emploi : Construit un trajet composé à partir de la liste de
    // trajets passée en paramètre. Les trajets doivent IMPÉRATIVEMENT être 
    // construit dans le tas. Ils ne doivent en aucun cas être delete, c'est
    // le destructeur qui s'en chargera. Le tableau peux lui être static.
    // 
    // Contrat : Aucune vérification n'est effectué sur les données entrantes.
    //

    virtual ~TrajetCompose ( );
    // Mode d'emploi : Détruit chaque trajet puis se détruit.
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
//----------------------------------------------------- Attributs protégés
	Trajet** listeTrajets;
	const int nbTrajets;
};

//-------------------------------- Autres définitions dépendantes de <TrajetCompose>

#endif // TRAJETCOMPOSE_H

