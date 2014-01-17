//
//  modif_fourmi.h
//  Fourmis
//
//  Created by Lucas Chauvin  on 06/01/2014.
//  Copyright (c) 2014 Supinfo. All rights reserved.
//

#ifndef __Fourmis__modif_fourmi__
#define __Fourmis__modif_fourmi__

#include <iostream>
#include "Etat_plateau.h"


class modif
{
private:
    int modif_couleurr;    //couleur retournee
    int modif_directionr;       //direction retournee
public:
    modif(int c=2, int d=1);
    int modif_couleur();
    int modif_direction();
    
};

class fourmi {
private:
    int i,j;
    int direction;
    int stat_direction[4];
    int N[1]; //Nbre de generations voulues
    modif regles[2];
    
public:
    fourmi(plateau& plat, int c1=2, int d1=1, int c2=1, int d2=2);
    void change_direction (int c);
    void deplace (plateau& plat);
    void deplace_double(plateau& plat);
    void stat_deplacement();
    
};
#endif /* defined(__Fourmis__modif_fourmi__) */
