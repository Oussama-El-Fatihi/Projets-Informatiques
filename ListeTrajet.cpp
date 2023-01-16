/*************************************************************************
                           ListeTrajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <ListeTrajet> (fichier Elem.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel

#include "Elem.h"
#include "Trajet.h"
#include "ListeTrajet.h"

using namespace std;
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool ListeTrajet::AjouterFin (Trajet *t){
    if (debut == nullptr){
        debut = new Elem (t);
        fin = debut;
        return true;
    } else{
        if(strcmp(fin->getValue ()->getArrivee (), t->getDepart ()) == 0) {
            fin->setNext (t);
            fin = fin->getNext ();
            return true;
        } else {
            cout << "Ajout Impossible le Depart du trajet actuel ne correspond point à l'arrivée du trajet précédent"<< endl;
            return false;
        }
    }   
}//--Fin de AjouterFin

void ListeTrajet::AjouterAlph (Trajet *t)
{

  if (debut == nullptr){ // Si la liste est vide
        debut = new Elem (t);
        fin = debut;
        
    } else {
        Elem * courant = debut;
        Elem * precedent = debut;
        Elem * e = new Elem (t);
        while( courant != nullptr && strcmp( courant -> getValue() -> getDepart(), t -> getDepart() ) < 0 )
        { //Boucle parcourant la liste en comparant le départ du trajet ajouté avec celui de chacun de la liste
            precedent = courant;
            courant = courant -> getNext ();
        }
        if (courant == debut){ // Cas ou le Trajet doit etre au début
            debut = e;
            debut -> setNextElem(courant);
        }
        else if (courant != nullptr){ // Cas où le Trajet est au milieu de la liste
            precedent -> setNextElem (e);
            e -> setNextElem (courant);
        }else{ // Cas ou le Trajet doit etre en fin
            fin -> setNextElem (e);
            fin = fin->getNext ();
        //delete e;
        }
}

}//--Fin de AjouterAlph ()

Trajet * ListeTrajet::getDebut ()
{
    if (debut!=nullptr) return debut->getValue ();
    return nullptr;
} //--Fin de getDebut

Elem * ListeTrajet::getDebutListe ()
{
    return debut;
} //--Fin de getDebutListe

Trajet * ListeTrajet::getFin ()
{
    if (fin!=nullptr) return fin->getValue ();
    return nullptr;
} //--Fin de getFin

//------------------------------------------------- Surcharge d'opérateurs


void ListeTrajet::AfficheListe () const
{
    if (debut == nullptr){
        cout << "Pas de Trajet pour le moment :/ : " <<  endl;
    } else {
        Elem * courant = debut;
        while (courant != nullptr){
            courant->getValue ()->Affichage ();
            cout<<endl;
            courant = courant->getNext ();
        }
    }
} //--Fin de AfficheListe

void ListeTrajet:: AfficheListeTrajetCompose() const
{
    if (debut == nullptr){
        cout << "Pas de Trajet pour le moment :/ : " <<  endl;
    } else {
        Elem * courant = debut;
        while (courant != nullptr){
            courant->getValue ()->Affichage ();
            courant = courant->getNext ();
        }
    }
} //--Fin de AfficheListe

ListeTrajet::ListeTrajet ()
// Algorithme : 
//
{
    #ifdef MAP
    cout << "Appel au constructeur de <ListeTrajet>" << endl;
    #endif
    debut = nullptr;
    fin = nullptr;
} //--Fin de ListeTrajet


ListeTrajet::~ListeTrajet ()
// Algorithme : 
//
{
    #ifdef MAP
    cout << "Appel au destructeur de <ListeTrajet>" << endl;
    #endif
    if (debut!=nullptr){
        Elem * temp = debut;
        while (debut->getNext ()!=nullptr){
            debut = debut->getNext ();
            delete temp;
            temp = debut;
        }
        delete fin;
    }
} //--Fin de ~ListeTrajet

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

