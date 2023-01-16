/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
#include <fstream>

//------------------------------------------------------ Include personnel

#include "Trajet.h"
#include "TrajetSimple.h"
using namespace std;

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Xxx::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void TrajetSimple::Affichage () const
// Algorithme :
//
{
    cout<<"Trajet Simple de "<<Depart<< " à "<<Arrivee<<" en "<<ModedeTransport<<endl;   
} //--Fin de Affichage


void TrajetSimple :: sauveTrajet(ofstream & fichier){
// Algorithme : 
//
    Trajet :: sauveTrajet(fichier);
    fichier.write(ModedeTransport, strlen(ModedeTransport));


}   //--Fin de sauveTrajet
//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur


TrajetSimple::TrajetSimple (const char *D,  const char *A,  const char *Transport): Trajet(D,A)
// Algorithme : 
//
{
    
    ModedeTransport = new char[strlen(Transport)+1];
    strcpy (ModedeTransport,Transport);
    #ifdef MAP
        cout << "Appel au constructeur de <Trajet Sinmple>" << endl;
    #endif
} //--Fin de TrajetSimple

TrajetSimple::~TrajetSimple ()
// Algorithme :
//
{
    
    delete [] ModedeTransport;
    #ifdef MAP
        cout << "Appel au destructeur de <Trajet Simple>" << endl;
    #endif


} //--Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
