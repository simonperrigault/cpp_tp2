/*************************************************************************
                           TrajetCompose  -  description
                            -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ----------------
#if ! defined ( TRAJETCOMPOSE_H )
#define TRAJETCOMPOSE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "TrajetSimple.h"
#include <vector>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
// Classe qui définit un trajet composé de plusieurs trajets simples
//  en utilisant un TableauTrajets
//------------------------------------------------------------------------

class TrajetCompose : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
  virtual void Afficher(unsigned int deltaTab = 0) const;
  virtual TrajetCompose * clone() const
  {
    return new TrajetCompose(*this);
  }

//-------------------------------------------- Constructeurs - destructeur
  TrajetCompose(const TrajetCompose & autre);
  TrajetCompose (TrajetSimple** listeT, unsigned int taille);
  // construit un trajet composé à partir de la liste de trajets,
  // les trajets doivent être continus

  virtual ~TrajetCompose ( );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
  vector<TrajetSimple*> tableauTrajets;
};

//-------------------------------- Autres définitions dépendantes de <TrajetCompose>

#endif // TRAJETCOMPOSE_H

