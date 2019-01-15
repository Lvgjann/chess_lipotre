/** 
 * Header de Echiquier.cxx
 *
 * @file Echiquier.h
 */

#if !defined Echiquier_h
#define Echiquier_h

#include "Piece.h"
#include <array>
#include <memory>
#include <string>

/**
 * Declaration d'une classe mod�lisant une piece de jeu d'echec.
 */
const unsigned int NB_CASES_PER_ROW = 8;
const unsigned int NB_CASES = 64;

class Echiquier 
{
private:
  /**
   * Les cases de l'echiquier
   */
  std::array<std::shared_ptr<Piece>, NB_CASES> m_cases;
  
public:

  /**
   * Constructeur par d�faut.
   * Initialise � vide l'echiquier.
   */
  Echiquier();

  /**
   * Recupere la piece situee sur une case.
   *
   * @param x un entier entre 1 et 8
   * @param y un entier entre 1 et 8
   *
   * @return 0 si aucune piece n'est sur cette case et un pointeur
   * vers une piece sinon.
   */
  std::shared_ptr<Piece> getPiece( unsigned int x, unsigned int y );
  const std::shared_ptr<Piece> getPiece( unsigned int x, unsigned int y ) const;
  
  /**
   * Place une piece sur l'echiquier, aux coordonnees specifiees dans la piece.
   *
   * @param p un pointeur vers une piece
   *
   * @return 'true' si le placement s'est bien passe, 'false' sinon
   * (case occupee, coordonnees invalides, piece vide )
   */
  bool placer( std::shared_ptr<Piece> p );

  /**
   * Deplace une piece sur l'echiquier, des coordonnees specifiees
   * dans la piece aux coordonnees x,y. 
   *
   * @param p un pointeur vers une piece
   * @param x un entier entre 1 et 8
   * @param y un entier entre 1 et 8
   *
   * @return 'true' si le placement s'est bien passe, 'false' sinon
   * (case occupee, coordonnees invalides, piece vide, piece pas
   * presente au bon endroit sur l'echiquier)
   */
  bool deplacer( std::shared_ptr<Piece>& p, int x, int y );

  /**
   * Enleve la piece situee sur une case (qui devient vide).
   *
   * @param x un entier entre 1 et 8
   * @param y un entier entre 1 et 8
   *
   * @return 0 si aucune piece n'est sur cette case et le pointeur
   * vers la piece enlevee sinon.
   */
  std::shared_ptr<Piece> enleverPiece( int x, int y );

  /**
   * Affiche l'echiquier avec des # pour les cases noires et . pour
   * les blanches si elles sont vides, et avec B pour les pieces
   * blanches et N pour les pieces noires.
   */
  void affiche();

  bool positionValide(int x, int y) const { 
    return (x>=1 && x <= NB_CASES_PER_ROW && y>=1 && y <= NB_CASES_PER_ROW);
  }
  
};

#endif // !defined Echiquier_h

