/*************************************************************************
                           Elem  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Elem> (fichier Elem.h) ----------------
#if ! defined ( ELEM_H )
#define ELEM_H


//--------------------------------------------------- Interfaces utilisées

#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Elem>
//Définit un element composé d'un trajet et d'un pointeur vers le trajet suivant
//permettant de créer la classe listeTrajet (une linked list de trajet)
//------------------------------------------------------------------------

class Elem 
{
//----------------------------------------------------------------- PUBLIC

public:


//----------------------------------------------------- Méthodes publiques
    Trajet * getValue ();
    // Mode d'emploi : Retourne le trajet pointé par Elem
    //
    // Contrat :
    //

    Elem * getNext ();
    // Mode d'emploi : Retourne l'Elem suivant pointé par Elem
    //
    // Contrat :
    //

    void setValue (Trajet * T);
    // Mode d'emploi : Permet de modifierle trajet pointé par Elem
    //
    // Contrat :
    //

    void setNext (Trajet * T);
    // Mode d'emploi : Permet de modifier l'élement suivant à partir d'un trajet
    //créer un nouveau élément à partir du pointeur de trajet mis en parametre afin 
    //pointeur d'elem (new elem) qui sera donc l'elem actuel
    // Contrat :
    //

    void setNextElem (Elem * e);
    // Mode d'emploi : Met le pointeur d'Elem mis en parametre en temps que suivant 
    //de l'Elem actuel
    //
    // Contrat :
    //
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
//-------------------------------------------- Constructeurs - destructeur

    Elem (Trajet * T);
    // Mode d'emploi : Constructeur d'Elem
    //
    // Contrat : Initialisation d'elem à partir d'un pointeur trajet
    //

    virtual ~Elem ();
    // Mode d'emploi : delete le pointeur de trajet t
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE


private:
    Trajet * t;
    Elem * suivant;

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Elem>

#endif // Elem_H

