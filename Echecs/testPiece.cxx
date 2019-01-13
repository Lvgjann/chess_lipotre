/** 
 * Programme test de Piece
 *
 * @file testPiece.cxx
 */

// Utile pour l'affichage
#include <iostream>
#include "Piece.h"
#include "Echiquier.h"
#include "JoueurBlanc.h"
#include "JoueurNoir.h"


// Pour utiliser les flux de iostream sans mettre "std::" tout le temps.
using namespace std;

void test2pieces(const Piece & p1, const Piece & p2){
  if (p1.x() == p2.x() && p1.y() == p2.y()){
    std::cout << "Les 2 pièces sont au même endroit" << std::endl;
  }
  else{
    std::cout << "Les 2 pièces ne sont pas au même endroit" << std::endl;
  }
}

/**
 * Programme principal
 */
int main( int argc, char** argv )
{
  // instancie un objet p1 de type Piece
  Piece p1;
  Piece p2(2, 7, false);
  // p1 est une piece blanche de coordonnees (3,3)
  p1.init( 3, 3, true );
  cout << "==================================" << endl;
  // On l'affiche
  p1.affiche();
  p2.affiche();
  cout << "==================================" << endl;

  Echiquier echiquier;

  // instancie des objet de type joueur
  JoueurBlanc *jb = new JoueurBlanc();
  JoueurNoir *jn = new JoueurNoir();

  jb->initEchiquier(echiquier);
  jn->initEchiquier(echiquier);

  //echiquier.placer(&p1);
  //echiquier.placer(&p2);
  echiquier.affiche();

  /*cout << "==================================" << endl;

  echiquier.deplacer(&p1, 8, 8);
  echiquier.affiche();
  /*cout << "Piece: x=" << p1.x() << " y=" << p1.y() << " "
       << ( p1.isWhite() ? "blanche" : "noire" ) << endl;
  cout << "Piece 2: x=" << p2.x() << " y=" << p2.y() << " "
       << ( p2.isWhite() ? "blanche" : "noire" ) << endl;*/
    
  //Piece tbl[4];


  /*jb.affiche();
  jn.affiche();*/  

  //cout << "==================================" << endl;

  //test2pieces(p1, p2);

  //cout << "==================================" << endl;

  //p2.plusforte(p1);

  //Piece *ptr = new Piece[5];
  //.
  //.
  //.
  //delete[] ptr pour détruire tout le tableau
  // les objets definis dans cette fonction sont automatiquement d�truits.
  // Ex : p1
  return 0;
}