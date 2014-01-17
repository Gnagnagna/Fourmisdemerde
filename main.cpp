//
//  main.cpp
//  Fourmis
//
//  Created by Lucas Chauvin  on 06/01/2014.
//  Copyright (c) 2014 Supinfo. All rights reserved.
//

#include <iostream>
#include "Etat_plateau.h"
#include "modif_fourmi.h"

using namespace std;

int main(int argc, const char * argv[])
{   int cases_noires;
    int he, le, i;
    int choix_regle;
    cout<<"Quelle hauteur voulez vous ? ";
    cin>>he;
    cout<<"Quelle largeur voulez vous ? ";
    cin>>le;
    int N;  //nombre de déplacements voulus
    cout<<"Combien de déplacements voulez vous ? ";
    cin>>N;
    cout<<"Quelle règle voulez vous ? 1. Normale 2. Turmite 3. Rapide : ";
    cin>>choix_regle;
    plateau* plat = new plateau(le,he);
    cout << "Combien de cases noires souhaitez-vous ? ";
    cin >> cases_noires;
    
    if (cases_noires > 0)
    {
        // Pour chaque case on demande les coordonnées
        for (int i = 0; i < cases_noires; i++)
        {
            int x;
            int y;
            
            cout << "Abscisse de la cellule noire n°" << i + 1 <<" : ";
            cin >> x;
            cout << endl << "Ordonnée de la cellule noire n°" << i + 1 << " : ";
            cin >> y;
            plat->getTab()[x][y].setCouleur(2);
        }
    }
    
    fourmi mafourmi(*plat);
    if(choix_regle == 1)
    {
        for(i=0;i<N;i++)
        {
            mafourmi.deplace(*plat);
            plat->affiche();
        }
    }
    else if (choix_regle == 2)
    {
        //(*plat,1,2, 2,1);
    }
    else if (choix_regle == 3)
    {
        for(i=0;i<N;i++)
        {
            mafourmi.deplace_double(*plat);
            plat->affiche();
        }
    }
    mafourmi.stat_deplacement();
    return 0;
}

