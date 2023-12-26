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
#include "../int/TrajetSimple.h"

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

string TrajetSimple::getCSV() const
{
  string res = "TS;" + depart + ";" + arrivee + ";" + moyen;
  return res;
}

//-------------------------------------------- Constructeurs - destructeur
TrajetSimple::TrajetSimple(const TrajetSimple & autre)
  : Trajet(autre), moyen(autre.moyen)
{
#ifdef MAP
  cout << "Appel au constructeur de copie de <TrajetSimple>" << endl;
#endif
}

TrajetSimple::TrajetSimple (const char* dep, const char* arr, const char* moy)
    : Trajet(dep, arr), moyen(moy)
{
#ifdef MAP
  cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
} //----- Fin de TrajetSimple

TrajetSimple::TrajetSimple (const string & dep, const string & arr, const string & moy)
    : Trajet(dep, arr), moyen(moy)
{
#ifdef MAP
  cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
} //----- Fin de TrajetSimple


TrajetSimple::~TrajetSimple ( )
{
#ifdef MAP
  cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
} //----- Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

