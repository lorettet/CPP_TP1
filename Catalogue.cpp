/*************************************************************************
Catalogue  -  description
-------------------
d�but                : 13/11/2017
copyright            : (C) 2017 par Th�o Lorette-Froidevaux
Anatolii Gasiuk
e-mail               : theo.lorette-froidevaux@insa-lyon.fr
*************************************************************************/

//---------- R�alisation de la classe <Catalogue> (fichier Catalogue.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
#include <cstring>


//------------------------------------------------------ Include personnel
#include "Catalogue.h"

//------------------------------------------------------------- Constantes
#define TAILLE_BUFFER_CLAVIER 20
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
bool Catalogue::Ajouter(const char *villeDep, const char *villeArr, const char *moyenTransport)
// Algorithme : Cr�er un objet TrajetSimple et l'ajoute dans la liste chain�e
//
{
	if (strcmp(villeDep, villeArr) == 0)
		return false;

	Element* ptr = new Element;
	ptr->trajet = new TrajetSimple(villeDep, villeArr, moyenTransport);
	ptr->suivant = NULL;
	if (listeTrajets.Tete == NULL)
	{
		listeTrajets.Tete = ptr;
		return true;
	}
	Element* ptrRech = listeTrajets.Tete;
	while (ptrRech->suivant != NULL)
	{
		ptrRech = ptrRech->suivant;
	}
	ptrRech->suivant = ptr;
	return true;
}

bool Catalogue::Ajouter(const UnTrajetSimple *listeTrajetSimple, unsigned int tailleListe)
// Algorithme : pour chaque membre de la liste de UnTrajetSimple, cr�er l'objet TrajetSimple
// associ�. Cr�er l'objet TrajetCompose � partir des objets TrajetSimple et enfin l'ajoute �
// la liste chain�e.
{
	for (unsigned int i = 0; i<tailleListe; i++)
	{
		if (strcmp(listeTrajetSimple[i].villeDep, listeTrajetSimple[i].villeArr) == 0)
			return false;
	}

	Trajet** lesTrajets = new Trajet*[tailleListe];
	for (unsigned int i = 0; i<tailleListe; i++)
	{
		lesTrajets[i] = new TrajetSimple(listeTrajetSimple[i].villeDep, listeTrajetSimple[i].villeArr, listeTrajetSimple[i].moyenTransport);
	}
	Element* elem = new Element;
	elem->suivant = NULL;
	elem->trajet = new TrajetCompose(lesTrajets, tailleListe);
	Element* ptr = listeTrajets.Tete;
	if (ptr == NULL)
	{
		listeTrajets.Tete = elem;
	}
	else {
		while (ptr->suivant != NULL)
			ptr = ptr->suivant;
		ptr->suivant = elem;
	}
	for (unsigned int i = 0; i<tailleListe; i++)
	{
		delete lesTrajets[i];
	}
	delete[] lesTrajets;
	return true;
}

void Catalogue::Afficher() const
// Algorithme : Pour chaque trajet de la liste chain�e, affiche le trajet.
//
{
	if (listeTrajets.Tete == NULL)
	{
		cout << "Aucun trajet planifi�" << endl;
		return;
	}
	Element* ptr = listeTrajets.Tete;
	int i = 1;
	while (ptr != NULL)
	{
		cout << "- Trajet " << i++ << " ------------------------------------------" << endl;
		ptr->trajet->Afficher();
		ptr = ptr->suivant;
	}
}



