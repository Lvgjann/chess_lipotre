#if !defined Roi_h
#define Roi_h
#include "Piece.h"

class Roi : public Piece {
    public: 
        Roi();
        Roi(int x, int y, bool white);

        ~Roi() override = default;

        void affiche() const override;
        bool mouvementValide(const Echiquier & e, int x, int y) const override;
        char getChar() const override;
};

#endif