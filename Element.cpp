#include "Element.h"

Element::Element(Position p) : position(p)
{
}

Element::~Element()
{
}


Position Element::getPosition() const
{
    return position;
}


void Element::setPosition(Position position)
{
    this->position = position;
}
