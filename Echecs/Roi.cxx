#include "Roi.h"
#include <iostream>

Roi::Roi(int x, int y, bool white) : Piece(x,y,white){}

void Roi::affiche() const {
    if(m_white){
        std::cout << "R ";
    }
    else {
        std::cout << "r ";
    }
}

bool Roi::mouvementValide(const Echiquier& echiquier, int x, int y) const {
    bool caseLibre = Piece::mouvementValide(echiquier, x, y);
    return caseLibre &&
    std::max(abs(x-m_x), abs(y-m_y)) == 1;
}

char Roi::getChar() const{
    return m_white ? 'K' : 'k';
}
