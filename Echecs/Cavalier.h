#include "Piece.h"

#if !defined Cavalier_h
#define Cavalier_h
class Cavalier : public Piece{
    public:
        Cavalier() = default;
        Cavalier(int x, int y, bool white);

        ~Cavalier() override = default;

        bool mouvementValide(const Echiquier &e, int x, int y) const override;
        void affiche() const override;
        char getChar() const override;
};
#endif
