/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par Oussama & Célia
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

//--------------------------------------------------- Interfaces utilisées
#include "ListeTrajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Description de  <Catalogue>
//
//
//------------------------------------------------------------------------

class Catalogue
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
    // type Méthode (liste des paramètres);
    // Mode d'emploi :
    //
    // Contrat :
    //

    void AfficheCatalogue () const;
    // Mode d'emploi : Affiche les trajets contenues dans le catalogue
    //
    // Contrat :
    //

    void AjoutCatalogue (Trajet * unTrajet);
    // Mode d'emploi : Ajout d'un Trajet de le Catalogue par ordre alphabétique de Départ
    // 
    // Contrat :
    //

     void RechercheTrajet (const char * vdepart, const char * varrivee);
     // Mode d'emploi : Recherche d'un trajet dans le catalogue correpondant au départ et arrivé rentré
    // 
    // Contrat :
    //

     ListeTrajet * getCatalogue () const;
     // Mode d'emploi : Retourne le catalogue
    // 
    // Contrat :
    //




//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Catalogue();
    // Mode d'emploi : Construteur initialisant le pointeur de ListeTrajet
    // 
    // Contrat :
    //
    ~Catalogue();
    // Mode d'emploi : Destructeur qui delete le pointeur de ListeTrajet
    // 
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

private:
    ListeTrajet * CatalogueTrajet;
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // CATALOGUE_H

