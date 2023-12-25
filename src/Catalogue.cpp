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
  
}

void Catalogue::dfs(const string & currPoint, vector<Trajet*> & currChemin, vector<vector<Trajet*>> & res) const
{

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