#include "Piece.h"

#if !defined Pion_h
#define Pion_h

class Pion:public Piece{
    public: 
        Pion() = default;
        Pion(int x, int y, bool white);

        ~Pion() override = default;

        void affiche() const override;
        bool mouvementValide(const Echiquier & e, int x, int y) const override;
        char getChar() const override;
};

#endif