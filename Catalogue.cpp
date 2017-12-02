/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 13/11/2017
    copyright            : (C) 2017 par Théo Lorette-Froidevaux
			   Anatolii Gasiuk
    e-mail               : theo.lorette-froidevaux@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>


//------------------------------------------------------ Include personnel
#include "Catalogue.h"

//------------------------------------------------------------- Constantes
#define TAILLE_BUFFER_CLAVIER 20
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Catalogue::Ajouter(const char *villeDep, const char *villeArr, const char *moyenTransport)
// Algorithme : Créer un objet TrajetSimple et l'ajoute dans la liste chainée
//
{
	Element* ptr = new Element;
	ptr->trajet = new TrajetSimple(villeDep,villeArr,moyenTransport);
	ptr->suivant = NULL;
	if(listeTrajets.Tete == NULL)
	{
		listeTrajets.Tete = ptr;
		return;
	}
	Element* ptrRech = listeTrajets.Tete;
	while(ptrRech->suivant != NULL)
	{
		ptrRech = ptrRech->suivant;
	}
	ptrRech->suivant = ptr;
}

void Catalogue::Ajouter(const UnTrajetSimple *listeTrajetSimple, unsigned int tailleListe)
// Algorithme : pour chaque membre de la liste de UnTrajetSimple, créer l'objet TrajetSimple
// associé. Créer l'objet TrajetCompose à partir des objets TrajetSimple et enfin l'ajoute à
// la liste chainée.
{
	
	Trajet** lesTrajets = new Trajet*[tailleListe];
	for(unsigned int i = 0;i<tailleListe;i++)
	{
		lesTrajets[i] = new TrajetSimple(listeTrajetSimple[i].villeDep,listeTrajetSimple[i].villeArr,listeTrajetSimple[i].moyenTransport);
	}
	Element* elem = new Element;
	elem->suivant = NULL;
	elem->trajet = new TrajetCompose(lesTrajets,tailleListe);
	Element* ptr = listeTrajets.Tete;
	if(ptr==NULL)
	{
		listeTrajets.Tete = elem;
		delete [] lesTrajets;
	}
	while(ptr->suivant != NULL)
		ptr = ptr->suivant;
	ptr->suivant = elem;
	delete [] lesTrajets;
}

void Catalogue::Afficher() const
// Algorithme : Pour chaque trajet de la liste chainée, affiche le trajet.
//
{
	if(listeTrajets.Tete==NULL)
	{
		cout << "Aucun trajet planifié" << endl;
		return;
	}
	Element* ptr = listeTrajets.Tete;
	int i = 1;
	while(ptr!=NULL)
	{
		cout << "- Trajet " << i++ << " ------------------------------------------" << endl;
		ptr->trajet->Afficher();
		ptr = ptr->suivant;
	}
}

