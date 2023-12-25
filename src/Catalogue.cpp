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
  // map<string, vector<vector<Trajet*>>> res;
  // stocke les trajets qui permettent d'aller à la ville depuis dep
  unsigned int i=0;
  vector<Trajet*>::const_iterator it, itera;
  stack<Trajet*> stack;
  vector<Trajet*> currChemin;
  string currPoint = dep;
  bool boucle;

  for (it = catalogue.begin(); it != catalogue.end(); ++it)
  {
    if ((*it)->GetDepart() == currPoint)
    {
      stack.push(*it);
    }
  }

  while (!stack.empty())
  {
    Trajet* currTrajet = stack.top();
    stack.pop();
    currChemin.push_back(currTrajet);
    currPoint = currTrajet->GetArrivee();
    if (currPoint == arr)
    {
      cout << "Solution n°" << ++i << endl;
      for (it = currChemin.begin(); it != currChemin.end(); ++it)
      {
        (*it)->Afficher();
      }
      cout << "\n";
      currChemin.pop_back();
      currPoint = currTrajet->GetDepart();
    }
    else
    {
      for (it = catalogue.begin(); it != catalogue.end(); ++it)
      {
        if ((*it)->GetDepart() == currPoint)
        {
          // vérifie qu'on fait pas de boucle
          boucle = false;
          for (itera = currChemin.begin(); itera != currChemin.end(); ++itera)
          {
            if ((*itera) == (*it))
            {
              boucle = true;
              break;
            }
          }

          if (!boucle)
          {
            stack.push(*it);
          }
        }
      }
    }
  }
}


Catalogue & Catalogue::operator = (const Catalogue & autre)
{
  catalogue = autre.catalogue;
  return *this;
}

//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue (unsigned int max) : catalogue()
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