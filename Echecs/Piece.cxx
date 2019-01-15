/** 
 * Mise en oeuvre de Piece.h
 *
 * @file Piece.cxx
 */

// A besoin de la declaration de la classe
#include "Piece.h"
#include "Echiquier.h"
#include <iostream>
#include <string>

#include "Pion.h"
#include "Tour.h"
#include "Cavalier.h"
#include "Fou.h"
#include "Roi.h"
#include "Reine.h"

using namespace std;

Piece::Piece() {}

Piece::Piece(int x, int y, bool white)
  : m_x(x), m_y(y), m_white(white) {
  m_x = x;
  m_y = y;
  m_white = white;
}

Piece::~Piece() {}

void Piece::init( int x, int y, bool white ) {
  m_x = x;
  m_y = y;
  m_white = white;
}

void Piece::move( int x, int y ) {
  m_x = x;
  m_y = y;
}

int Piece::x() const {
  return m_x;
}

int Piece::y() const {
  return m_y;
}

bool Piece::isWhite() const {
  return m_white;
}

bool Piece::isBlack() const {
  return !m_white;
}

void Piece::affiche() const {
  cout << "Piece: x=" << m_x << " y=" << m_y << " "
       << ( m_white ? "blanche" : "noire" ) << endl;
}

char Piece::getChar() const {
  return 0;
}

const Piece& Piece::plusforte(const Piece & p) const {
  if (this < &p) {
    return *this;
  } else {
    return p;
  }
}

bool Piece::mouvementValide(const Echiquier& echiquier, int x, int y) const {
  return (echiquier.getPiece(x, y) == nullptr);
}
