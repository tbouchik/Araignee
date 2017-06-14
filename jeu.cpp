#include "jeu.h"
#include "piece.h"
#include "joueur.h"
#include "zonetext.h"
#include <iostream>
using namespace std ;

jeu::jeu(string nom_Joueur1, string nom_Joueur2, QObject *parent): QObject(parent),Joueur1(nom_Joueur1,true),Joueur2(nom_Joueur2,false),message(nom_Joueur1,nom_Joueur2)
{
    tours_compt = 0 ;
    pieceListe = new piece[6] ;
    victoire_jeu = false ;
}

void jeu::pilotage(int slot)
{
    bool existsalready = false;
    if(victoire_jeu == false)
    {
        if (tours_compt < 6)
        {
            for(int i = 0 ; i < tours_compt ; i++)
            {
                if(slot == pieceListe[i].getPosition()) existsalready = true ;
            }
            if (existsalready == false)
            {
                premiere_Etape(slot) ;
                tours_compt++ ;
            }
        }
        else
        {
            jeu::seconde_Etape(slot) ;
        }
        victoire() ;
        changePos() ;
        changeBord() ;
        changeVis() ;
        changeTexte() ;
    }
}

void jeu::premiere_Etape(int slot)
{
    pieceListe[tours_compt] = piece(tours_compt % 2, slot) ;
}

void jeu::seconde_Etape(int slot)
{
    bool existsalready = false, occupiedalready = false ;
    for(int i = 0 ; i < 6 ; i++)
    {
       if(slot == pieceListe[i].getPosition() && tours_compt % 2 == i % 2)
       {
           existsalready = true ;
           for(int j = 0 ; j < 6 ; j++)
           {
               if(pieceListe[j].getSelected() == true)
               {
                   pieceListe[j].setSelected(false) ;
               }
           }
           pieceListe[i].setSelected(true) ;
        }
    }
    if (existsalready == false)
    {
        for(int k = 0 ; k < 6 && k < tours_compt ; k++)
        {
            if(slot == pieceListe[k].getPosition()) occupiedalready = true ;
        }
        if(occupiedalready == false)
        {
            for(int l = 0 ; l < 6 ; l++)
            {
                if(pieceListe[l].getSelected() == true)
                {
                    pieceListe[l].setPosition(slot) ;
                    tours_compt++ ;
                }
            }
        }
    }
}

QList<QString> jeu::readPos()
{
    QList<QString> positions ;
    for(int i = 0 ; i < 9 ; i++)
    {
        positions << "#ffffff" ;
    }
    for(int j = 0 ; j < 6 && j < tours_compt ; j++)
    {
        if(j % 2 == 0)
        {
            positions[pieceListe[j].getPosition()] = "#cccccc" ;
        }
        else
        {
            positions[pieceListe[j].getPosition()] = "#000000" ;
        }
    }
    return positions ;
}

QList<QString> jeu::readBord()
    {
        QList<QString> bordure ;
        for(int i = 0 ; i < 9 ; i++)
        {
            bordure << "#ffffff" ;
        }
        for(int j = 0 ; j < 6 && j < tours_compt ; j++)
        {
            if(j % 2 == 0)
            {
                bordure[pieceListe[j].getPosition()] = "#000000" ;
            }
            else
            {
                bordure[pieceListe[j].getPosition()] = "#cccccc" ;
            }
        }
        return bordure ;
    }

QList<bool> jeu::readVis()
{
    QList<bool> visible ;
    for(int i = 0 ; i < 9 ; i++)
    {
        visible << false ;
    }
    for(int j = 0 ; j < 6 && j < tours_compt ; j++)
    {
        visible[pieceListe[j].getPosition()] = true ;
    }
    return visible ;
}

int jeu::getTour()
{
    return tours_compt ;
}

void jeu::victoire()
{
    int i ;
    int* caseJ1 = new int[3] ;
    int* caseJ2 = new int[3] ;
    if(tours_compt >= 5)
    {
        for(int j = 0 ; j < 6 && j < tours_compt ; j++)
        {
            i = j / 2 ;
            if(j % 2 == 0)
            {
                caseJ1[i] = pieceListe[j].getPosition() ;
            }
            else
            {
                caseJ2[i] = pieceListe[j].getPosition() ;
            }
        }
        if (tours_compt % 2 == 1) testVictoire(caseJ1) ;
        else testVictoire(caseJ2) ;
        delete[] caseJ1 ;
        delete[] caseJ2;
    }
}

bool jeu::testVictoire(int *pPos)
{
    int a ;
    if (pPos[0] > pPos[1])
    {
        a = pPos[0] ;
        pPos[0] = pPos[1] ;
        pPos[1] = a ;
    }
    if (pPos[1] > pPos[2])
    {
        a = pPos[2] ;
        pPos[2] = pPos[1] ;
        pPos[1] = a ;
    }
    if (pPos[0] > pPos[1])
    {
        a = pPos[0] ;
        pPos[0] = pPos[1] ;
        pPos[1] = a ;
    }
    if (pPos[0] % 3 == pPos[1] % 3 && pPos[0] % 3 == pPos[2] % 3)
    {
        victoire_jeu = true ;
    }
    else if (pPos[0] / 3 == pPos[1] / 3 && pPos[0] / 3 == pPos[2] / 3)
    {
        victoire_jeu = true ;
    }
    else if (pPos[0] == 2 && pPos[1] == 4 && pPos[2] == 6)
    {
        victoire_jeu = true ;
    }
    else if (pPos[0] == 0 && pPos[1] == 4 && pPos[2] == 8)
    {
        victoire_jeu = true ;
    }
}

QString jeu::currentText()
{
    return message.getText(tours_compt, victoire_jeu) ;
}
