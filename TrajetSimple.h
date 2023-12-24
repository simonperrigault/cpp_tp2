/*************************************************************************
                           TrajetSimple  -  description
                            -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----------------
#if ! defined ( TRAJETSIMPLE_H )
#define TRAJETSIMPLE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
// Classe qui définit un trajet simple entre deux villes à partir d'un
// moyen de transport
//------------------------------------------------------------------------

class TrajetSimple : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
  virtual void Afficher(unsigned int deltaTab = 0) const;
  virtual TrajetSimple * clone() const
  {
    return new TrajetSimple(*this);
  }


//-------------------------------------------- Constructeurs - destructeur
  TrajetSimple(const TrajetSimple & autre);
  TrajetSimple (const char* dep, const char* arr, const char* moy);

  virtual ~TrajetSimple ( );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
  char* moyen;
};

//-------------------------------- Autres définitions dépendantes de <TrajetSimple>

#endif // TRAJETSIMPLE_H

