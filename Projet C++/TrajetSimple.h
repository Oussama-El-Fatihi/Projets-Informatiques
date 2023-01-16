/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par Oussama & Célia
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier Trajet.h) ----------------
#if ! defined ( TRAJETSIMPLE_H)
#define TRAJETSIMPLE_H
using namespace std;
#include <fstream>


//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
//
//
//------------------------------------------------------------------------

class TrajetSimple : virtual public Trajet
{
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


public: 
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

     void Affichage () const;
     // Mode d'emploi :Affichage des attributs du trajet simple
    //Définition de la méthode abstraite affichage de 
    // Contrat :
    //

    void sauveTrajet(ofstream & fichier);
    // Mode d'emploi : Méthode etandant celle de la classe mère permettant l'ajout du moyen de transport
    //
    // Contrat :
    //



//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    TrajetSimple (const char * D,const char * A, const char * MdT);
    // Mode d'emploi : Création d'un Trajet simple à partir 
    //d'un départ, d'une arrivée et d'un moyen de transport
    // Contrat :
    //
   
    virtual ~TrajetSimple ();
     
    // Mode d'emploi : delete le char * du ModeDeTransport
    //
    // Contrat :
    //


//------------------------------------------------------------------ PRIVE
private:
    char * ModedeTransport;


//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
protected:

};

//-------------------------------- Autres définitions dépendantes de <TrajetSimple>

#endif // TRAJETSIMPLE_H

