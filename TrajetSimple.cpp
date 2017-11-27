/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes
#define TAILLE_CHAINE 20
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetSimple::Afficher() const
{
	cout << "De " << villeDepart << " à " << villeArrivee << " en " << moyenTransport << endl;
}

const char* TrajetSimple::getVilleArrivee() const
{
	return villeArrivee;
}

const char* TrajetSimple::getVilleDepart() const
{
	return villeDepart;
} 

//-------------------------------------------- Constructeurs - destructeur

TrajetSimple::TrajetSimple(const char *villeDep, const char *villeArr, const char *moyenTransp)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
	char* newVilleDepart = new char[TAILLE_CHAINE];
	strcpy(newVilleDepart,villeDep);
	villeDepart = newVilleDepart;

	char* newVilleArrivee = new char[TAILLE_CHAINE];
	strcpy(newVilleArrivee,villeArr);
	villeArrivee = newVilleArrivee;

	char* newMoyenTransport = new char[TAILLE_CHAINE];
	strcpy(newMoyenTransport,moyenTransp);
	moyenTransport = newMoyenTransport;

} //----- Fin de TrajetSimple (constructeur de copie)

TrajetSimple::~TrajetSimple ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
delete [] villeDepart;
delete [] villeArrivee;
delete [] moyenTransport;
} //----- Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

