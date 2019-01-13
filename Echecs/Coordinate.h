#if !defined Coordinate_h
#define Coordinate_h

#include <array>
#include "Piece.h"

class Coordinate{
    public:
        Coordinate():m_x(m_max),m_y(m_max) {}
        Coordinate(int x, int y):m_x(x),m_y(y){}
        int x() const {return m_x;}
        int y() const {return m_y;}
        bool isValid() const { return m_x<=m_max && m_y <=m_max;}
    private:
        static const int m_max = 8; int m_x; int m_y;
};

#endif