/** 
 * Header de Piece.cxx
 *
 * @file Piece.h
 */

#if !defined Piece_h
#define Piece_h

#include <iostream>
#include "Coordinate.h"

class Echiquier;
/**
 * Declaration d'une classe mod�lisant une piece de jeu d'echec.
 */
class Piece 
{
protected:
  int m_x;
  int m_y;
  bool m_white;
  
public:
  Piece();
  Piece(int x, int y, bool white);
  //Piece(const Piece& autre) = delete;
  virtual ~Piece();
  void init( int x, int y, bool white );
  void move( int x, int y );
  int x() const;
  int y() const;
  bool isWhite() const;
  bool isBlack() const;
  virtual void affiche() const;
  virtual char getChar() const;
  const Piece& plusforte(const Piece & p) const;
  virtual bool mouvementValide(const Echiquier& echiquier, int x, int y) const;
}; 

#endif // !defined Piece_h
