#include "Guerrier.h"



Guerrier::Guerrier(Position position, string nom, Equipe equipe) : Element(position), ptsVie(100), nom(nom), equipe(equipe), capAttack(20), capDefense(5), type(GUERRIER)
{

}

Guerrier::~Guerrier()
{
    //dtor
}

int Guerrier::getVie()
{
    return ptsVie;
}

void Guerrier::setVie(int ptsVie)
{
    this->ptsVie = ptsVie;
}


Equipe Guerrier::getEquipe() const
{
    return equipe;
}


string Guerrier::getNom() const
{
    return nom;
}

int Guerrier::getCapAttack() const
{
    return capAttack;
}

void Guerrier::setCapAttack(int capAttack)
{
    this->capAttack = capAttack;
}

int Guerrier::getCapDefense() const
{
    return capDefense;
}

void Guerrier::setCapDefense(int capDefense)
{
    this->capDefense = capDefense;
}

void Guerrier::attack(Guerrier& guerrier)
{
    if (guerrier.getEquipe() != equipe)
    {
        guerrier.setVie(guerrier.getVie() - capAttack);
    }
}


ElemType Guerrier::getType() const
{
    return GUERRIER;
}


bool Guerrier::estAdversaire(Guerrier g)
{
    if (g.getEquipe() != equipe)
    {
        return true;
    }
    else
    {
        return false;
    }
}
