/*************************************************************************
                          DFS  -  description
                          -------------------
    début                : DATE$
    copyright            : (C) YEAR$ par AUTHOR$
    e-mail               : EMAIL$
*************************************************************************/
//---------- Réalisation de la classe <DFS> (fichier DFS.cpp) ------------
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
//------------------------------------------------------ Include personnel
#include "../int/DFS.h"
//------------------------------------------------------------- Constantes
//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques

void DFS::Parcours()
{
  unsigned int i;
  if (!strcmp(currPoint, arrivee))
  // on est à l'arrivée donc on doit ajouter currChemin à res
  {
    if (maxTaille == currTaille)
    // politique de réallocation : prendre 2 fois plus grand
    {
      TableauTrajets* realloc = new TableauTrajets[2*maxTaille];
      for (i=0; i<maxTaille; i++)
      {
        realloc[i] = res[i];
      }
      delete[] res;
      res = realloc;
    }
    res[currTaille] = TableauTrajets(currChemin);
    currTaille++;
    return;
  }
  for (i=0; i<tailleCatalogue; i++)
  // on parcourt chaque trajet
  {
    if (trajetsPris[i] || strcmp(currPoint, catalogue[i]->GetDepart()))
    // le trajet n'est pas disponible parce qu'on l'a déjà pris sur currChemin
    // ou bien on ne peut pas le prendre parce qu'on ne se trouve pas sur le départ
    {
      continue;
    }

    currChemin.Ajouter(catalogue[i]);
    // on ajoute ce trajet au chemin actuel
    // (copie en surface parce qu'on ne fait pas de suppression et moins de copie)

    trajetsPris[i] = true;
    // et on dit qu'on l'a pris

    strcpy(currPoint, catalogue[i]->GetArrivee());

    Parcours();
    // on essaie d'aller plus loin sur ce chemin

    // on a fini d'essayer toutes les possibilités à partir de ce chemin actuel
    // donc on revient en arrière
    strcpy(currPoint, catalogue[i]->GetDepart());
    currChemin.SupprimerDernier();
    trajetsPris[i] = false;
  }
}

void DFS::AfficherResultats() const
{
  unsigned int i;
  if (currTaille == 0)
  {
    cout << "Aucun résultat" << endl;
  }
  for (i=0; i<currTaille; i++)
  {
    cout << "Solution n°" << i+1;
    res[i].Afficher(1, false);
    cout << endl;
  }
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
DFS::DFS ( const DFS & unDFS )
// Algorithme :
//
{
#ifdef MAP
  cout << "Appel au constructeur de copie de <DFS>" << endl;
#endif
} //----- Fin de DFS (constructeur de copie)

DFS::DFS (const char* dep, const char* arr, const TableauTrajets & trajets, unsigned int tailleCata)
  : currChemin(), catalogue(trajets), tailleCatalogue(tailleCata), maxTaille(5), currTaille(0)
// Algorithme :
//
{
#ifdef MAP
  cout << "Appel au constructeur de <DFS>" << endl;
#endif
  unsigned int i;

  currPoint = new char[20];
  strcpy(currPoint, dep);

  arrivee = new char[20];
  strcpy(arrivee, arr);

  trajetsPris = new bool[tailleCata];
  for (i=0; i<tailleCata; i++)
  {
    trajetsPris[i] = false;
  }

  res = new TableauTrajets[maxTaille];
} //----- Fin de DFS
DFS::~DFS ( )
// Algorithme :
//
{
#ifdef MAP
  cout << "Appel au destructeur de <DFS>" << endl;
#endif
  delete[] currPoint;
  delete[] arrivee;
  delete[] trajetsPris;
  delete[] res;
} //----- Fin de ~DFS
//------------------------------------------------------------------ PRIVE
//----------------------------------------------------- Méthodes protégées