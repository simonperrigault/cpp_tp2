Trajet* Catalogue::creerTrajet(unsigned int delta) const
{
    Trajet* nouveau;
    int choixTrajet = -1;

    while (choixTrajet < 0 || choixTrajet > 2)
    {
        faireTab(delta);
        cout << "0 : Annuler" << endl;
        faireTab(delta);
        cout << "1 : Trajet Simple" << endl;
        faireTab(delta);
        cout << "2 : Trajet Composé" << endl;
        cin >> choixTrajet;
    }

    if (choixTrajet == 0)
    {
        return NULL;
    }

    else if (choixTrajet == 1)
    {
        char* depart = new char[20];
        char* arrivee = new char[20];
        char* moyen = new char[20];
        faireTab(delta);
        cout << "Départ : ";
        cin >> depart;
        faireTab(delta);
        cout << "Arrivée : ";
        cin >> arrivee;
        faireTab(delta);
        cout << "Moyen de transport : ";
        cin >> moyen;
        nouveau = new TrajetSimple(depart, arrivee, moyen);
        return nouveau;
    }

    Trajet** listeCompose;
    unsigned int tailleCompose;
    unsigned int i;
    faireTab(delta);
    cout << "Nombre de trajets dans le trajet composé : ";
    cin >> tailleCompose;
    listeCompose = new Trajet*[tailleCompose];
    for (i=0; i<tailleCompose; i++)
    {
        faireTab(delta);
        cout << "Etape " << i+1 << " du trajet composé" << endl;
        listeCompose[i] = creerTrajet(delta+1);
        if (listeCompose[i] == NULL)
        {
            return NULL;
        }
    }
    for (i=0; i<tailleCompose-1; i++)
    {
        if (strcmp(listeCompose[i]->GetArrivee(), listeCompose[i+1]->GetDepart()))
        {
            cout << "Les trajets ne sont pas continus" << endl;
            return NULL;
        }
    }
    nouveau = new TrajetCompose(listeCompose, tailleCompose);
    return nouveau;
}


void Catalogue::SupprimerTrajet(unsigned int indice)
{
    unsigned int i;
    Trajet* temp;
    for (i=indice; i<currTaille-1; i++)
    {
        temp = listeCatalogue[i];
        listeCatalogue[i] = listeCatalogue[i+1];
        listeCatalogue[i+1] = temp;
    }
    delete listeCatalogue[currTaille--];
}


//------------------------------------------------- Surcharge d'opérateurs
Catalogue & Catalogue::operator = ( const Catalogue & unCatalogue )
// Algorithme :
//
{
    unsigned int i;

    for (i=0; i<currTaille; i++)
    {
        delete listeCatalogue[i];
    }
    delete listeCatalogue;

    currTaille = unCatalogue.currTaille;
    maxTaille = unCatalogue.maxTaille;
    listeCatalogue = new Trajet*[maxTaille];
    for (i=0; i<currTaille; i++)
    {
        listeCatalogue[i] = unCatalogue.listeCatalogue[i]->clone();
    }
    return *this;
} //----- Fin de operator =


Catalogue::Catalogue ( const Catalogue & unCatalogue )
    : currTaille(unCatalogue.currTaille), maxTaille(unCatalogue.maxTaille)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Catalogue>" << endl;
#endif
    unsigned int i;
    listeCatalogue = new Trajet*[maxTaille];
    for (i=0; i<currTaille; i++)
    {
        listeCatalogue[i] = unCatalogue.listeCatalogue[i]->clone();
    }
} //----- Fin de Catalogue (constructeur de copie)



//------------------------------------------------- Surcharge d'opérateurs
Trajet & Trajet::operator = ( const Trajet & unTrajet )
// Algorithme :
//
{
    delete[] depart;
    delete[] arrivee;

    depart = new char[strlen(unTrajet.depart)+1];
    strcpy(depart, unTrajet.depart);

    arrivee = new char[strlen(unTrajet.arrivee)+1];
    strcpy(arrivee, unTrajet.arrivee);

    return *this;
} //----- Fin de operator =


Trajet::Trajet ( const Trajet & unTrajet )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Trajet>" << endl;
#endif
    depart = new char[strlen(unTrajet.depart)+1];
    strcpy(depart, unTrajet.depart);

    arrivee = new char[strlen(unTrajet.arrivee)+1];
    strcpy(arrivee, unTrajet.arrivee);
} //----- Fin de Trajet (constructeur de copie)


TrajetSimple::TrajetSimple ( const TrajetSimple & unTrajetSimple )
    : Trajet(unTrajetSimple)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <TrajetSimple>" << endl;
#endif
    moyen = new char[strlen(unTrajetSimple.moyen)+1];
    strcpy(moyen, unTrajetSimple.moyen);
} //----- Fin de TrajetSimple (constructeur de copie)

//------------------------------------------------- Surcharge d'opérateurs
TrajetSimple & TrajetSimple::operator = ( const TrajetSimple & unTrajetSimple )
// Algorithme :
//
{
    Trajet::operator=(unTrajetSimple);
    delete[] moyen;
    moyen = new char[strlen(unTrajetSimple.moyen)+1];
    strcpy(moyen, unTrajetSimple.moyen);

    return *this;
} //----- Fin de operator =

//------------------------------------------------- Surcharge d'opérateurs
TrajetCompose & TrajetCompose::operator = ( const TrajetCompose & unTrajetCompose )
// Algorithme :
//
{
    unsigned int i;
    Trajet::operator=(unTrajetCompose);
    for (i=0; i < nombreTrajets; i++)
    {
        delete listeTrajets[i];
    }
    delete[] listeTrajets;

    nombreTrajets = unTrajetCompose.nombreTrajets;
    listeTrajets = new TrajetSimple*[unTrajetCompose.nombreTrajets];
    for (i = 0; i < unTrajetCompose.nombreTrajets; i++)
    {
        listeTrajets[i] = unTrajetCompose.listeTrajets[i];
    }
    return *this;
} //----- Fin de operator =

TrajetCompose::TrajetCompose ( const TrajetCompose & unTrajetCompose )
    : Trajet(unTrajetCompose)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <TrajetCompose>" << endl;
#endif
    unsigned int i;
    for (i=0; i < nombreTrajets; i++)
    {
        delete listeTrajets[i];
    }
    delete[] listeTrajets;
    listeTrajets = new TrajetSimple*[unTrajetCompose.nombreTrajets];
    for (i = 0; i < unTrajetCompose.nombreTrajets; i++)
    {
        listeTrajets[i] = unTrajetCompose.listeTrajets[i];
    }
} //----- Fin de TrajetCompose (constructeur de copie)