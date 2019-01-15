#include "Piece.h"

#if !defined joueur_h
#define joueur_h

#include <vector>
#include <iostream>
#include <memory>

#include "Echiquier.h"
#include "Cavalier.h"
#include "Fou.h"
#include "Pion.h"
#include "Reine.h"
#include "Roi.h"
#include "Tour.h"

const unsigned int NB_PIECES = 16;
const unsigned int NB_COLS = 8;

class Joueur
{
  protected:
    std::vector<std::shared_ptr<Piece>> _pieces;
    bool _white;

  public:
    Joueur(bool white);
    ~Joueur();
    void initEchiquier(Echiquier &echiquier);
    void affiche() const;
};

#endif