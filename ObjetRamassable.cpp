#include "OBJETRAMASSABLE.h"
#include "Position.h"

using namespace std;

ObjetRamassable::ObjetRamassable(Position position) : Element(position), nbPtsVie(10), type(OBJETRAMASSABLE)
{

}

ObjetRamassable::ObjetRamassable(Position position, int ptsVie) : Element(position), nbPtsVie(ptsVie), type(OBJETRAMASSABLE)
{

}

ObjetRamassable::~ObjetRamassable()
{
    //dtor
}

int ObjetRamassable::getNbPtsVie() const
{
    return nbPtsVie;
}


ElemType ObjetRamassable::getType() const
{
    return OBJETRAMASSABLE;
}