void Catalogue::Run()
// Algorithme : Affiche la liste d'instructions possible, puis ex�cute l'instruction en fonction
// des donn�es entr�es par l'utilisateur. Se processus est r�p�t� tant que l'utiisateur ne quitte
// pas l'application.
//
{
	cout << "\t\t\t Bonjour, bienvenue dans le GPS de Timtim." << endl << endl;
	cout << "#####################################################################################" << endl;
	cout << "#########               #    #   ######   ##               #   #   ######   #########" << endl;
	cout << "#########               #    #    ####    ##               #   #    ####    #########" << endl;
	cout << "###############   #######    #   # ## #   ########   #######   #   # ## #   #########" << endl;
	cout << "###############   #######    #   ##  ##   ########   #######   #   ##  ##   #########" << endl;
	cout << "###############   #######    #   ######   ########   #######   #   ######   #########" << endl;
	cout << "###############   #######    #   ######   ########   #######   #   ######   #########" << endl;
	cout << "###############   #######    #   ######   ########   #######   #   ######   #########" << endl;
	cout << "#####################################################################################" << endl << endl;

	char villeDep[TAILLE_BUFFER_CLAVIER];
	char villeArr[TAILLE_BUFFER_CLAVIER];
	char moyenTransport[TAILLE_BUFFER_CLAVIER];
	int commande;
	while (true)
	{
		cout << "\t\t\t\tVoici la liste de commandes: " << endl << endl;
		cout << "\t\t\t\t 0 - Afficher la liste de trajets" << endl;
		cout << "\t\t\t\t 1 - Entrer un trajet simple" << endl;
		cout << "\t\t\t\t 2 - Entrer un trajet compos�" << endl;
		cout << "\t\t\t\t 3 - Rechercher un trajet" << endl;
		cout << "\t\t\t\t 4 - Recherche avanc�e de trajet" << endl << endl;
		cout << "\t\t\t\t 5 - Quitter l'application" << endl << endl;

		cin >> commande;
		switch (commande)
		{
		case 0:
			this->Afficher();
			break;

		case 1:
			cout << "Veuillez entrer la ville de d�part, la ville d'arriv�e et le transport correspondant : " << endl;
			cin >> villeDep;
			cin >> villeArr;
			cin >> moyenTransport;

			if (Ajouter(villeDep, villeArr, moyenTransport))
				cout << "Trajet ajout� avec succ�s!" << endl;
			else
				cout << "Erreur lors de l'ajout du trajet... :(" << endl;
			break;

		case 2:
		{
			cout << "Veuillez rentrer le nombre de trajets simples avec leur moyen de transport" << endl;
			int nbrTrajets;
			cin >> nbrTrajets;
			UnTrajetSimple* liste = new UnTrajetSimple[nbrTrajets];
			cin >> villeDep;
			for (int i(0); i<nbrTrajets; i++)
			{
				cin >> villeArr;
				cin >> moyenTransport;

				liste[i].villeDep = new char[20];
				liste[i].villeArr = new char[20];
				liste[i].moyenTransport = new char[20];

				strcpy(liste[i].villeDep, villeDep);

				strcpy(liste[i].villeArr, villeArr);

				strcpy(liste[i].moyenTransport, moyenTransport);

				strcpy(villeDep, villeArr);
			}
			if (Ajouter(liste, nbrTrajets))
				cout << "Trajet ajout� avec succ�s!" << endl;
			else
				cout << "Erreur lors de l'ajout du trajet... :(" << endl;

			for (int i(0); i<nbrTrajets; i++)
			{
				delete[] liste[i].villeDep;
				delete[] liste[i].villeArr;
				delete[] liste[i].moyenTransport;
			}
			delete[] liste;
		}
		break;

		case 3:
			cout << "Veuillez entrer la ville de d�part et la ville d'arriv�e : " << endl;

			cin >> villeDep;
			cin >> villeArr;
			this->Recherche(villeDep, villeArr);
			break;

		case 4:
			cout << "Veuillez entrer la ville de d�part et la ville d'arriv�e : " << endl;
			cin >> villeDep;
			cin >> villeArr;
			this->RechercheAvancee(villeDep, villeArr);
			break;

		case 5:
			return;
		}
	}

}

