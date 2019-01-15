#include "JoueurBlanc.h"

using namespace std;

JoueurBlanc::JoueurBlanc() : Joueur(true) {
    _pieces.push_back(make_shared<Roi>(5,1,true));
    _pieces.push_back(make_shared<Reine>(4,1,true));
    _pieces.push_back(make_shared<Fou>(6,1,true));
    _pieces.push_back(make_shared<Fou>(3,1,true));
    _pieces.push_back(make_shared<Tour>(1,1,true));
    _pieces.push_back(make_shared<Tour>(8,1,true));
    _pieces.push_back(make_shared<Cavalier>(2,1,true));
    _pieces.push_back(make_shared<Cavalier>(7,1,true));
    for (int i = 1; i <= 8; i++) {
         _pieces.push_back(make_shared<Pion>(i,2,true));
    }
}

JoueurBlanc::~JoueurBlanc() {}