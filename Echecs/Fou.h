#include "Piece.h"

#if !defined Fou_h
#define Fou_h
class Fou:public Piece{
    public: 
        Fou();
        Fou(int x, int y, bool white);

        ~Fou() = default;

        void affiche() const override;
        bool mouvementValide(const Echiquier &e, int x, int y) const override;
        char getChar() const override;

};

#endif