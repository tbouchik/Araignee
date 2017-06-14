#include "zonetext.h"
#include <string>
#include <iostream>
using namespace std ;

zonetext::zonetext(string joueur_1, string joueur_2)
{
    Joueur_1 = joueur_1 ;
    Joueur_2 = joueur_2 ;
    joueur_Actu(Joueur_1) ;
    top_Depart() ;
}

QString zonetext::getText(int tours_Jeu, bool issue)
{
    message_Affiche.clear() ;
    if(issue == true)
    {
        gagnant(tours_Jeu % 2) ;
    }
    else if (tours_Jeu <= 5)
    {
        if (tours_Jeu % 2 == 0) joueur_Actu(Joueur_1) ;
        else joueur_Actu(Joueur_2) ;
    }
    return message_Affiche ;
}

string zonetext::get_instructions()
{
    return instructions ;
}

void zonetext::joueur_Actu(string joueur)
{
    message_Affiche.append(QString::fromStdString(joueur)) ;
    message_Affiche.append(" c'est votre tour.") ;
}

void zonetext::gagnant(int joueur)
{
    string gagnant ;
    if (joueur == 1)
    {
        gagnant = Joueur_1 ;
    }
    if (joueur == 2)
    {
        gagnant = Joueur_2 ;
    }
    message_Affiche.append(QString::fromStdString(gagnant)) ;
    message_Affiche.append(" gagne !") ;
}

void zonetext::top_Depart()
{
    instructions = "Choisissez un spot pour placer votre pièce." ;
}

void zonetext::dephasage()
{
    instructions = "Selectionnez la pièce à déplacer puis le spot d'arrivée." ;
}

void zonetext::fin()
{
    instructions = "Partie terminée !" ;
}
