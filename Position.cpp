#include "Position.h"

Position::Position(int x, int y)
{
    this->x = x;
    this->y = y;
}

Position::~Position()
{
}

int Position::getX() const
{
    return x;
}
int Position::getY() const
{
    return y;
}
void Position::setX(unsigned int x)
{
    this->x = x;
}
void Position::setY(unsigned int y)
{
    this->y = y;
}

bool Position::operator==(Position const& a)
{
    if (a.getX() == x && a.getY() == y)
        return true;
    else
        return false;
}
