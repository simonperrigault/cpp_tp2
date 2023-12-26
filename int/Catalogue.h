/*************************************************************************
                           Catalogue  -  description
                            -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "TrajetSimple.h"
#include <vector>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
// Classe qui gère un catalogue de trajets et l'affichage de l'interface
// pour l'utilisateur
//------------------------------------------------------------------------

class Catalogue
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
  void Afficher() const;
  void AjouterTrajet(const Trajet* nouveau);

  void FaireParcoursSimple(const string & dep, const string & arr) const;
  // renvoie la liste des trajets du catalogue qui ont le même départ et la même arrivée
  // que ceux rentrés par l'utilisateur

  void FaireParcoursComplexe(const string & dep, const string & arr) const;
  // renvoie toutes les combinaisons de trajets du catalogue empruntant chaque
  // ville au maximum une fois et allant du départ jusqu'à l'arrivée donnés par l'utilisateur

  void ChargerCatalogue(const string & nomFichier, int mode, int n = 0, int m = 0, const string & ville = "");

//-------------------------------------------- Constructeurs - destructeur
  Catalogue ();
  // max représente le nombre maximal de trajets pouvant aller dans le
  // catalogue à l'initialisation du tableau (peut augmenter)

  virtual ~Catalogue ( );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

  void dfs(const string & currPoint, const string & arr, vector<Trajet*> & currChemin, vector<vector<Trajet*>> & res) const;
  // fonction récursive permettant de construire les combinaisons de trajets
  // pour le parcours complexe

//----------------------------------------------------- Attributs protégés
  vector<Trajet*> catalogue;
};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // CATALOGUE_H

