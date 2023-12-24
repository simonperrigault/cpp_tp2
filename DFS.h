/*************************************************************************
                          DFS  -  description
                          -------------------
    début                : DATE$
    copyright            : (C) YEAR$ par AUTHOR$
    e-mail               : EMAIL$
*************************************************************************/
//---------- Interface de la classe <DFS> (fichier DFS.h) ----------------
#if ! defined ( DFS_H )
#define DFS_H
//--------------------------------------------------- Interfaces utilisées

#include "TableauTrajets.h"

//------------------------------------------------------------- Constantes
//------------------------------------------------------------------ Types
//------------------------------------------------------------------------
// Rôle de la classe <DFS>
// Classe qui va trouver toutes les combinaisons de trajets qui permettent
// d'aller d'un point A à un point B à partir d'un catalogue de trajets
//------------------------------------------------------------------------
class DFS
{
//----------------------------------------------------------------- PUBLIC
public:
//----------------------------------------------------- Méthodes publiques

  void Parcours();
  void AfficherResultats() const;

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
  DFS ( const DFS & unDFS );
  // Mode d'emploi (constructeur de copie) :
  //
  // Contrat :
  //
  DFS (const char* dep, const char* arr, const TableauTrajets & trajets, unsigned int tailleCata);
  // Mode d'emploi :
  //
  // Contrat :
  //
  virtual ~DFS ( );
  // Mode d'emploi :
  //
  // Contrat :
  //
//------------------------------------------------------------------ PRIVE
protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
  char* currPoint;
  char* arrivee;

  TableauTrajets currChemin;
  // va stocker le chemin actuel qu'on parcourt afin de pouvoir l'ajouter au résultat
  // si on arrive à l'arrivée

  TableauTrajets catalogue;
  // liste des trajets disponibles
  unsigned int tailleCatalogue;

  bool* trajetsPris;

  TableauTrajets* res;
  // va stocker les combinaisons qui ont permis de faire le bon trajet
  // taille dynamique donc on regarde sa taille courante et sa taille max
  unsigned int maxTaille;
  unsigned int currTaille;
};
//-------------------------------- Autres définitions dépendantes de <DFS>
#endif // DFS_H