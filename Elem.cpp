/*************************************************************************
                           Elem  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Elem> (fichier Elem.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

#include <iostream>
#include <cstring>


//------------------------------------------------------ Include personnel

#include "Elem.h"
#include "Trajet.h"

using namespace std;

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

Trajet * Elem::getValue ()
// Algorithme :
{
    return t;
} //--Fin de getValue


Elem * Elem::getNext ()
// Algorithme :
{
    return suivant;
}//--Fin de getNext

void Elem::setValue (Trajet * T)
// Algorithme :
{
    t = T;
}//--Fin de setValue

void Elem::setNext (Trajet * T)
// Algorithme :
{
    suivant = new Elem (T);
}//--Fin de setNext

void Elem::setNextElem (Elem * e)
// Algorithme :
{
    suivant = e;
}//--Fin de setNextElem
//------------------------------------------------- Surcharge d'opérateurs



Elem::Elem (Trajet * T)
// Algorithme : 
//
{
    t = T;
    suivant = nullptr;
    #ifdef MAP
        cout << "Appel au constructeur de <Elem>" << endl;
    #endif
} //----- Fin de Elem

Elem::~Elem ()
// Algorithme :
//
{
    delete t;
    #ifdef MAP
        cout << "Appel au destructeur de <Elem>" << endl;
    #endif
    
} //----- Fin de ~Elem


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

