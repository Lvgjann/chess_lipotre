#include "Fou.h"
#include "Piece.h"
#include "Echiquier.h"
#include <iostream>

Fou::Fou(int x, int y, bool white) : Piece(x, y , white){}

void 
Fou::affiche() const{
    if(m_white){
        std::cout << "F ";
    }else{
        std::cout << "f ";
    }
}

bool Fou::mouvementValide(const Echiquier &e, int x, int y) const{
    bool caseLibre = Piece::mouvementValide(e, x, y);
    //TODO : Modifer le calcul dans le return aui est la copie de celui de la tour (adapter aux diagonales).
    return caseLibre &&( 
    (x-m_x == 0 && y-m_y != 0) || 
    (x-m_x != 0 && y-m_y == 0)) ;
}

char
Fou::getChar() const{
    return m_white ? 'T' : 't';
}
