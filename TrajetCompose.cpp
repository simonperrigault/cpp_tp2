/*************************************************************************
                           TrajetCompose  -  description
                            -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetCompose::Afficher(unsigned int deltaTab) const
{
  unsigned int i;
  for (i=0; i<deltaTab; i++)
  {
    cout << "\t";
  }
  cout << "Trajet composé de " << depart << " à " << arrivee << " :";
  tableauTrajets.Afficher(deltaTab+1, false);
}

//-------------------------------------------- Constructeurs - destructeur

TrajetCompose::TrajetCompose (const TrajetCompose & autre)
    : Trajet(autre), tableauTrajets(autre.tableauTrajets)
{
#ifdef MAP
  cout << "Appel au constructeur de copie de <TrajetCompose>" << endl;
#endif
}

TrajetCompose::TrajetCompose (TrajetSimple** listeT, unsigned int taille)
    : Trajet(listeT[0]->GetDepart(), listeT[taille-1]->GetArrivee()), tableauTrajets()
{
#ifdef MAP
  cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
  unsigned int i;
  for (i = 0; i < taille; i++)
  {
    tableauTrajets.Ajouter(listeT[i]);
  }
} //----- Fin de TrajetCompose


TrajetCompose::~TrajetCompose ( )
{
#ifdef MAP
  cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
} //----- Fin de ~TrajetCompose


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

