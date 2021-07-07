#include "BouleDeFeu.hpp"

using namespace std;

BouleDeFeu::BouleDeFeu(Position position) : Element(position), type(BDF)
{
}

ElemType BouleDeFeu::getType() const
{
    return BDF;
}
