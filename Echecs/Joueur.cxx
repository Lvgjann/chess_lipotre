#include "Joueur.h"

Joueur::Joueur(bool white) 
    : _white(white){}
Joueur::~Joueur(){}

void Joueur::affiche() const
{
    for (auto p : _pieces)
        p->affiche();
    printf("\n");
}

void Joueur::initEchiquier(Echiquier & echiquier){

    for (auto p : _pieces)
       echiquier.placer(std::shared_ptr<Piece>(p));
}