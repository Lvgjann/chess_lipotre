#include "Piece.h"

#if !defined Tour_h
#define Tour_h

class Tour:public Piece{
    public: 
        Tour();
        Tour(int x, int y, bool white);

        ~Tour() = default;

        void affiche() const override;
        bool mouvementValide(const Echiquier & e, int x, int y) const override;
        char getChar() const override;
};

#endif