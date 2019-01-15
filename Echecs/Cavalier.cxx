 #include "Cavalier.h"
#include "Piece.h"
#include "Echiquier.h"
#include <iostream>

Cavalier::Cavalier(int x, int y, bool white) : Piece(x, y , white){}

void Cavalier::affiche() const{
    if(m_white){
        std::cout << "C ";
    }else{
        std::cout << "c ";
    }
}

bool Cavalier::mouvementValide(const Echiquier &e, int x, int y) const{
    bool caseLibre = Piece::mouvementValide(e, x, y);
    return caseLibre &&( 
    (abs(x-m_x) == 2 && abs(y-m_y) == 1) || 
    (abs(x-m_x) == 1 && abs(y-m_y) == 2)) ;
}

char Cavalier::getChar() const{
    return m_white ? 'C' : 'c';
}
