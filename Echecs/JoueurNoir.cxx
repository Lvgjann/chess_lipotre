#include "JoueurNoir.h"
#include <iostream>
#include <memory>

#include"Cavalier.h"
#include"Fou.h"
#include"Pion.h"
#include"Reine.h"
#include"Roi.h"
#include"Tour.h"

using namespace std;

JoueurNoir::JoueurNoir() : Joueur(false) {
    _pieces[0] = make_shared<Roi>(Roi(4,8, false ));
    _pieces[1] = make_shared<Reine>(Reine(5,8, false ));
    _pieces[2] = make_shared<Fou>(Fou(6,8, false));
    _pieces[3] = make_shared<Fou>(Fou(3,8, false));
    _pieces[4] = make_shared<Tour>(Tour(1,8, false));
    _pieces[5] = make_shared<Tour>(Tour(8,8, false));
    _pieces[6] = make_shared<Cavalier>(Cavalier(2,8, false));
    _pieces[7] = make_shared<Cavalier>(Cavalier(7,8, false));

    for (int i = 1; i <= 8; i++) {
          _pieces[7+i] = make_shared<Pion>(Pion(i,7,false));
    }
}

JoueurNoir::~JoueurNoir() {
    std::cout << "Destructor Joueur noir ?" << std::endl;
}