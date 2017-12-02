/*************************************************************************
                           Trajet  -  Classe abstraite
                             -------------------
    début                : 13/11/2017
    copyright            : (C) 2017 par Théo Lorette-Froidevaux
			   Anatolii Gasiuk
    e-mail               : theo.lorette-froidevaux@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if ! defined ( TRAJET_H )
#define TRAJET_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
// Contient les méthodes de base devant être implémentées dans des classes
// représentant des trajets.
//
//------------------------------------------------------------------------

class Trajet
{

//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual void Afficher() const = 0;
    // Mode d'emploi : Affiche les caractéristique du trajet
    //
    // Contrat :
    //
	
    virtual const char* getVilleDepart() const =0;
    // Mode d'emploi : Renvoie la ville de départ du trajet
    //
    // Contrat :
    //

    virtual const char* getVilleArrivee() const =0;
    // Mode d'emploi : Renvoie le terminus du trajet
    //
    // Contrat :
    //

    virtual ~Trajet(){}
    // Mode d'emploie : détruit le trajet
    //
    // Contrat :
    //

};

#endif // TRAJET_H

