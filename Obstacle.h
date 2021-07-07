#ifndef OBSTACLE_H
#define OBSTACLE_H
#include "Element.h"

class Obstacle : public Element
{
private:
    ElemType type;
public:
    Obstacle(Position);
    virtual ~Obstacle();
    virtual ElemType getType() const;
protected:

};

#endif // OBSTACLE_H

