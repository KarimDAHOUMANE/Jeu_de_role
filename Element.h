#ifndef ELEMENT_H
#define ELEMENT_H
#include "Position.h"
#include <string>

enum Direction { HAUT,BAS,GAUCHE,DROITE };


enum ElemType
{
    OBSTACLE,GUERRIER,OBJETRAMASSABLE,
};

class Element
{
public:
    Element(Position);
    virtual ~Element();
    Position getPosition() const;
    void setPosition(Position position);
    virtual ElemType getType() const = 0;
protected:
private:
    Position position;
};

#endif // ELEMENT_H
