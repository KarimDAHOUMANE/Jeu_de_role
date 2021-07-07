#include "OBSTACLE.h"

Obstacle::Obstacle(Position position) : Element(position), type(OBSTACLE)
{

}

Obstacle::~Obstacle()
{
    //dtor
}

ElemType Obstacle::getType() const
{
    return OBSTACLE;
}
