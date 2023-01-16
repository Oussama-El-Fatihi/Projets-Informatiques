/*************************************************************************
                           TrajetComposé  -  Trajet Composé de plusieurs villes avec divers moyens
                                                                de transport
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par Oussama & Célia
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TrajetComposé> (fichier TrajetComposé.h) ----------------
#if ! defined ( TRAJETCOMPOSE_H )
#define TRAJETCOMPOSE_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <fstream>

#include "ListeTrajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
//
//
//------------------------------------------------------------------------

class TrajetCompose : virtual public Trajet
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
    // Mode d'emploi : Méthode etandant celle de la classe mère permettant d'ajouter l'ensemble des trajets du trajet composé
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    TrajetCompose (const char * D,  const char * A, ListeTrajet * L);
    // Mode d'emploi : Création d'un TrajetCompo à partir 
    //d'un départ, d'une arrivée et d'une liste de Trajet (supposé simple peut ne pas l'étre en théorie)
    //Dans le main, on vérifie si le Départ du premier trajet de la liste correspond au départ du trajet composé
    // Contrat :
    //

    TrajetCompose (ListeTrajet * L);
    // Mode d'emploi : Création d'un TrajetCompo à partir 
    //d'un départ, d'une arrivée et d'une liste de Trajet (supposé simple peut ne pas l'étre en théorie)
    //Dans le main, on vérifie si le Départ du premier trajet de la liste correspond au départ du trajet composé
    // Contrat :
    //

    ~TrajetCompose ();
    // Mode d'emploi : Destructeur qui delete le pointeur de ListeTrajet
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE
private:
    ListeTrajet * Liste;

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // TRAJETCOMPOSE_H