void Catalogue::Run()
// Algorithme : Affiche la liste d'instructions possible, puis exécute l'instruction en fonction
// des données entrées par l'utilisateur. Se processus est répété tant que l'utiisateur ne quitte
// pas l'application.
//
{
	cout<<"\t\t\t Bonjour, bienvenue dans le GPS de Timtim."<<endl<<endl;
	cout<<"###########################################################################################"<<endl;
	cout<<"############               #    #   ######   ##               #   #   ######   ############"<<endl;
	cout<<"############               #    #    ####    ##               #   #    ####    ############"<<endl;
	cout<<"##################   #######    #   # ## #   ########   #######   #   # ## #   ############"<<endl;
	cout<<"##################   #######    #   ##  ##   ########   #######   #   ##  ##   ############"<<endl;
	cout<<"##################   #######    #   ######   ########   #######   #   ######   ############"<<endl;
	cout<<"##################   #######    #   ######   ########   #######   #   ######   ############"<<endl;
	cout<<"##################   #######    #   ######   ########   #######   #   ######   ############"<<endl;
	cout<<"###########################################################################################"<<endl<<endl;
		
	char villeDep[TAILLE_BUFFER_CLAVIER];
	char villeArr[TAILLE_BUFFER_CLAVIER];
	char moyenTransport[TAILLE_BUFFER_CLAVIER];
	int commande;
	while (true)
	{
		cout<<"\t\t\t\tVoici la liste de commandes: "<<endl<<endl;
		cout<<"\t\t\t\t 0 - Afficher la liste de trajets"<<endl;
		cout<<"\t\t\t\t 1 - Entrer un trajet simple"<<endl;
		cout<<"\t\t\t\t 2 - Entrer un trajet composée"<<endl;
		cout<<"\t\t\t\t 3 - Rechercher un trajet"<<endl;
		cout<<"\t\t\t\t 4 - Quitter l'application"<<endl<<endl;

		cin>>commande;
		switch (commande)
		{
			case 0:
				this->Afficher();
				break;
			
			case 1:
				cout<<"Veuillez entrer la ville de départ, la ville d'arrivée et le transport correspondant : "<<endl;
				cin>>villeDep;
				cin>>villeArr;
				cin>>moyenTransport;
				this->Ajouter(villeDep,villeArr,moyenTransport);
				cout << "test" << endl;
				break;
				
			case 2:
				{
					cout<<"Veuillez rentrer le nombre de trajets simples avec leur moyen de transport"<<endl;
					int nbrTrajets;
					cin>> nbrTrajets;
					UnTrajetSimple* liste = new UnTrajetSimple[nbrTrajets];
					cin >> villeDep;
					for(int i(0);i<nbrTrajets;i++)
					{
						cin>>villeArr;
						cin>>moyenTransport;
						
						liste[i].villeDep = new char[20];
						liste[i].villeArr = new char[20];
						liste[i].moyenTransport = new char[20];
						
						strcpy(liste[i].villeDep,villeDep);
						
						strcpy(liste[i].villeArr,villeArr);
						
						strcpy(liste[i].moyenTransport,moyenTransport);

						strcpy(villeDep,villeArr);
					}
					this->Ajouter(liste,nbrTrajets);
					for(int i(0);i<nbrTrajets;i++)
					{
						delete[] liste[i].villeDep;
						delete[] liste[i].villeArr;
						delete[] liste[i].moyenTransport;
					}
					delete [] liste;
				}
				break;
				
			case 3:
				cout<<"Veuillez entrer la ville de départ et la ville d'arrivée : "<<endl;
				
				cin>>villeDep;
				cin>>villeArr;
				this->Recherche(villeDep, villeArr);
				break;
				
			case 4:
				return;
		}
	}
	
}

void Catalogue::Recherche (const char *villeDep, const char *villeArr) const
// Algorithme : pour chaque trajet de la liste, on l'affiche uniquement si ses
// villes de départ et d'arrivée correspondent aux paramètres.
{
	bool test=false;
	Element *ptrRech=listeTrajets.Tete;
	unsigned int compteur = 0;
	while(ptrRech!=NULL)
	{
		if(strcmp(ptrRech->trajet->getVilleDepart(), villeDep)==0)
		{
			if(strcmp(ptrRech->trajet->getVilleArrivee(), villeArr)==0)
			{
				if(!test)
				{
					cout<<"Liste des trajets proposés: "<<endl;
					test=true;
				}
				cout << "- Trajet " << ++compteur << " ------------------------------------------" << endl;
				ptrRech->trajet->Afficher();
			}
		}
		ptrRech=ptrRech->suivant;
	}
	if(!test)
	{
		cout<<"Aucun trajet ne correspond à votre recherche: "<<villeDep<<" -> "<< villeArr<<endl;
	}
}


Catalogue::Catalogue ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
	listeTrajets.Tete = NULL;
} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
	Element* ptr = listeTrajets.Tete;
	while(ptr!=NULL)
	{
		delete ptr->trajet;
		Element* tmp = ptr;
		ptr = ptr->suivant;
		delete tmp;
	}
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

