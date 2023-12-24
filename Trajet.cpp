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
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


//-------------------------------------------- Constructeurs - destructeur
Trajet::Trajet (const Trajet & autre)
{
#ifdef MAP
  cout << "Appel au constructeur de copie de <Trajet>" << endl;
#endif
  depart = new char[strlen(autre.depart)+1];
  strcpy(depart, autre.depart);

  arrivee = new char[strlen(autre.arrivee)+1];
  strcpy(arrivee, autre.arrivee);
}

Trajet::Trajet (const char* dep, const char* arr)
{
#ifdef MAP
  cout << "Appel au constructeur de <Trajet>" << endl;
#endif
  depart = new char[strlen(dep)+1];
  strcpy(depart, dep);

  arrivee = new char[strlen(arr)+1];
  strcpy(arrivee, arr);
} //----- Fin de Trajet


Trajet::~Trajet ( )
{
#ifdef MAP
  cout << "Appel au destructeur de <Trajet>" << endl;
#endif
  delete[] depart;
  delete[] arrivee;
} //----- Fin de ~Trajet


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

