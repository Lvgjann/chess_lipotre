#include "JoueurNoir.h"

using namespace std;

JoueurNoir::JoueurNoir() : Joueur(false) {
    
    _pieces.push_back(make_shared<Roi>(5,8,false));
    _pieces.push_back(make_shared<Reine>(4,8,false));
    _pieces.push_back(make_shared<Fou>(6,8,false));
    _pieces.push_back(make_shared<Fou>(3,8,false));
    _pieces.push_back(make_shared<Tour>(1,8,false));
    _pieces.push_back(make_shared<Tour>(8,8,false));
    _pieces.push_back(make_shared<Cavalier>(2,8,false));
    _pieces.push_back(make_shared<Cavalier>(7,8,false));


    for (int i = 1; i <= 8; i++) {
        _pieces.push_back(make_shared<Pion>(i,7,false));
    }
}

JoueurNoir::~JoueurNoir() {}