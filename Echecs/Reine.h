#include "Piece.h"

#if !defined Reine_h
#define Reine_h

class Reine:public Piece{
    public: 
        Reine();
        Reine(int x, int y, bool white);

        ~Reine() = default;

        void affiche() const override;
        bool mouvementValide(const Echiquier & e, int x, int y) const override;
        char getChar() const override;
};

#endif