#include "Pion.h"
#include "Piece.h"
#include "Echiquier.h"
#include <iostream>

Pion::Pion(int x, int y, bool white) : Piece(x, y , white){}

void 
Pion::affiche() const{
    if(m_white){
        std::cout << "P ";
    }else{
        std::cout << "p ";
    }
}

bool 
Pion::mouvementValide(const Echiquier &e, int x, int y) const{
    bool caseLibre = Piece::mouvementValide(e, x, y);
    return caseLibre && 
    (m_white ? y - m_y == -1 : y - m_y == 1) && (x - m_x == 0) ;
}

char
Pion::getChar() const{
    return m_white ? 'P' : 'p';
}
