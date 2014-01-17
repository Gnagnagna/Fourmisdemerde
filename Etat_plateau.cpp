//
//  Etat_plateau.cpp
//  Fourmis
//
//  Created by Lucas Chauvin  on 06/01/2014.
//  Copyright (c) 2014 Supinfo. All rights reserved.
//

#include <iostream>
#include "modif_fourmi.h"

using namespace std;

void Etat::inverser_libre()
{
    if(libre==true)
    {
        libre=false;
    }
    else if (libre==false)
    {
        libre=true;
    }
}

Etat::Etat(int c,bool l)
{
    couleur=c;
    libre=l;
}

bool Etat::getLibre()
{
    return libre;
}

int Etat::getCouleur()
{
    return couleur;
}


plateau::plateau(int l, int h)          //initialise le tableau
{
    int i;
    largeur=l;
    hauteur=h;
    if(!(hauteur > 0 && hauteur % 2 ==1))
    {
        hauteur=21;
    }
    if(!(largeur > 0 && largeur % 2==1))
    {
        largeur=51;
    }
    
    Etat ** tabe;
    tabe=new Etat*[hauteur];
    for(i=0;i<hauteur;i++)
    {
        tabe[i]=new Etat[largeur];
    }
    tab=tabe;
}

plateau::plateau(plateau const& plateau) : hauteur(plateau.hauteur), largeur(plateau.largeur)
{
    // Allocation dynamique du tableau d'objets
    tab = new Etat*[hauteur];
    for (int i = 0; i < hauteur; i++) {
        tab[i] = new Etat[largeur];
    }
    
    // Copie des objets dans les cases du tableau
    for (int i = 0; i < hauteur; i++) {
        for (int j = 0; j < largeur; j++) {
            tab[i][j] = *new Etat(plateau.tab[i][j]);
        }
    }
}

void plateau::affiche()
{
    int i,j;
    for(i=0; i<hauteur; i++)
    {
        for(j=0; j<largeur; j++)
        {
            bool etat_libre=tab[i][j].getLibre();
            int etat_couleur=tab[i][j].getCouleur();
            if(etat_libre==0)
            {
                cout<<"o";
            }
            else if(etat_libre==1 && etat_couleur==1)
            {
                cout<<" ";
            }
            else if(etat_libre==1 && etat_couleur==2)
            {
                cout<<".";
            }
        }
        cout<<endl;
    }
    
}
//void plateau::affiche_fichier() //a modifier pour Windows
//{

plateau::~plateau() //libération mémoire
{
    for (int i = 0; i < hauteur; i++) {
        delete [] tab[i];
    }
    delete [] tab;
}

plateau& plateau::operator=(const plateau &plateau)
{
    {
        for (int i = 0; i < hauteur; i++) {
            for (int j = 0; j < largeur; j++) {
                tab[i][j] = *new Etat(plateau.tab[i][j]);
            }
        }
        return *this;
    }
}

plateau& plateau::operator++()
{
    plateau temp = *new plateau(*this);
    
    for (int i = 0; i < hauteur; i++) {
        delete [] tab[i];
    }
    delete [] tab;
    
    hauteur += 2;
    largeur += 2;
    
    // Allocation du tableau de recopie
    tab = new Etat*[hauteur];
    for (int i = 0; i < hauteur; i++) {
        tab[i] = new Etat[largeur];
    }
    
    // Copie cellule ancien tableau
    for (int i = 1; i < hauteur - 1; i++) {
        for (int j = 1; j < largeur - 1; j++) {
            tab[i][j] = temp.tab[i - 1][j - 1];
        }
    }
    
    return *this;
}

int plateau::getHauteur()
{
    return hauteur;
}

int plateau::getLargeur()
{
    return largeur;
}
void Etat::setCouleur(int c)
{couleur=c;
}

Etat** plateau::getTab()
{
    return tab;
}
