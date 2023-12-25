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

Trajet* creerTrajet();
TrajetSimple* creerTrajetSimple(bool depConnu = false, const string & dep = "");

int main(int argc, char* argv[])
{  
  int choixMenu = 1;
  Trajet* nouveau;
  Catalogue catalogue;
  string dep, arr;


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
    cout << "\n";

    switch(choixMenu)
    {
      case 0:
        break;
      case 1:
        catalogue.Afficher();
        break;
      case 2:
        nouveau = creerTrajet();
        catalogue.AjouterTrajet(nouveau);
        delete nouveau;
        break;
      case 3:
        cout << "Départ : ";
        cin >> dep;
        cout << "Arrivée : ";
        cin >> arr;
        cout << "\n";
        catalogue.FaireParcoursSimple(dep, arr);
        break;
      case 4:
        cout << "Départ : ";
        cin >> dep;
        cout << "Arrivée : ";
        cin >> arr;
        cout << "\n";
        catalogue.FaireParcoursComplexe(dep, arr);
        break;
      default:
        cout << "Veuillez entrez une valeur valide" << endl;
    }
  }

  return 0;
}

Trajet* creerTrajet()
{
  Trajet* nouveau;
  int choixTrajet = -1;

  cout << "\n--- Ajout de trajet au catalogue ---" << endl;
  cout << "0 : Trajet Simple" << endl;
  cout << "1 : Trajet Composé" << endl;
  cout << "Votre choix : ";
  cin >> choixTrajet;
  if (choixTrajet == 0)
  {
    nouveau = creerTrajetSimple();
  }
  else
  {
    TrajetSimple** listeCompose;
    unsigned int tailleCompose;
    unsigned int i;
    cout << "Nombre de trajets dans le trajet composé : ";
    cin >> tailleCompose;
    listeCompose = new TrajetSimple*[tailleCompose];
    for (i=0; i<tailleCompose; i++)
    {
      cout << "\nEtape " << i+1 << " du trajet composé" << endl;
      if (i == 0)
      {
        listeCompose[i] = creerTrajetSimple();
      }
      else
      {
        listeCompose[i] = creerTrajetSimple(true, listeCompose[i-1]->GetArrivee());
      }
    }
    nouveau = new TrajetCompose(listeCompose, tailleCompose);
    for (i=0; i<tailleCompose; i++)
    {
      delete listeCompose[i];
    }
    delete[] listeCompose;
  }

  return nouveau;
}

TrajetSimple* creerTrajetSimple(bool depConnu, const string & dep)
{
  string depart = dep;
  string arrivee;
  string moyen;
  TrajetSimple* nouveau;
  if (!depConnu)
  {
    cout << "Départ : ";
    cin >> depart;
  }
  cout << "Arrivée : ";
  cin >> arrivee;
  cout << "Moyen de transport : ";
  cin >> moyen;
  nouveau = new TrajetSimple(depart, arrivee, moyen);
  return nouveau;
}