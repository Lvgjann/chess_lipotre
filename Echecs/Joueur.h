#include "Piece.h"

#if !defined joueur_h
#define joueur_h

const unsigned int NB_PIECES=16;
const unsigned int NB_COLS=8;

#include "Piece.h"
#include "Echiquier.h"
#include <vector>
#include <memory>

class Joueur {
    protected:
        std::vector<std::shared_ptr<Piece>> _pieces;
        //Piece * _pieces [NB_PIECES];
        bool _white;
        
    public:
        Joueur(bool white);
        ~Joueur();
        void initEchiquier(Echiquier & echiquier);
        void affiche() const;
};

#endif