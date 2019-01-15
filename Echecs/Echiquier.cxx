/** 
 * Mise en oeuvre de Echiquier.h
 *
 * @file Echiquier.cxx
 */

#include <iostream>
#include <assert.h>
// A besoin de la declaration de la classe
#include "Echiquier.h"
#include <memory>

using namespace std;

/**
 * Constructeur par d�faut.
 * Initialise � vide l'echiquier.
 */
Echiquier::Echiquier()
{
	for (auto &p : m_cases)
		p = nullptr;
}

/**
 * Recupere la piece situee sur une case.
 *
 * @param x un entier entre 1 et 8
 * @param y un entier entre 1 et 8
 *
 * @return nullptr si aucune piece n'est sur cette case et un pointeur
 * vers une piece sinon.
 */
std::shared_ptr<Piece> Echiquier::getPiece(unsigned int x, unsigned int y)
{
	assert(x >= 1 && x <= NB_CASES_PER_ROW);
	assert(y >= 1 && y <= NB_CASES_PER_ROW);
	return m_cases[NB_CASES_PER_ROW * (y - 1) + (x - 1)];
}
const std::shared_ptr<Piece> Echiquier::getPiece(unsigned int x, unsigned int y) const
{
	assert(x >= 1 && x <= NB_CASES_PER_ROW);
	assert(y >= 1 && y <= NB_CASES_PER_ROW);
	return m_cases[NB_CASES_PER_ROW * (y - 1) + (x - 1)];
}

/**
 * Place une piece sur l'echiquier, aux coordonnees specifiees dans la piece.
 *
 * @param p un pointeur vers une piece
 *
 * @return 'true' si le placement s'est bien passe, 'false' sinon
 * (case occupee, coordonnees invalides, piece vide )
 */
bool Echiquier::placer(std::shared_ptr<Piece> p)
{
	if (p == nullptr)
	{
		return false;
	}
	unsigned int x = p->x();
	unsigned int y = p->y();
	if (x <= 0 || x > 8 || y <= 0 || y > 8)
	{
		return false;
	}
	unsigned int ind = NB_CASES_PER_ROW * (y - 1) + (x - 1);
	if (m_cases[ind] != nullptr)
	{
		if (p->isWhite())
		{
			if (m_cases[ind]->isWhite())
			{
				return false;
			}
			else
			{
				(enleverPiece(x, y));
			}
		}
		else
		{
			if (m_cases[ind]->isBlack())
			{
				return false;
			}
			else
			{
				enleverPiece(x, y);
			}
		}
	}

	m_cases[ind] = p;
	return true;
}

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
bool Echiquier::deplacer(std::shared_ptr<Piece> &p, int x, int y)
{
	if (nullptr == p)
		return false;
	unsigned int xp = p->x();
	unsigned int yp = p->y();
	unsigned int ind = NB_CASES_PER_ROW * (yp - 1) + (xp - 1);
	if (xp <= 0 || xp > 8 || yp <= 0 || yp > 8)
	{
		return false;
	}
	if (x <= 0 || x > 8 || y <= 0 || y > 8)
	{
		return false;
	}
	if (!p->mouvementValide(*this, x, y))
	{
		return false;
	}

	m_cases[ind] = nullptr;
	p->move(x, y);
	return placer(p);
}

/**
 * Enleve la piece situee sur une case (qui devient vide).
 *
 * @param x un entier entre 1 et 8
 * @param y un entier entre 1 et 8
 *
 * @return nullptr si aucune piece n'est sur cette case et le pointeur
 * vers la piece enlevee sinon.
 */
std::shared_ptr<Piece> Echiquier::enleverPiece(int x, int y)
{
	std::shared_ptr<Piece> p = getPiece(x, y);
	unsigned int ind = NB_CASES_PER_ROW * (y - 1) + (x - 1);
	m_cases[ind] = nullptr;
	return p;
}

/**
 * Affiche l'echiquier avec des # pour les cases noires et . pour
 * les blanches si elles sont vides, et avec B pour les pieces
 * blanches et N pour les pieces noires.
 */
void Echiquier::affiche()
{
	cout << endl
		 << "   1 2 3 4 5 6 7 8" << endl
		 << "   ===============" << endl;
	for (int y = 1; y <= 8; ++y)
	{
		cout << y << "| ";
		for (int x = 1; x <= 8; ++x)
		{
			char c;
			std::shared_ptr<Piece> p = getPiece(x, y);
			if (p == nullptr)
				c = ((x + y) % 2) == 0 ? '#' : '.';
			else
				c = p->getChar();
			cout << c << " ";
		}
		cout << "|" << y << endl;
	}
	cout << "   ===============" << endl
		 << "   1 2 3 4 5 6 7 8" << endl;
}
