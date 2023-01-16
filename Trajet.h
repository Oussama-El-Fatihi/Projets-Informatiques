/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par QUE Oussama & Célia
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if ! defined ( TRAJET_H )
#define TRAJET_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <fstream>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
// Classe mère abstraite pure de TrajetSimple et TrajetCompose
// 
//
//------------------------------------------------------------------------

class Trajet
{
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    

    
public: 

    char * getDepart ();
    char * getArrivee ();

    virtual void Affichage () const  = 0;
    // Mode d'emploi : Méthode Abstraite définie dans les classes filles
    //
    // Contrat :
    //
    virtual void sauveTrajet(ofstream & fichier);
    // Mode d'emploi : Méthode permettant de sauvegarder le départ et l'arrivée d'un trajet dans un fichier (csv)
    //
    // Contrat :
    //
//-------------------------------------------- Constructeurs - destructeur
    
    Trajet(const char * D,  const char * A);
    //virtual Trajet ();
    // Mode d'emploi : Construteur de la classe
    //
    // Contrat :
    //

    

    
    virtual ~Trajet ();
    //virtual ~Xxx ();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
    char * Depart;
    char * Arrivee;
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // TRAJET_H
