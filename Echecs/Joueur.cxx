#include "Joueur.h"
#include <iostream>
#include <memory>

Joueur::Joueur(bool white) 
    : _white(white){
        std::cout << "Joueur white ?" << _white << std::endl;
        unsigned int l_begin = (_white ? 1 : 7);

        unsigned int l = l_begin, c=1;
        for (unsigned int i=0; i < NB_PIECES; ++i){
            _pieces[i]->init(c, l, _white);
            c++;
            if (c == NB_COLS+1){
                ++l;
                c=1;
            }
        }

}

void Joueur::affiche() const
{
    for (auto p : _pieces)
        p->affiche();
    /*for (unsigned int i=0; i<_pieces.size(); ++i){
        _pieces[i].affiche();
    }*/
}

void Joueur::initEchiquier(Echiquier & echiquier){
    /*for (unsigned int i=0; i<_pieces.size(); ++i){
        echiquier.placer(&_pieces[i]);
    }*/
    for (auto p : _pieces)
        echiquier.placer(std::shared_ptr<Piece>(p));
}