/*************************************************************************
                          TableauTrajets  -  description
                          -------------------
    début                : DATE$
    copyright            : (C) YEAR$ par AUTHOR$
    e-mail               : EMAIL$
*************************************************************************/
//---------- Réalisation de la classe <TableauTrajets> (fichier TableauTrajets.cpp) ------------
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
//------------------------------------------------------ Include personnel
#include "../int/TableauTrajets.h"
#include "../int/DFS.h"
//------------------------------------------------------------- Constantes
//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques

void TableauTrajets::Ajouter(const Trajet * nouveau)
{
  unsigned int i;
  Trajet * ajout = nouveau->clone();
  if (currTaille == maxTaille)
  // on a atteint la taille maximale du tableau actuel
  // politique de réallocation : prendre 2 fois plus grand
  {
    Trajet** realloc = new Trajet*[maxTaille*2];
    for (i=0; i<maxTaille; i++)
    {
      realloc[i] = tab[i];
    }
    delete[] tab;
    tab = realloc;
    maxTaille *= 2;
  }
  tab[currTaille] = ajout;
  currTaille++;
}

void TableauTrajets::SupprimerDernier()
{
  currTaille--;
  delete tab[currTaille];
}

void TableauTrajets::Afficher(unsigned int deltaTab, bool numero) const
{
  unsigned int i;
  cout << '\n';
  if (currTaille == 0)
  {
    cout << "Catalogue vide" << endl;
  }
  for (i=0; i<currTaille; i++)
  {
    if (numero)
    {
      cout << i << " - ";
    }
    tab[i]->Afficher(deltaTab);
  }
}

void TableauTrajets::ParcoursSimple(const char* dep, const char* arr) const
{
  unsigned int i;
  bool trouve = false;
  for (i=0; i<currTaille; i++)
  {
    if (!strcmp(tab[i]->GetDepart(), dep) && !strcmp(tab[i]->GetArrivee(), arr))
    {
      tab[i]->Afficher();
      trouve = true;
    }
  }
  if (!trouve)
  {
    cout << "Il n'y a aucun trajet qui fasse ce parcours" << endl;
  }
}

void TableauTrajets::ParcoursComplexe(const char* dep, const char* arr) const
{
  DFS resultat(dep, arr, *this, currTaille);

  resultat.Parcours();

  resultat.AfficherResultats();  
}

//------------------------------------------------- Surcharge d'opérateurs

const Trajet* TableauTrajets::operator[](unsigned int indice) const
{
  if (indice >= currTaille)
  {
    indice %= currTaille;
  }
  return tab[indice];
}

const TableauTrajets & TableauTrajets::operator=(const TableauTrajets & autre)
{
  unsigned int i;
  for (i=0; i < currTaille; i++)
  {
    delete tab[i];
  }
  delete[] tab;

  currTaille = autre.currTaille;
  maxTaille = autre.maxTaille;
  tab = new Trajet*[autre.maxTaille];

  for (i=0; i<autre.currTaille; i++)
  {
    tab[i] = autre.tab[i]->clone();
  }
  
  return *this;
}

//-------------------------------------------- Constructeurs - destructeur
TableauTrajets::TableauTrajets ( const TableauTrajets & autre )
  : currTaille(autre.currTaille), maxTaille(autre.maxTaille)
// Algorithme :
//
{
#ifdef MAP
  cout << "Appel au constructeur de copie de <TableauTrajets>" << endl;
#endif
  unsigned int i;
  tab = new Trajet*[autre.maxTaille];

  for (i=0; i<autre.currTaille; i++)
  {
    tab[i] = autre.tab[i]->clone();
  }
} //----- Fin de TableauTrajets (constructeur de copie)

TableauTrajets::TableauTrajets ( unsigned int max )
  : currTaille(0), maxTaille(max)
// Algorithme :
//
{
#ifdef MAP
  cout << "Appel au constructeur de <TableauTrajets>" << endl;
#endif
  tab = new Trajet*[max];
} //----- Fin de TableauTrajets
TableauTrajets::~TableauTrajets ( )
// Algorithme :
//
{
#ifdef MAP
  cout << "Appel au destructeur de <TableauTrajets>" << endl;
#endif
  unsigned int i;
  for (i=0; i < currTaille; i++)
  {
    delete tab[i];
  }
  delete[] tab;
} //----- Fin de ~TableauTrajets
//------------------------------------------------------------------ PRIVE
//----------------------------------------------------- Méthodes protégées