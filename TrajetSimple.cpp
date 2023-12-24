/*************************************************************************
                           TrajetSimple  -  description
                            -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetSimple::Afficher(unsigned int deltaTab) const
{
  unsigned int i;
  for (i=0; i<deltaTab; i++)
  {
    cout << "\t";
  }
  cout << "Trajet simple " << depart << " -> " << arrivee << " en " << moyen << endl;
}

//-------------------------------------------- Constructeurs - destructeur
TrajetSimple::TrajetSimple(const TrajetSimple & autre)
  : Trajet(autre)
{
#ifdef MAP
  cout << "Appel au constructeur de copie de <TrajetSimple>" << endl;
#endif
  moyen = new char[strlen(autre.moyen)+1];
  strcpy(moyen, autre.moyen);
}

TrajetSimple::TrajetSimple (const char* dep, const char* arr, const char* moy)
    : Trajet(dep, arr)
{
#ifdef MAP
  cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
  moyen = new char[strlen(moy)+1];
  strcpy(moyen, moy);
} //----- Fin de TrajetSimple


TrajetSimple::~TrajetSimple ( )
{
#ifdef MAP
  cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
  delete[] moyen;
} //----- Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

