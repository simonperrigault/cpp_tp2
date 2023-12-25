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

//------------------------------------------------------ Include personnel
#include "../int/TrajetCompose.h"

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
  cout << "Trajet composé de " << depart << " à " << arrivee << " :" << endl;
  for (vector<TrajetSimple*>::const_iterator it = tableauTrajets.begin(); it != tableauTrajets.end(); ++it)
  {
    (*it)->Afficher(deltaTab+1);
  }
}


//-------------------------------------------- Constructeurs - destructeur

TrajetCompose::TrajetCompose (const TrajetCompose & autre)
    : Trajet(autre), tableauTrajets(autre.tableauTrajets.size(), nullptr)
{
#ifdef MAP
  cout << "Appel au constructeur de copie de <TrajetCompose>" << endl;
#endif
  unsigned int i;
  for (i=0; i<autre.tableauTrajets.size(); ++i)
  {
    tableauTrajets[i] = autre.tableauTrajets[i]->clone();
  }
}

TrajetCompose::TrajetCompose (TrajetSimple** listeT, unsigned int taille)
    : Trajet(listeT[0]->GetDepart(), listeT[taille-1]->GetArrivee()), tableauTrajets(taille, nullptr)
{
#ifdef MAP
  cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
  unsigned int i;
  for (i=0; i<taille; ++i)
  {
    tableauTrajets[i] = listeT[i]->clone();
  }
} //----- Fin de TrajetCompose


TrajetCompose::~TrajetCompose ( )
{
#ifdef MAP
  cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
  vector<TrajetSimple*>::iterator it;
  for (it = tableauTrajets.begin(); it != tableauTrajets.end(); ++it)
  {
    delete *it;
  }
} //----- Fin de ~TrajetCompose


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

