/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel

#include "Trajet.h"
#include "ListeTrajet.h"
#include "Catalogue.h"
#include "Elem.h"

using namespace std;

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
ListeTrajet * Catalogue::getCatalogue () const
{
    return CatalogueTrajet;
} //--Fin de getCatalogue

void Catalogue::AfficheCatalogue () const
{
    cout<<"Trajets contenus dans le Catalogue actuellement :"<<endl;
    cout<<endl;
    CatalogueTrajet->AfficheListe ();
    cout<<endl;
    cout<<endl;
} //--Fin de AfficheCatalogue

void Catalogue::AjoutCatalogue (Trajet * unTrajet)
{
    CatalogueTrajet->AjouterAlph(unTrajet);
} //--Fin de AjoutCatalogue

void Catalogue::RechercheTrajet (const char * vdepart, const char * varrivee)
{
    bool res = false;
    Elem * courant = CatalogueTrajet->getDebutListe ();
    while (courant !=nullptr)
    {
        if((strcmp(courant->getValue()->getDepart(),vdepart)== 0) && (strcmp(courant->getValue()->getArrivee(),varrivee)== 0))
        {
            if(!res){
                cout<<"Trajet(s) correspondant(s) :"<<endl;
                cout<<endl;
            }
            res = true;
            courant->getValue()->Affichage();
            cout<< endl;
        }
        courant = courant->getNext ();
    }
    if (!res)
    {
        cout<<"Désolé, mais aucun trajet du catalogue ne correspond à votre recherche :/";
    }

} //--Fin de RechercheTrajet
//-------------------------------------------- Constructeurs - destructeur

Catalogue::Catalogue ()
// Algorithme : 

{
    CatalogueTrajet = new ListeTrajet ();
    #ifdef MAP
        cout << "Appel au Constructeur de <Catalogue>" << endl;
    #endif
} //--Fin de Catalogue

Catalogue::~Catalogue ()
// Algorithme :
//
{
    delete CatalogueTrajet;
    #ifdef MAP
        cout << "Appel au destructeur de <Catalogue>" << endl;
    #endif

} //--Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

