/*************************************************************************
                           Trajet  -  description
                            -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "../int/Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


//-------------------------------------------- Constructeurs - destructeur
Trajet::Trajet (const Trajet & autre)
  : depart(autre.depart), arrivee(autre.arrivee)
{
#ifdef MAP
  cout << "Appel au constructeur de copie de <Trajet>" << endl;
#endif
}

Trajet::Trajet (const char* dep, const char* arr)
  : depart(dep), arrivee(arr)
{
#ifdef MAP
  cout << "Appel au constructeur de <Trajet>" << endl;
#endif
} //----- Fin de Trajet

Trajet::Trajet (const string & dep, const string & arr)
  : depart(dep), arrivee(arr)
{
#ifdef MAP
  cout << "Appel au constructeur de <Trajet>" << endl;
#endif
} //----- Fin de Trajet


Trajet::~Trajet ( )
{
#ifdef MAP
  cout << "Appel au destructeur de <Trajet>" << endl;
#endif
} //----- Fin de ~Trajet


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

