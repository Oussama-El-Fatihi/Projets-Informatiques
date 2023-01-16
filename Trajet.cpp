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

using namespace std;

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Xxx::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//-------------------------------------------- Constructeurs - destructeur

Trajet::Trajet ( const char *D,  const char *A )
// Algorithme : 
//
{
    Depart = new char[strlen(D)+1];
    Arrivee = new char[strlen(A)+1];
    strcpy (Depart,D);
    strcpy (Arrivee,A);
    #ifdef MAP
        cout << "Appel au Constructeur de <Trajet>" << endl;
    #endif
} //--Fin de Trajet

char * Trajet::getArrivee ()
{
    return Arrivee;
} //--Fin de getArrivee

char * Trajet::getDepart ()
{
    return Depart;
} //--Fin de getDepart

Trajet::~Trajet ()
// Algorithme :
//
{
    delete [] Depart;
    delete [] Arrivee;
    #ifdef MAP
        cout << "Appel au destructeur de <Trajet>" << endl;
    #endif
} //--Fin de ~Trajet


void Trajet :: sauveTrajet(ofstream & fichier){
// Algorithme : 
//
    fichier.write(Depart, strlen(Depart));
    fichier.put(';');
    fichier.write(Arrivee, strlen(Arrivee));
    fichier.put(';');


}   //--Fin de sauveTrajet


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

