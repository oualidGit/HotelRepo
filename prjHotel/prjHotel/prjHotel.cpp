#include <iostream>
#include "elementfacturable.h"
#include "facturablefraisfixe.h"
#include "facturableparunite.h"
#include "nbruniteexception.h"
#include "doublonunite.h"
#include "facture.h"
#include <vector>
#include <map>
using namespace std;
static void afficherMenu();
int main(){

    int choix = 0;
    ElementFacturable* nuitee = NULL;
    ElementFacturable* repas = NULL;
    ElementFacturable* spa = NULL;
    ElementFacturable* gym = NULL;

    Facture f(1, "20/04/2020");
   
    int nbrNuitee = 0, nbrRepas = 0;
    while (choix !=5) {
        afficherMenu();
        cin >> choix;
        switch (choix){
        case 1:
            cout << "Enter le nbr de nuitees : ";
            cin >> nbrNuitee;
            
            try {
                if (nbrNuitee <= 0)    throw NbrUniteException("Nuitee");
                if (f.getMapFacturables().count(1)>0) throw DoublonUnite(nbrNuitee , "Element Nuitee remplace");

                nuitee = new FacturableParUnite("Nuitee", 100, 1, nbrNuitee);
                f.ajouterElmtFacturable(nuitee);
                cout << nbrNuitee << " nuitee(s) a (ont) ete ajoute(s) a la facture" << endl;
            }
            catch(NbrUniteException e){
                cout << e.getMessage()<<endl;
            }
            catch (DoublonUnite d) {
                // ici, on remplace ElementFacturable avec sa cle par un nouvel element, avec nbr unites passé 
                // en argument d.getNb()
                f.getMapFacturables()[1] = new FacturableParUnite("Nuitee", 100, 1, d.getNb());
                cout << d.getMessage() << endl;
            }
            break;
        case 2:
            cout << "Enter le nbr de repas : ";
            cin >> nbrRepas;
            
            try {
                if (nbrRepas <= 0)      throw NbrUniteException("Repas ");
                if (f.getMapFacturables().count(2) > 0) throw DoublonUnite(nbrRepas , "Element Repas remplace");
                repas = new FacturableParUnite("Repas ", 20, 2, nbrRepas);
                f.ajouterElmtFacturable(repas);
                cout << nbrRepas << " repas a (ont) ete ajoute(s) a la facture" << endl;
            }
            catch (NbrUniteException e) {
                cout << e.getMessage()<<endl;
            }
            catch (DoublonUnite d) {
                f.getMapFacturables()[2] = new FacturableParUnite("Repas ", 20, 2, d.getNb());
                cout << d.getMessage() << endl;
            }
            break;
        case 3:
            spa = new FacturableFraisFixe("Spa   ", 75, 4);
            f.ajouterElmtFacturable(spa);
            cout << "Un forfait SPA a ete ajoute a la facture"<<endl;
            break;
        case 4:
            gym = new FacturableFraisFixe("Gym   ", 50, 3);
            f.ajouterElmtFacturable(gym);
            cout << "Un forfait Gym a ete ajoute a la facture" << endl;
            break;
        case 5:
            cout<<f.toString();
            cout << endl<< "Fin du programme";
            delete nuitee;
            delete repas;
            delete spa;
            delete gym;
            nuitee = NULL;
            repas = NULL;
            spa = NULL;
            gym = NULL;

            break;
        default:
            cout << "Choix incorrect";
            break;
        }
    }
}

static void afficherMenu() {
    
    cout << endl << "==========Menu principal==========" << endl;
    cout << "1. Ajouter des nuitees\n2. Ajouter des repas\n3. Ajouter un acces au spa\n4. Ajouter un acces au gym\n5. Afficher la facture et quitter\n";
    cout << "=================================="<<endl;
    cout << "Veuillez Entrer un choix : ";
}