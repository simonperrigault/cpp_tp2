/*************************************************************************
                          TableauTrajets  -  description
                          -------------------
    début                : DATE$
    copyright            : (C) YEAR$ par AUTHOR$
    e-mail               : EMAIL$
*************************************************************************/
//---------- Interface de la classe <TableauTrajets> (fichier TableauTrajets.h) ----------------
#if ! defined ( TABLEAUTRAJETS_H )
#define TABLEAUTRAJETS_H
//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------- Constantes
//------------------------------------------------------------------ Types
//------------------------------------------------------------------------
// Rôle de la classe <TableauTrajets>
// Classe qui gère un tableau dynamique de pointeurs vers des trajets
// afin de simplifier les classes utilisant ces tableaux
//------------------------------------------------------------------------
class TableauTrajets
{
//----------------------------------------------------------------- PUBLIC
public:
//----------------------------------------------------- Méthodes publiques
  void Ajouter(const Trajet* nouveau);
  void SupprimerDernier();
  void Afficher(unsigned int deltaTab = 0, bool numero = true) const;
  void ParcoursSimple(const char* dep, const char* arr) const;
  void ParcoursComplexe(const char* dep, const char* arr) const;
//------------------------------------------------- Surcharge d'opérateurs
  const Trajet* operator[](unsigned int indice) const;
  const TableauTrajets & operator=(const TableauTrajets & autre);
//-------------------------------------------- Constructeurs - destructeur
  TableauTrajets ( const TableauTrajets & autre );
  // Mode d'emploi (constructeur de copie) :
  //
  // Contrat :
  //
  TableauTrajets (unsigned int max = 5);
  // Mode d'emploi :
  //
  // Contrat :
  //
  virtual ~TableauTrajets ( );
  // Mode d'emploi :
  //
  // Contrat :
  //
//------------------------------------------------------------------ PRIVE
protected:
//----------------------------------------------------- Méthodes protégées
//----------------------------------------------------- Attributs protégés
  unsigned int currTaille;
  unsigned int maxTaille;
  Trajet** tab;
};
//-------------------------------- Autres définitions dépendantes de <TableauTrajets>
#endif // TABLEAUTRAJETS_H