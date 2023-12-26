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
#include <string>
#include <stack>
#include <map>

//------------------------------------------------------ Include personnel
#include "../int/Catalogue.h"
#include "../int/TrajetSimple.h"
#include "../int/TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Catalogue::Afficher() const
{
  bool vide = true;
  for (vector<Trajet*>::const_iterator it = catalogue.begin(); it != catalogue.end(); ++it)
  {
    (*it)->Afficher();
    vide = false;
  }
  if (vide)
  {
    cout << "Catalogue vide" << endl;
  }
}

void Catalogue::AjouterTrajet(const Trajet* nouveau)
{
  catalogue.push_back(nouveau->clone());
}

void Catalogue::FaireParcoursSimple(const string & dep, const string & arr) const
{
  bool trouve = false;
  unsigned int res = 0;
  for (vector<Trajet*>::const_iterator it = catalogue.begin(); it != catalogue.end(); ++it)
  {
    if ((*it)->GetDepart() == dep && (*it)->GetArrivee() == arr)
    {
      trouve = true;
      cout << "Solution n°" << ++res << endl;
      (*it)->Afficher();
      cout << "\n";
    }
  }
  if (!trouve)
  {
    cout << "Aucun trajet ne correspond à votre recherche" << endl;
  }
}

void Catalogue::FaireParcoursComplexe(const string & dep, const string & arr) const
{
  vector<vector<Trajet*>> res;
  vector<Trajet*> currChemin;
  dfs(dep, arr, currChemin, res);

  if (res.empty())
  {
    cout << "Aucun trajet ne correspond à votre recherche" << endl;
    return;
  }

  unsigned int i = 0;
  for (vector<vector<Trajet*>>::const_iterator it = res.begin(); it != res.end(); ++it)
  {
    cout << "Solution n°" << ++i << endl;
    for (vector<Trajet*>::const_iterator it2 = (*it).begin(); it2 != (*it).end(); ++it2)
    {
      (*it2)->Afficher();
    }
    cout << "\n";
  }
}

void Catalogue::ChargerCatalogue(const string & nomFichier, int mode, int n, int m, const string & ville)
{
  
}


//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue () : catalogue()
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
  vector<Trajet*>::iterator it;
  for (it = catalogue.begin(); it != catalogue.end(); ++it)
  {
    delete *it;
  }
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
void Catalogue::dfs(const string & currPoint, const string & arr, vector<Trajet*> & currChemin, vector<vector<Trajet*>> & res) const
{
  if (currPoint == arr)
  {
    res.push_back(currChemin);
    return;
  }
  for (vector<Trajet*>::const_iterator it = catalogue.begin(); it != catalogue.end(); ++it)
  {
    if ((*it)->GetDepart() == currPoint)
    {
      bool dejafait = false;
      for (vector<Trajet*>::const_iterator it2 = currChemin.begin(); it2 != currChemin.end(); ++it2)
      {
        if (*it == *it2)
        {
          dejafait = true;
          break;
        }
      }
      if (dejafait)
      {
        continue;
      }
      currChemin.push_back(*it);
      dfs((*it)->GetArrivee(), arr, currChemin, res);
      currChemin.pop_back();
    }
  }
}