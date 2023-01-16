/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
#include <fstream>

//------------------------------------------------------ Include personnel

#include "Trajet.h"
#include "TrajetCompose.h"
#include "TrajetSimple.h"
#include "Elem.h"
#include "ListeTrajet.h"

using namespace std;
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetCompose::Affichage () const
// Algorithme :
//
{
    cout<<"Trajet Composé de  "<<Depart<< " à  "<<Arrivee<<"  composé de "<<endl;
    cout<<endl;
    Liste->AfficheListeTrajetCompose ();
    cout<<endl;    
    cout<<endl;
} //--Fin de Affichage

void TrajetCompose :: sauveTrajet(ofstream & fichier)
// Algorithme :
//
{
Elem * e = Liste -> getDebutListe();
while(e->getNext() != nullptr){
    fichier.write("2;",2);
    e->getValue()->sauveTrajet(fichier);
    fichier<<endl;
    e = e->getNext();
    }
    fichier.write("2;",2);
    e->getValue()->sauveTrajet(fichier);
} //--Fin de Affichage   

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur


TrajetCompose::TrajetCompose (const char *D,  const char *A, ListeTrajet * L): Trajet(D,A)
// Algorithme : 
//
{
    Liste = L;
    #ifdef MAP
        cout << "Appel au constructeur de <Trajet Compose>" << endl;
    #endif

}//--Fin de TrajetCompose 

TrajetCompose::TrajetCompose (ListeTrajet * L): Trajet(L->getDebut()->getDepart(),L->getFin()->getArrivee())
// Algorithme : 
//
{
    Liste = L;
    #ifdef MAP
        cout << "Appel au constructeur de <Trajet Compose>" << endl;
    #endif

}//--Fin de TrajetCompose 

TrajetCompose::~TrajetCompose ()
// Algorithme :
//
{
    delete Liste;
    #ifdef MAP
        cout << "Appel au destructeur de <Trajet Compose>" << endl;
    #endif
} //--Fin de ~TrajetCompose


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
