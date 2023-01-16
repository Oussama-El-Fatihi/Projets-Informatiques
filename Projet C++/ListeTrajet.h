/*************************************************************************
                           Elem  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <ListeTrajet> (fichier ListeTrajet.h) ----------------
#if ! defined ( LISTETRAJET_H )
#define LISTETRAJET_H

//--------------------------------------------------- Interfaces utilisées

#include "Elem.h"
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Elem>
//Définit un element composé d'un trajet et d'un pointeur vers le trajet suivant
//permettant de créer la classe listeTrajet (une linked list de trajet)
//------------------------------------------------------------------------

class ListeTrajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    bool AjouterFin (Trajet * t);
    // Mode d'emploi : Ajout à la fin de liste le trajet 
    //
    // Contrat : Si le départ du trajet en paramètre correspond à
    //l'arrivée du trajet précedent alors la trajet est ajouté à la liste
    //(en créant un Elem qui pointe vers le trajet) et retourne true. Retourne false sinon
    //Méthode utilisé pour créer la ListeTrajet d'un TrajetComposé
    void AjouterAlph (Trajet * t);
    // Mode d'emploi :Ajout du trajet par ordre alphabétique de son depart
    //
    // Contrat : 
    //Méthode utilisé pour créer la ListeTrajet du Catalogue
    void AfficheListe () const;
    // Mode d'emploi : Affichage de chaque trajet composant la liste 
    //(utilisation de la méthode Affichage() en fonction du type de trajet (simple ou composé))
    // Contrat :
    //
    void AfficheListeTrajetCompose() const;
    // Mode d'emploi : Affichage de chaque trajet composant la liste de trajet composée
    //(utilisation de la méthode Affichage() en fonction du type de trajet (simple ou composé))
    // Contrat :
    //
    Trajet * getDebut ();
    // Mode d'emploi : Retourne le trajet pointé par le debut de la liste
    //
    // Contrat :
    //
    Trajet * getFin ();
    // Mode d'emploi : Retourne le trajet pointé par le debut de la liste
    //
    // Contrat :
    //
    Elem * getDebutListe ();
    // Mode d'emploi : Retourne le premier Elem de la liste
    //
    // Contrat :
    //
//-------------------------------------------- Constructeurs - destructeur

    ListeTrajet ();
    // Mode d'emploi : Construteur initialisant les deux pointeurs de la liste à nullptr
    //
    // Contrat :
    //

    virtual ~ListeTrajet ();
    // Mode d'emploi : delete les pointeurs d'Elem constituant la Liste
    //
    // Contrat :
    //

//----------------------------------------------------------------- PRIVATE

private:
    Elem * debut;
    Elem * fin;

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <ListeTrajet>

#endif // LISTETRAJET_H

