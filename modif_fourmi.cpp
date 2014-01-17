//
//  modif_fourmi.cpp
//  Fourmis
//
//  Created by Lucas Chauvin  on 06/01/2014.
//  Copyright (c) 2014 Supinfo. All rights reserved.
//

#include "modif_fourmi.h"
#include "Etat_plateau.h"
#include <iostream>

using namespace std;


modif::modif(int c, int d)
{
    modif_couleurr=c;
    modif_directionr=d;
    
}

int modif::modif_couleur()
{
    return modif_couleurr;
}
int modif::modif_direction()
{
    return modif_directionr;
}

fourmi::fourmi(plateau& plat, int c1, int d1, int c2, int d2)
{
    i = (plat.getHauteur())/ 2;     //placement de la fourmi au milieu
    j = (plat.getLargeur()) / 2;        //Idem
    
    plat.getTab()[i][j].inverser_libre();     //
    
    direction = 1;      //Nord par défaut
    modif modif1(c1,d1);
    modif modif2(c2,d2);
    regles[0] = modif1;     //Initialisation des regles
    regles[1] = modif2;//Idem
}

void fourmi::change_direction(int c)
{
    if (c == 2) {
        (direction > 1) ? direction-- : direction = 4;        //ternaire à expliquer. On decremente la direction pour faire tourner la fourmi
    } else {
        (direction < 4) ? direction++ : direction = 1;        //ternaire à expliquer. On inermente pour faire tourner la fourmi
    }
    stat_direction[direction-1]++;
}

void fourmi::deplace(plateau& plat)
{
    plat.getTab()[i][j].inverser_libre();
    change_direction(plat.getTab()[i][j].getCouleur());
    
    int couleur_act=plat.getTab()[i][j].getCouleur();
    plat.getTab()[i][j].setCouleur(regles[couleur_act-1].modif_couleur());
    switch(direction)
    {
        case 1:
            i--;
            break;
        case 2:
            j--;
            break;
        case 3:
            i++;
            break;
        case 4:
            j++;
            break;
    }
    
    plat.getTab()[i][j].inverser_libre();
    
    if (i == plat.getLargeur() - 1 || i == 0 || j == plat.getHauteur() - 1 || j == 0)       //Condition de depassement tableau
    {
        i++;        //augmentation de la taille du tableau
        j++;        //Idem
        ++plat;     //placement fourmi
    }
}

void fourmi::deplace_double(plateau& plat)
{
    plat.getTab()[i][j].inverser_libre();
    change_direction(plat.getTab()[i][j].getCouleur());
    
    int couleur_act=plat.getTab()[i][j].getCouleur();
    plat.getTab()[i][j].setCouleur(regles[couleur_act-1].modif_couleur());
    switch(direction)
    {
        case 1:
            i -= 2;
            break;
        case 2:
            j += 2;
            break;
        case 3:
            i += 2;
            break;
        case 4:
            j -= 2;
            break;
    }
    plat.getTab()[i][j].inverser_libre();
    if (i >= plat.getLargeur() -2 || i <= 1 || j == plat.getHauteur() -2 || j <= 1)
    {
        i++;
        j++;
        ++plat;
    }
}

void fourmi::stat_deplacement()
{
    int total = stat_direction[0]+stat_direction[1]+stat_direction[2]+stat_direction[3];
    cout<<"statistiques de déplacements"<<endl;
    cout<< "Nord : "<< stat_direction[0] * 100 / total <<"%"<<endl;
    cout<< "Sud : "<< stat_direction[1] * 100 / total <<"%"<<endl;
    cout<< "Est : "<< stat_direction[2] * 100 / total <<"%"<<endl;
    cout<< "Ouest : "<< stat_direction[3] * 100 / total <<"%"<<endl;
}