#include "JoueurBlanc.h"
#include <iostream>
#include <memory>

#include"Cavalier.h"
#include"Fou.h"
#include"Pion.h"
#include"Reine.h"
#include"Roi.h"
#include"Tour.h"

using namespace std;

JoueurBlanc::JoueurBlanc() : Joueur(true) {
    _pieces[0] = make_shared<Roi>(Roi(4,1, true ));
    _pieces[1] = make_shared<Reine>(Reine(5,1, true ));
    _pieces[2] = make_shared<Fou>(Fou(6,1, true));
    _pieces[3] = make_shared<Fou>(Fou(3,1, true));
    _pieces[4] = make_shared<Tour>(Tour(1,1, true));
    _pieces[5] = make_shared<Tour>(Tour(8,1, true));
    _pieces[6] = make_shared<Cavalier>(Cavalier(2,1, true));
    _pieces[7] = make_shared<Cavalier>(Cavalier(7,1, true));

    for (int i = 1; i <= 8; i++) {
          _pieces[7+i] = make_shared<Pion>(Pion(i,2,true));
    }
}

JoueurBlanc::~JoueurBlanc() {
    std::cout << "Destructor Joueur blanc ?" << std::endl;
}