void Catalogue::Recherche(const char *villeDep, const char *villeArr) const
// Algorithme : pour chaque trajet de la liste, on l'affiche uniquement si ses
// villes de d�part et d'arriv�e correspondent aux param�tres.
{
	bool test = false;
	Element *ptrRech = listeTrajets.Tete;
	unsigned int compteur = 0;
	while (ptrRech != NULL)
	{
		if (strcmp(ptrRech->trajet->getVilleDepart(), villeDep) == 0)
		{
			if (strcmp(ptrRech->trajet->getVilleArrivee(), villeArr) == 0)
			{
				if (!test)
				{
					cout << "Liste des trajets propos�s: " << endl;
					test = true;
				}
				cout << "- Trajet " << ++compteur << " ------------------------------------------" << endl;
				ptrRech->trajet->Afficher();
			}
		}
		ptrRech = ptrRech->suivant;
	}
	if (!test)
	{
		cout << "Aucun trajet ne correspond � votre recherche: " << villeDep << " -> " << villeArr << endl;
	}
}

void Catalogue::RechercheAvancee(const char*villeDep, const char*villeArr) const 
// Algorithme : pour chaque trajet de la liste, on test si la ville de d�part correspond � celle d'un trajet
// on stocke le trajet trouv� dans une nouvelle liste de trajet et on reitere le proc�de pour la ville de 
// depart de trajet
//si avant la fin de la liste on arrive sur un trajet dont la ville de depart correspond � ville voulu
// on affiche la liste, sinon on la vide et on reitere.
{
	Element *ptr = listeTrajets.Tete;
	Element *test = listeTrajets.Tete;
	
	int compteur = 0;
	while (ptr!= NULL)	// on parcour la liste de trajet pour trouver le premier trajet avec ville de depart voulu
	{

		if (strcmp(ptr->trajet->getVilleDepart(), villeDep) == 0)
		{


			Element *newPtr = new Element;
			Element *newTete;
			test = listeTrajets.Tete;

			newPtr->trajet = ptr->trajet;
			newPtr->suivant = NULL;


			newTete = newPtr;
			
			
			while (strcmp(test->trajet->getVilleArrivee(), villeArr) !=0 ) // on parcourt toute la liste pour faire le lien ville depart= ville arriv�
			{	

				

				test = test->suivant;
				if (test == NULL) // si on arrive � la fin sans resultat voulu, on efface la liste newPtr
				{
					Element* ptrParcourt = newTete;
					while (ptrParcourt != NULL)
					{
						Element* tmp = ptrParcourt->suivant;
						delete ptrParcourt;
						ptrParcourt = tmp;

					}
					break;
				}
				
				else
					if (strcmp(test->trajet->getVilleDepart(), newPtr->trajet->getVilleArrivee()) == 0)
					{
						Element *elem=new Element;
						elem->trajet = test->trajet;
						elem->suivant = NULL;
						newPtr->suivant = elem;
						newPtr = newPtr->suivant;
					
					}

			}
			if (strcmp(newPtr->trajet->getVilleArrivee(), villeArr) == 0) // si le resultat est correct, on l'affiche
			{
				compteur++;

				cout << "    Trajet  " <<compteur<<" :"<< endl;
				newPtr = newTete;
				while (newPtr!=NULL)
				{
					newPtr->trajet->Afficher();
					newPtr = newPtr->suivant;
				}

				
			}
			Element* ptrParcourt = newTete;
			while (ptrParcourt != NULL)
			{
				Element* tmp = ptrParcourt->suivant;
				delete ptrParcourt;
				ptrParcourt = tmp;

			}
			
			
		}
		

		ptr = ptr->suivant;
	}
	if (compteur == 0)
	{
		cout << "D�sol�, votre recherche n'a pas donn� de resultat" << endl;
	}



}

Catalogue::Catalogue()
{
#ifdef MAP
	cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
	listeTrajets.Tete = NULL;
} //----- Fin de Catalogue


Catalogue::~Catalogue()
{
#ifdef MAP
	cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
	Element* ptr = listeTrajets.Tete;
	while (ptr != NULL)
	{
		delete ptr->trajet;
		Element* tmp = ptr;
		ptr = ptr->suivant;
		delete tmp;
	}
} //----- Fin de ~Catalogue


  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- M�thodes prot�g�es

