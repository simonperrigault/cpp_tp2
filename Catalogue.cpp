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
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Catalogue::Afficher() const
{
  catalogue.Afficher();
}

void Catalogue::AjouterTrajet()
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
    if (nouveau == NULL)
    {
      return;
    }
  }
  else
  {
    TrajetSimple** listeCompose;
    unsigned int tailleCompose;
    unsigned int i,j;
    cout << "Nombre de trajets dans le trajet composé : ";
    cin >> tailleCompose;
    listeCompose = new TrajetSimple*[tailleCompose];
    for (i=0; i<tailleCompose; i++)
    {
      cout << "\nEtape " << i+1 << " du trajet composé" << endl;
      listeCompose[i] = creerTrajetSimple();
      if (listeCompose[i] == NULL)
      {
        for (j=0; j<i; j++)
        {
          delete listeCompose[j];
        }
        delete[] listeCompose;
        return;
      }
    }
    for (i=0; i<tailleCompose-1; i++)
    {
      if (strcmp(listeCompose[i]->GetArrivee(), listeCompose[i+1]->GetDepart()))
      {
        cout << "Entrez des trajets continus" << endl;
        for (i=0; i<tailleCompose; i++)
        {
          delete listeCompose[i];
        }
        delete[] listeCompose;
        return;
      }
    }
    nouveau = new TrajetCompose(listeCompose, tailleCompose);
    for (i=0; i<tailleCompose; i++)
    {
      delete listeCompose[i];
    }
    delete[] listeCompose;
  }

  catalogue.Ajouter(nouveau);
  delete nouveau;
}

void Catalogue::FaireParcoursSimple() const
{
  char dep[20];
  char arr[20];

  cout << "Départ : ";
  cin >> dep;
  cout << "Arrivée : ";
  cin >> arr;
  cout << '\n';

  catalogue.ParcoursSimple(dep, arr);
}

void Catalogue::FaireParcoursComplexe() const
{
  char dep[20];
  char arr[20];

  cout << "Départ : ";
  cin >> dep;
  cout << "Arrivée : ";
  cin >> arr;
  cout << '\n';

  catalogue.ParcoursComplexe(dep, arr);
}

//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue (unsigned int max) : catalogue(max)
{
#ifdef MAP
  cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
{
#ifdef MAP
  cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
  
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
TrajetSimple* Catalogue::creerTrajetSimple() const
{
  char depart[20];
  char arrivee[20];
  char moyen[20];
  TrajetSimple* nouveau;
  cout << "Départ : ";
  cin >> depart;
  cout << "Arrivée : ";
  cin >> arrivee;
  cout << "Moyen de transport : ";
  cin >> moyen;
  if (!strcmp(depart, arrivee))
  {
    cout << "Entrez un départ et une arrivée différents" << endl;
    return NULL;
  }
  nouveau = new TrajetSimple(depart, arrivee, moyen);
  return nouveau;
}