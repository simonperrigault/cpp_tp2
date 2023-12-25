/*************************************************************************
                           Trajet  -  description
                            -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if ! defined ( TRAJET_H )
#define TRAJET_H

//--------------------------------------------------- Interfaces utilisées
#include <string>

using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
// Classe abstraite qui définit un trajet entre deux villes
//
//------------------------------------------------------------------------

class Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
  const string GetDepart() const
  {
    return depart;
  }
  const string GetArrivee() const
  {
    return arrivee;
  }
  
  virtual void Afficher(unsigned int deltaTab = 0) const = 0;
  // deltaTab définit le nombre de tabulations à ajouter avant chaque ligne
  // pour faire un affichage plus lisible pour les trajets composés
  virtual Trajet * clone() const = 0;
  virtual ~Trajet ( );

//------------------------------------------------------------------ PRIVE

protected:
// on met le constructeur en protected car c'est une classe abstraite
  Trajet (const char* dep, const char* arr);
  Trajet (const string & dep, const string & arr);
  Trajet (const Trajet & autre);

//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
  string depart;
  string arrivee;
};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // TRAJET_H

