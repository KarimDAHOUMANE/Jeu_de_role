#ifndef OBJETRAMASSABLE_H
#define OBJETRAMASSABLE_H
#include "Element.h"

class ObjetRamassable : public Element
{
private:
    int nbPtsVie;
    ElemType type;
public:
    ObjetRamassable(Position);
    ObjetRamassable(Position, int);
    virtual ~ObjetRamassable();
    int getNbPtsVie() const;
    virtual ElemType getType() const;
protected:

};

#endif // OBJETRAMASSABLE_H
