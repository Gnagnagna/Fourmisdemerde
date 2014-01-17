//
//  Etat_plateau.h
//  Fourmis
//
//  Created by Lucas Chauvin  on 06/01/2014.
//  Copyright (c) 2014 Supinfo. All rights reserved.
//

#ifndef __Fourmis__Etat_plateau__
#define __Fourmis__Etat_plateau__

#include <iostream>

class Etat {
private:
    int couleur;
    bool libre;
public:
    Etat(int c=1, bool l=true);
    void inverser_libre();
    bool getLibre();
    int getCouleur();
    void setCouleur(int c);
};

class plateau {
private:
    Etat** tab;
    int hauteur;
    int largeur;
    
public:
    plateau(int h=21, int l=51);    //constructeur
    plateau(plateau const& plateau);    //constructeur de copie
    ~plateau(); //destructeur
    plateau& operator=(const plateau &plateau); //opérateur d'affectation
    plateau& operator++();  //surcharge opérateur
    void affiche(); //affichage console
    void affiche_fichier(); //écriture dans le fichier
    
    int getLargeur();   //setter largeur
    int getHauteur();   //setter hauteur
    Etat** getTab(); //setter plateau
};

#endif /* defined(__Fourmis__Etat_plateau__) */
