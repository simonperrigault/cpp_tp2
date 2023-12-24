/*************************************************************************
                          Main  -  description
                          -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation du module <Main> (fichier Main.cpp) ---------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "../int/Trajet.h"
#include "../int/TrajetSimple.h"
#include "../int/TrajetCompose.h"
#include "../int/Catalogue.h"

///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privées


//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques

int main(int argc, char* argv[])
{
  // TableauTrajets tab;
  // Trajet* a = new TrajetSimple("a", "b", "m");
  // Trajet* b = new TrajetSimple("b", "c", "t");
  // tab.Ajouter(a);
  // tab.Ajouter(b);
  // delete a;
  // delete b;
  // tab.Afficher();

  
  int choixMenu = 1;
  Catalogue catalogue;

  while (choixMenu)
  {
    cout << "\n----- Menu Principal -----" << endl;
    cout << "1 : Afficher le catalogue" << endl;
    cout << "2 : Ajouter un trajet au catalogue" << endl;
    cout << "3 : Faire un parcours" << endl;
    cout << "4 : Faire un parcours utilisant plusieurs trajets" << endl;
    cout << "0 : Quitter" << endl;
    cout << "Votre choix : ";
    cin >> choixMenu;

    switch(choixMenu)
    {
      case 0:
        break;
      case 1:
        catalogue.Afficher();
        break;
      case 2:
        catalogue.AjouterTrajet();
        break;
      case 3:
        catalogue.FaireParcoursSimple();
        break;
      case 4:
        catalogue.FaireParcoursComplexe();
        break;
      default:
        cout << "Veuillez entrez une valeur valide" << endl;
    }
  }

  return 0;
}