#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "Trajet.h"
#include "TrajetSimple.h"
#include "Elem.h"
#include "ListeTrajet.h"
#include "TrajetCompose.h"
#include "Catalogue.h"
//#define MAP 5;

using namespace std;

int main ()
{
  
Catalogue* monCatalogue = new Catalogue ();


int choix = 1;


while (choix != 0)

{
    cout << endl;
    cout << "Taper 0 si vous souhaitez quitter le programme" << endl;
    cout << endl;
    cout << "Taper 1 si vous souhaitez ajouter un Trajet Simple dans le Catalogue" << endl;
    cout << endl;
    cout << "Taper 2 si vous souhaitez ajouter un Trajet Composé dans le Catalogue" << endl;
    cout << endl;
    cout << "Taper 3 si vous souhaitez voir le contenue actuel du Catalogue" << endl;
    cout << endl;
    cout << "Taper 4 si vous souhaitez rechercher un Trajet qui correspond au voyage que vous voulez effectuer" << endl;
    cout << endl;
    cout << "Taper 5 si vous souhaitez sauvegarder le catalogue dans un fichier csv" << endl;
    cout << endl;
    cout << "Taper 6 si vous souhaitez charger le catalogue à partir d'un fichier csv" << endl;
    cout << endl;

    cin >> choix ;

    if (choix == 1)
    {
        cout << "Vous avez choisi l'ajout un trajet simple" << endl;
        char* depart = new char[27];
        char* arrivee = new char[27];
        char* transport = new char[27];
        cout << "Veuillez saisir la ville de départ de votre trajet simple" << endl;
        cin >> depart;
        cout << "Veuillez saisir la ville d'arrivée de votre trajet simple" << endl;
        cin >> arrivee;
        cout << "Veuillez saisir le moyen de transport de votre trajet simple" << endl;
        cin >> transport;
        TrajetSimple * unTrajetSimple = new TrajetSimple(depart , arrivee , transport);
        monCatalogue -> AjoutCatalogue(unTrajetSimple);
        delete [] depart;
        delete [] arrivee;
        delete [] transport;
    }

    if (choix == 2)
    {
      cout << "Vous avez choisi d'ajout un trajet composé" << endl;
      char* depart = new char[27];
      char* arrivee = new char[27];
      ListeTrajet * ListeTrajetCompose = new ListeTrajet ();
      cout << "Veuillez saisir la ville de départ de votre trajet composé" << endl;
      cin >> depart;
      cout << "Veuillez saisir la ville d'arrivée de votre trajet composé" << endl;
      cin >> arrivee;

      char* departpremiertrajet = new char[27];
      char* arriveepremiertrajet = new char[27];
      char* mdtpremiertrajet = new char[27];
      int i = 1;
      cout << "Veuillez saisir le trajet n° " << i << " de votre trajet composé" << endl;
      cout << "Commencez par saisir le depart de ce trajet" << endl;
      cin >> departpremiertrajet;
      while (strcmp(departpremiertrajet,depart ) != 0 )
      {
        cout<< "Le départ du premier trajet ne coincide pas avec le depart de votre trajet composé. Veuillez ressaisir le départ" << endl;
        
        cin >> departpremiertrajet;
        
      }
      cout << "Saisissez maintenant l'arrivee de ce trajet" << endl;
      cin >> arriveepremiertrajet;
      cout << "Saisissez enfin le moyen de transport de ce trajet" << endl;
      cin >> mdtpremiertrajet;
      TrajetSimple * PremTrjt = new TrajetSimple (departpremiertrajet ,arriveepremiertrajet ,mdtpremiertrajet);
      ListeTrajetCompose -> AjouterFin (PremTrjt);
      i++;
      delete [] departpremiertrajet;
      delete [] arriveepremiertrajet;
      delete [] mdtpremiertrajet;
      while( strcmp (arrivee,ListeTrajetCompose -> getFin () -> getArrivee ()) != 0)
      {
        cout << "Veuillez saisir le trajet n° " << i << " de votre trajet composé" << endl;
        cout << "Commencez par saisir le depart de ce trajet" << endl;
        char* dep = new char[27];
        char* arr = new char[27];
        char* transport = new char[27];
        cin >> dep;
        cout << "Saisissez maintenant l'arrivee de ce trajet" << endl;
        cin >> arr;
        cout << "Saisissez enfin le moyen de transport de ce trajet" << endl;
        cin >> transport;
        TrajetSimple * t = new TrajetSimple (dep ,arr ,transport);
        delete [] dep;
        delete [] arr;
        delete [] transport;
        if(ListeTrajetCompose -> AjouterFin (t))
        {
        i++;
        }
      
    }

    TrajetCompose *  trajetcompose = new TrajetCompose (depart, arrivee, ListeTrajetCompose);
    monCatalogue->AjoutCatalogue (trajetcompose);
    delete [] depart;
    delete [] arrivee;
    }
    
    if (choix == 3)
    {
    monCatalogue->AfficheCatalogue();
    
    }

    if (choix == 4)
    {
        cout << "Vous avez choisi une recherche de trajet" << endl;
        char* depart = new char[27];
        char* arrivee = new char[27];
        cout << "Veuillez saisir la ville de départ de votre voyage" << endl;
        cin >> depart;
        cout << "Veuillez saisir la ville d'arrivée de votre voyage" << endl;
        cin >> arrivee;
        monCatalogue -> RechercheTrajet (depart, arrivee);
        delete [] depart;
        delete [] arrivee;
    }
    if(choix == 5)
    {
        cout << "Vous avez choisi de sauvegarder le catalogue"<< endl;
        cout<<endl;
        if(monCatalogue -> getCatalogue()-> getDebutListe()==nullptr){
            cout<<"Malheuresement le catalogue est toujours vide"<<endl;
            cout<<endl;
        } else{
            cout << "Taper 1 si vous voulez sauvegarder le catalogue en entier (sauvegarde sans critères de sélection)"<< endl;
            cout << endl;
            cout << "Taper 2 si vous voulez sauvegarder le catalogue selon un type de trajet"<< endl;
            cout << endl;
            cout << "Taper 3 si vous voulez sauvegarder le catalogue selon la ville de départ et ou d'arrivée"<<endl;
            cout << endl;
            cout << "Taper 4 si vous voulez sauvegarder les trajets selon un intervalle "<<endl;
            cout << endl;
            int choixSauv;
            string nomFichier;
            cin >> choixSauv;
            cout << endl;
            cout << "Entrer le nom du fichier de sauvegarde (avec l'extension)"<< endl;
            cout<<endl;
            cin >> nomFichier;
            cout << endl;
            ifstream fichier2(nomFichier, ios::in); //ouverture d'un flux de lecture permettant de verifier si le fichier existe
            ofstream fichier(nomFichier, ios::out | ios::trunc); //ouverture d'un flux d'écriture
            if(!fichier2){
                cout<<"Fichier inexistant, de ce fait un fichier du même nom va etre créer afin de sauvegarder le catalogue"<<endl;
                cout<<endl;
            }
            fichier2.close();
            if(choixSauv == 1){
                Elem * e = monCatalogue -> getCatalogue()-> getDebutListe();
                while(e  != nullptr){
                    if(dynamic_cast<TrajetSimple*>(e->getValue())){
                    //if(typeid(e->getValue()) == typeid(TrajetSimple*)){   //On verifie si c'est un trajet simple
                        fichier.write("1;",2); 
                        e->getValue()->sauveTrajet(fichier);
                   // } else if(typeid(e->getValue()) == typeid(TrajetCompose*)){ //On verifie si c'est un trajet composé
                        } else if(dynamic_cast<TrajetCompose*>(e->getValue())){
                        e->getValue()->sauveTrajet(fichier);
                    }

                    fichier<<endl;
                    fichier<<endl;
                    e = e->getNext();
                }
            }
            if(choixSauv == 2) {
                int choixTrajet;
                Elem * e = monCatalogue -> getCatalogue()-> getDebutListe();
                cout << "Tapez 1 si vous voulez sauvegarder des trajets simples"<<endl;
                cout << endl;
                cout << "Tapez 2 si vous voulez sauvegarder des trajets composés"<<endl;
                cout << endl;
                cin >> choixTrajet; 
                cout << endl;
                if(choixTrajet == 1){
                    while(e  != nullptr){ //On ne sauvegarde que les trajets simples
                        if(dynamic_cast<TrajetSimple*>(e->getValue())){
                            fichier.write("1;",2);
                            e->getValue()->sauveTrajet(fichier);
                            fichier<<endl;
                            fichier<<endl;
                            
                        }
                        e = e->getNext();

                    }

                } else {
                    while(e  != nullptr){ //On ne sauvegarde que les trajets composés
                        if(dynamic_cast<TrajetCompose*>(e->getValue())){
                            e->getValue()->sauveTrajet(fichier);
                            fichier<<endl;
                            fichier<<endl;
                            
                        }
                        e = e->getNext();

                    }
                }
            }
            if(choixSauv == 3){ //Sauvegarde selon un départ et ou arrivée
                int choixVille;
                cout << "Taper 1 pour sauvegarder des trajets en fonction de la ville de départ" <<endl;
                cout << endl;
                cout << "Taper 2 pour sauvegarder des trajets en fonction de la ville d'arrivée" <<endl;
                cout << endl;
                cout << "Taper 3 pour sauvegarder des trajets en fonction de la ville de départ et celle de l'arrivée" <<endl;
                cout << endl;
                cin >> choixVille;
                cout <<endl;
                Elem * e = monCatalogue -> getCatalogue()-> getDebutListe();
                if(choixVille == 1){
                    string depart;
                    cout << "Veuillez saisir la ville de Départ";
                    cin >> depart;
                    cout << endl;
                    while(e != nullptr){
                        if(strcmp(depart.c_str(), e->getValue()->getDepart()) == 0){ //On compare le départ saisi avec l'arrivée du trajet
                            if(dynamic_cast<TrajetSimple*>(e->getValue())){
                                fichier.write("1;",2);
                                e->getValue()->sauveTrajet(fichier);
                            } else if(dynamic_cast<TrajetCompose*>(e->getValue())){
                                e->getValue()->sauveTrajet(fichier);
                            }
                            fichier<<endl;
                            fichier<<endl;
                            
                        }
                        e = e->getNext();
                    }

                } else if(choixVille == 2){ 
                        string arrive;
                        cout << "Veuillez saisir la ville d'arrivée";
                        cin >> arrive;
                        cout <<endl;
                        while(e != nullptr){
                            if(strcmp(arrive.c_str(), e->getValue()->getArrivee()) == 0){ //On compare l'arrivée saisie avec l'arrivée du trajet
                                if(dynamic_cast<TrajetSimple*>(e->getValue())){
                                    fichier.write("1;",2);
                                    e->getValue()->sauveTrajet(fichier);
                                } else if(dynamic_cast<TrajetCompose*>(e->getValue())){
                                    e->getValue()->sauveTrajet(fichier);
                                }
                                fichier<<endl;
                                fichier<<endl;
                                
                            }
                            e = e->getNext();
                        }

                    } else if(choixVille == 3){
                        string depart;
                        string arrive;
                        cout << "Veuillez entrer la ville de départ";
                        cin >> depart;
                        cout << "Veuillez entrer la ville d'arrivée";
                        cin >> arrive;
                        while(e != nullptr){
                            if((strcmp(arrive.c_str(), e->getValue()->getArrivee()) == 0)&&(strcmp(depart.c_str(), e->getValue()->getDepart()) == 0)){ // On compare le départ et l'arrivée saisis avec le départ et l'arrivée du trajet
                                if(dynamic_cast<TrajetSimple*>(e->getValue())){
                                    fichier.write("1;",2);
                                    e->getValue()->sauveTrajet(fichier);
                                } else if(dynamic_cast<TrajetCompose*>(e->getValue())){
                                    e->getValue()->sauveTrajet(fichier);
                                }
                                fichier<<endl;
                                fichier<<endl;
                                
                            }
                            e = e->getNext();
                        }

                    }                
            } else if(choixSauv==4){ //Sauvegarde selon un intervalle
                int max = 0;
                int indice = 0;
                int m, n;
                Elem * e = monCatalogue ->getCatalogue()->getDebutListe();
                while(e!=nullptr){ //Détérmination du nombre de trajets dans le catalogue
                    e= e->getNext();
                    max++;
                }
                if(max !=0){            
                    cout<< "Vous avez choisi la sauvegarde de trajets selon un intervalle"<<endl;
                    cout<<endl;
                    cout<<"Il y a actuellement "<<max<<" trajet(s) dans le catalogue"<<endl;
                    cout<<endl;
                    cout << "Veuillez saisir l'indice de début d'intervalle"<<endl;
                    cout<<endl;
                    cin >> n;
                    cout<<endl;
                    cout << "Veuillez saisir l'indice de fin d'intervalle"<<endl;
                    cout<<endl;
                    cin >> m;
                    cout<<endl;
                    while((n>m)||(m>max-1)||(n<0)){ //Vérification de la validité des indices
                        cout << "Veuillez rentrer des indices valables"<<endl;
                        cout<<endl;
                        cout << "Veuillez saisir l'indice de début d'intervalle"<<endl;
                        cout<<endl;
                        cin >> n;
                        cout<<endl;
                        cout << "Veuillez saisir l'indice de fin d'intervalle"<<endl;
                        cout<<endl;
                        cin >> m;
                        cout<<endl;
                    }
                    e = monCatalogue ->getCatalogue()->getDebutListe();
                    while(indice<=m){
                        if(indice>=n){ //Sauvegarde de trajets tant qu'on est dans l'intervalle
                            if(typeid(e->getValue()) == typeid(TrajetSimple*)){
                                fichier.write("1;",2);
                                e->getValue()->sauveTrajet(fichier);
                            } else if(typeid(e->getValue()) == typeid(TrajetCompose*)){
                                e->getValue()->sauveTrajet(fichier);
                            }
                            fichier<<endl;
                            fichier<<endl;
                        }
                        e = e->getNext();
                        indice++;
                    }    
                }else {
                    cout<<"Le catalogue est vide, il n'y a rien à sauvegarder."<<endl;
                    cout<<endl;
                }       
            }
        
        cout << "Sauvegarde effectuée avec succès !"<< endl;
        fichier.close();
        }
        
    }

    if(choix == 6){
        cout << "Vous avez choisi de charger un catalogue"<< endl;
        cout << endl;
        cout << "Entrer le nom du fichier (avec l'extension)"<< endl;
        cout << endl;
        string nomFichier;
        cin >> nomFichier;
        cout << endl;
        ifstream fichier(nomFichier, ios::in);
        /*
        while(!fichier.is_open()){ //A VERIFIER
            fichier.close();
            //string nomFichier;
            cout<<"Fichier inexistant, veuillez entrer le nom d'un fichier valide (avec l'extension)"<< endl;
            cout << endl;
            cin >> nomFichier;
            cout<<endl;
            ifstream fichier(nomFichier, ios::in);
        }
        */
        if(fichier){
            int choixCharge;
            
            
            cout << "Taper 1 si vous voulez charger le catalogue en entier" <<endl;
            cout << endl;
            cout << "Taper 2 si vous voulez charger un type de trajet"<<endl; 
            cout << endl;
            cout << "Taper 3 si vous voulez des trajets selon la ville de départ et ou d'arrivée"<<endl; 
            cout << endl;
            cout << "Taper 4 pour charger des trajets selon un intervalle "<<endl;
            cout << endl;
            cin >> choixCharge;
            cout << endl;

            
            if(choixCharge == 1){ //Chargement du catalogue en entier
                while (!fichier.eof()) {
                    char c = fichier.get(); //Enregistrement du premier caractère de ligne
                    if (c == '1') { //Chargement d'un trajet simple
                        fichier.seekg(1, ios::cur); //On sautre le ';' entre le 1 et le depart 
                        string depart, arrive, transport;
                        getline(fichier, depart, ';'); 
                        getline(fichier, arrive, ';');
                        getline(fichier, transport);
                        c = fichier.get();
                        //c_str() permet de convertir le string en char *
                        TrajetSimple* unTrajetSimple = new TrajetSimple(depart.c_str(), arrive.c_str(), transport.c_str());
                        monCatalogue->AjoutCatalogue(unTrajetSimple);
                    } else if (c == '2') { //Chargement d'un trajet composé
                        ListeTrajet* L = new ListeTrajet();
                        while (c == '2') {
                            string depart, arrive, transport;
                            fichier.seekg(1, ios::cur);
                            getline(fichier, depart, ';');
                            getline(fichier, arrive, ';');
                            getline(fichier, transport);
                            c = fichier.get();
            
                            TrajetSimple* unTrajetSimple = new TrajetSimple(depart.c_str(), arrive.c_str(), transport.c_str());
                            L->AjouterFin(unTrajetSimple);
                        }
                        TrajetCompose* unTrajetCompose = new TrajetCompose(L);
                        monCatalogue->AjoutCatalogue(unTrajetCompose);
                    }
                }
            } else if(choixCharge == 2) { //Chargement selon un type de trajet
                int choixTrajet;
                cout << "Tapez 1 si vous voulez charger des trajets simples"<<endl;
                cout << endl;
                cout << "Tapez 2 si vous voulez charger des trajets composés"<<endl;
                cout << endl;
                cin >> choixTrajet;
                if(choixTrajet == 1){
                    while(!fichier.eof()){
                    char c = fichier.get();
                    if(c == '1'){
                        fichier.seekg(1, ios::cur);
                        string depart, arrive, transport;
                        getline(fichier, depart, ';');
                        getline(fichier, arrive, ';');
                        getline(fichier, transport);
                        c = fichier.get();

                        TrajetSimple* unTrajetSimple = new TrajetSimple(depart.c_str(), arrive.c_str(), transport.c_str());
                        monCatalogue->AjoutCatalogue(unTrajetSimple);
                    }
                }
            } else if(choixTrajet == 2){
                char c;
                while(fichier.eof() != 1){
                    char c = fichier.get();
                    if(c == '2'){
                    ListeTrajet* L = new ListeTrajet();
                    while (c == '2') {
                        string depart, arrive, transport;
                        fichier.seekg(1, ios::cur);
                        getline(fichier, depart, ';');
                        getline(fichier, arrive, ';');
                        getline(fichier, transport);
                        c = fichier.get();
                        TrajetSimple* unTrajetSimple = new TrajetSimple(depart.c_str(), arrive.c_str(), transport.c_str());
                        L->AjouterFin(unTrajetSimple);
                    }
                    TrajetCompose* unTrajetCompose = new TrajetCompose(L);
                    monCatalogue->AjoutCatalogue(unTrajetCompose); 
                }
            }

        }

            
        } else if(choixCharge == 3){ //Chargement selon un départ et ou arrivée
            int choixVille;
            cout << "Taper 1 pour charger des trajets en fonction de la ville de départ" <<endl;
            cout << endl;
            cout << "Taper 2 pour charger des trajets en fonction de la ville d'arrivée" <<endl;
            cout << endl;
            cout << "Taper 3 pour charger des trajets en fonction de la ville de départ et celle de l'arrivée" <<endl;
            cout << endl;
            cin >> choixVille;
            if(choixVille == 1){
                string dep;
                cout << "Veuillez entrer la ville de départ" << endl;
                cout<< endl;
                cin >> dep;
                while(!fichier.eof()){
                    char c = fichier.get();
                    if(c == '1'){
                        fichier.seekg(1, ios::cur);
                        string depart, arrive, transport;
                        getline(fichier, depart, ';');
                        getline(fichier, arrive, ';');
                        getline(fichier, transport);
                        c = fichier.get();
                        if(strcmp(dep.c_str(), depart.c_str()) == 0){ //On vérifie si le départ du trajet crée correspond au départ saisi
                            TrajetSimple* unTrajetSimple = new TrajetSimple(depart.c_str(), arrive.c_str(), transport.c_str());
                            monCatalogue -> AjoutCatalogue(unTrajetSimple); 
                        }
                    } else if(c == '2'){
                        ListeTrajet * L = new ListeTrajet();
                        while(c == '2'){
                            string depart, arrive, transport;
                            fichier.seekg(1, ios::cur);
                            getline(fichier, depart, ';');
                            getline(fichier, arrive, ';');
                            getline(fichier, transport);
                            c = fichier.get();
                            TrajetSimple* unTrajetSimple = new TrajetSimple(depart.c_str(), arrive.c_str(), transport.c_str());
                            L->AjouterFin(unTrajetSimple);
                        }
                        if(strcmp(dep.c_str(), L->getDebut()->getDepart()) == 0){ //On vérifie si le départ du trajet crée correspond au départ saisi
                            TrajetCompose * unTrajetCompose = new TrajetCompose(L);
                            monCatalogue -> AjoutCatalogue(unTrajetCompose); 
                        } else { //Sinon on supprime la liste créé
                            delete L;
                        }
                    }
                }

            } else if(choixVille == 2){
                string arr;
                cout << "Veuillez entrer la ville d'arrivée" << endl;
                cout<< endl;
                cin >> arr;
                cout<<endl;
                while(fichier.eof() != 1){
                    char c;
                    c = fichier.get();
                    if(c == '1'){
                        fichier.seekg(1, ios::cur);
                        string depart, arrive, transport;
                        getline(fichier, depart, ';');
                        getline(fichier, arrive, ';');
                        getline(fichier, transport);
                        if(strcmp(arr.c_str(), arrive.c_str()) == 0){ 
                            TrajetSimple* unTrajetSimple = new TrajetSimple(depart.c_str(), arrive.c_str(), transport.c_str());
                            monCatalogue -> AjoutCatalogue(unTrajetSimple); 
                        }
                    } else if(c == '2'){

                        ListeTrajet * L = new ListeTrajet();
                        while(c == '2'){
                            string depart, arrive, transport;
                            fichier.seekg(1, ios::cur);
                            getline(fichier, depart, ';');
                            getline(fichier, arrive, ';');
                            getline(fichier, transport);
                            c = fichier.get();

                            TrajetSimple* unTrajetSimple = new TrajetSimple(depart.c_str(), arrive.c_str(), transport.c_str());
                            L->AjouterFin(unTrajetSimple);

                        }
                        if(strcmp(arr.c_str(), L->getFin()->getArrivee()) == 0){
                            TrajetCompose * unTrajetCompose = new TrajetCompose(L);
                            monCatalogue -> AjoutCatalogue(unTrajetCompose); 
                        } else {
                            delete L;
                        }
                    }
                }
            } else if(choixVille==3){
                string arr;
                string dep;
                cout << "Veuillez entrer la ville de départ" << endl;
                cout<< endl;
                cin >> dep;
                cout << "Veuillez entrer la ville d'arrivée" << endl;
                cout<< endl;
                cin >> arr;
                while(fichier.eof() != 1){
                    char c;
                    c = fichier.get();
                    if(c == '1'){
                    fichier.seekg(1, ios::cur);
                        string depart, arrive, transport;
                        getline(fichier, depart, ';');
                        getline(fichier, arrive, ';');
                        getline(fichier, transport);
                        if((strcmp(arr.c_str(), arrive.c_str()) == 0)&&(strcmp(dep.c_str(), depart.c_str()) == 0)){
                            TrajetSimple* unTrajetSimple = new TrajetSimple(depart.c_str(), arrive.c_str(), transport.c_str());
                            monCatalogue -> AjoutCatalogue(unTrajetSimple); 
                        }
                    } else if(c == '2'){

                        ListeTrajet * L = new ListeTrajet();
                        while(c == '2'){
                            string depart, arrive, transport;
                            fichier.seekg(1, ios::cur);
                            getline(fichier, depart, ';');
                            getline(fichier, arrive, ';');
                            getline(fichier, transport);
                            c = fichier.get();

                            TrajetSimple* unTrajetSimple = new TrajetSimple(depart.c_str(), arrive.c_str(), transport.c_str());
                            L->AjouterFin(unTrajetSimple);
                        }
                        if((strcmp(arr.c_str(), L->getFin()->getArrivee()) == 0)&&(strcmp(dep.c_str(), L->getDebut()->getDepart()) == 0)){
                            TrajetCompose * unTrajetCompose = new TrajetCompose(L);
                            monCatalogue -> AjoutCatalogue(unTrajetCompose); 
                        } else {
                            delete L;
                        }
                    }
                }
            }
        } else if(choixCharge == 4){ //Chargement selon un intervalle
            int indice = 0;
            int m, n;
            cout<< "Vous avez choisi la sauvegarde de trajets selon un intervalle"<<endl;
            cout<<endl;
            cout<<endl;
            cout << "Veuillez saisir l'indice de début d'intervalle"<<endl; 
            cout<<endl;
            cin >> n;  
            cout<<endl;         
            cout << "Veuillez saisir l'indice de fin d'intervalle"<<endl;
            cout<<endl;
            cin >> m;
            cout<<endl;
            while((n>m)||(n<0)){
                cout << "Veuillez rentrer des indices valables"<<endl;
                cout<<endl;
                cout << "Veuillez saisir l'indice de début d'intervalle"<<endl;
                cout<<endl;
                cin >> n;
                cout << "Veuillez saisir l'indice de fin d'intervalle"<<endl; 
                cout<<endl;           
                cin >> m;
                cout<<endl;
            }
            while((fichier.eof() != 1) || indice<=m){
                        char c;
                        c = fichier.get();
                        if(c == '1'){
                            string depart, arrive, transport;
                            fichier.seekg(1, ios::cur);
                            getline(fichier, depart, ';');
                            getline(fichier, arrive, ';');
                            getline(fichier, transport);
                            c = fichier.get();
                            if(indice<=m && indice>=n){ //Chargement dans le catalogue si on est bien dans l'intervalle
                                TrajetSimple* unTrajetSimple = new TrajetSimple(depart.c_str(), arrive.c_str(), transport.c_str());
                                monCatalogue -> AjoutCatalogue(unTrajetSimple); 
                            }
                        } else if(c == '2'){
                            ListeTrajet * L = new ListeTrajet();
                            while(c == '2'){
                                string depart, arrive, transport;
                                fichier.seekg(1, ios::cur);
                                getline(fichier, depart, ';');
                                getline(fichier, arrive, ';');
                                getline(fichier, transport);
                                c = fichier.get();

                                TrajetSimple* unTrajetSimple = new TrajetSimple(depart.c_str(), arrive.c_str(), transport.c_str());
                                L->AjouterFin(unTrajetSimple);
                            }
                            if(indice<=m && indice>=n){ //Chargement dans le catalogue si on est bien dans l'intervalle
                                TrajetCompose * unTrajetCompose = new TrajetCompose(L);
                                monCatalogue -> AjoutCatalogue(unTrajetCompose); 
                            } else { //Sinon on supprime la liste créée
                                delete L;
                            }
                    }
                    indice++;
            }
        }
        cout << "Chargement effectué avec succès !"<<endl;
        cout <<endl;
        fichier.close();
        } else {
            cerr<<"Fichier inexistant"<<endl;
            cerr<<endl;
        } 
    }
    if (choix == 0){
        delete monCatalogue;
    }

}
    return 0;
}