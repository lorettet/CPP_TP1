/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : 13/11/2017
    copyright            : (C) 2017 par Théo Lorette-Froidevaux
			   Anatolii Gasiuk
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetCompose::Afficher() const
{
	for(int i = 0; i<nbTrajets-1; i++)
	{
		listeTrajets[i]->Afficher();
		cout << " - ";
	}
	listeTrajets[nbTrajets-1]->Afficher();
}

const char* TrajetCompose::getVilleArrivee() const
{
	return listeTrajets[nbTrajets-1]->getVilleArrivee();
}

const char* TrajetCompose::getVilleDepart() const
{
	return listeTrajets[0]->getVilleDepart();
} 

//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose ( Trajet** trajets, unsigned int nb ) : nbTrajets(nb)
{
//#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
//#endif
	Trajet** newListeTrajets = new Trajet*[nb];
	for(unsigned int i = 0; i < nb; i++)
	{
		newListeTrajets[i] = trajets[i];
	}
	listeTrajets = (const Trajet**)newListeTrajets;
}


TrajetCompose::~TrajetCompose ( )
{
//#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
//#endif
	for(int i = 0; i<nbTrajets; i++)
	{
		delete listeTrajets[i];
	}
	delete [] listeTrajets;
} //----- Fin de ~Xxx


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
