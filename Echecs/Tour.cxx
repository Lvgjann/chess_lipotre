#include "Tour.h"
#include <iostream>

Tour::Tour(int x, int y, bool white) : Piece(x, y , white){}

void Tour::affiche() const{
    if(m_white){
        std::cout << "T ";
    }else{
        std::cout << "t ";
    }
}

bool Tour::mouvementValide(const Echiquier &e, int x, int y) const {
    bool caseLibre = Piece::mouvementValide(e, x, y);
    return caseLibre &&( 
    (x-m_x == 0 && y-m_y != 0) || 
    (x-m_x != 0 && y-m_y == 0)) ;
}

char
Tour::getChar() const{
    return m_white ? 'T' : 't';
}
