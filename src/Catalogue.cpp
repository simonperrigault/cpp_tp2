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
#include <fstream>
#include <sstream>

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

void Catalogue::ChargerCatalogue(const string & nomFichier, int mode, unsigned int n, unsigned int m, const string & ville)
{
  ifstream fichier(nomFichier);
  if (!fichier)
  {
    cout << "Erreur lors de l'ouverture du fichier" << endl;
    return;
  }
  unsigned int nombreTrajets = 0, tailleCompose = 0, i = 0;
  string ligne, type, depart, arrivee, moyen;
  TrajetSimple** listeCompose;
  while (getline(fichier, ligne))
  {
    ++nombreTrajets;
    if (mode == INTERVALLE && (nombreTrajets < n || nombreTrajets > m))
    {
      continue;
    }

    stringstream ss(ligne);
    getline(ss, type, ';');
    if (mode == SIMPLE && type == "TC")
    {
      continue;
    }
    if (mode == COMPOSE && type == "TS")
    {
      continue;
    }

    getline(ss, depart, ';');
    getline(ss, arrivee, ';');
    if (mode == DEPART && depart != ville)
    {
      continue;
    }
    if (mode == ARRIVEE && arrivee != ville)
    {
      continue;
    }

    if (type == "TS")
    {
      getline(ss, moyen, ';');
      catalogue.push_back(new TrajetSimple(depart, arrivee, moyen));
    }
    else
    {
      ss >> tailleCompose;
      ss.ignore(); // on passe le ; qui n'est pas pris par le >>
      listeCompose = new TrajetSimple*[tailleCompose];
      for (i=0; i<tailleCompose; ++i)
      {
        getline(ss, type, ';');
        getline(ss, depart, ';');
        getline(ss, arrivee, ';');
        getline(ss, moyen, ';');
        listeCompose[i] = new TrajetSimple(depart, arrivee, moyen);
      }
      catalogue.push_back(new TrajetCompose(listeCompose, tailleCompose));
      for (i=0; i<tailleCompose; ++i)
      {
        delete listeCompose[i];
      }
      delete[] listeCompose;
    }
  }
}

void Catalogue::SauvegarderCatalogue(const string & nomFichier, int mode, unsigned int n, unsigned int m, const string & ville) const
{
  ofstream fichier(nomFichier);
  if (!fichier)
  {
    cout << "Erreur lors de l'ouverture du fichier" << endl;
    return;
  }

  unsigned int nombreTrajets = 0;
  for (vector<Trajet*>::const_iterator it = catalogue.begin(); it != catalogue.end(); ++it)
  {
    ++nombreTrajets;
    if (mode == INTERVALLE && (nombreTrajets < n || nombreTrajets > m))
    {
      continue;
    }

    if (mode == SIMPLE && (*it)->EstType("TC"))
    {
      continue;
    }
    if (mode == COMPOSE && (*it)->EstType("TS"))
    {
      continue;
    }

    if (mode == DEPART && (*it)->GetDepart() != ville)
    {
      continue;
    }
    if (mode == ARRIVEE && (*it)->GetArrivee() != ville)
    {
      continue;
    }

    fichier << (*it)->getCSV() << endl;
  }
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