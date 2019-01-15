#include "Reine.h"
#include <iostream>

Reine::Reine(int x, int y, bool white) : Piece(x,y,white){}

void Reine::affiche() const {
    if(m_white){
        std::cout << "Q ";
    }
    else {
        std::cout << "q ";
    }
}

bool Reine::mouvementValide(const Echiquier& echiquier, int x, int y) const {
    bool caseLibre = Piece::mouvementValide(echiquier, x, y);
    return (caseLibre && ((x == m_x) || (y == m_y)));
}
char Reine::getChar() const{
    return m_white ? 'Q' : 'q';
}
