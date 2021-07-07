#ifndef __BDF__
#define __BDF__
#include "Element.h"
#include "Position.h"


class BouleDeFeu : public Element
{
private:
    ElemType type;
public:
    BouleDeFeu(Position);
    ElemType getType() const;

protected:

};

#endif // __BDF__
